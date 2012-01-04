<?php

/**
 * @file
 * Handles toggling of options.
 */

/**
 * Menu callback. Toggle options for a node if the action is confirmed via
 * POST. Otherwise, display a confirmation form.
 */
function fasttoggle_node_option($node, $option) {
  $options = fasttoggle_get_options('node', $node);

  // Check if the action is valid. This is essential to ensure the user has
  // access to the action.
  if (isset($options[$option]) && isset($_GET['token']) && drupal_valid_token($_GET['token'], $option . '_' . $node->nid, TRUE)) {
    // The action is confirmed: either via form submit or via AJAX/POST
    if ((isset($_POST['confirm']) && $_POST['confirm']) || (isset($_POST['js']) && $_POST['js'])) {
      // Get the next ID.
      while (key($options[$option]) != $node->$option) next($options[$option]);
      if (next($options[$option]) === FALSE) reset($options[$option]);

      // Save the node.
      $oldClass = 'fasttoggle-status-node-' . $node->nid . '-' . $option . '-' . $node->$option;
      $node->$option = key($options[$option]);
      $newClass = 'fasttoggle-status-node-' . $node->nid . '-' . $option . '-' . $node->$option;
      node_save($node);

      // Let other modules respond.
      module_invoke_all('fasttoggle_toggle', 'node', $node, $option);

      // Output the new status for the updated link text on AJAX changes
      if (isset($_POST['js']) && $_POST['js']) {
        drupal_add_http_header('Content-Type', 'text/javascript; charset=utf-8');
        $path = request_path();
        echo ajax_render(array(
          ajax_command_replace('.' . $oldClass, fasttoggle($options[$option][intval($node->$option)], $path, FASTTOGGLE_FORMAT_HTML, $option . '_' . $node->nid, $newClass)),
        ));
        exit;
      }
      else {
        drupal_goto();
      }
    }
    else {
      // The action is not confirmed. The user came here through a regular link;
      // no AJAX was involved. That means, we need a confirmation form so that
      // we get a POST form.
      $labels = _fasttoggle_get_label('node_' . $option, FASTTOGGLE_LABEL_STATUS);
      return drupal_get_form('fasttoggle_node_option_confirm', $node, $labels[intval(!$node->$option)]);
    }
  }
  else {
    return MENU_NOT_FOUND;
  }
}


/**
 * Confirmation form for the option change of a node.
 */
function fasttoggle_node_option_confirm($form, $form_state, $node, $option) {
  return confirm_form(array(),
    t('Are you sure you want to set the post %title to %option?', array('%title' => $node->title, '%option' => $option)),
    $_GET['destination'] ? $_GET['destination'] : 'node/' . $node->nid,
    '',
    t('Change'), t('Cancel')
  );
}


/**
 * Menu callback. Toggle the status of a user if the action is confirmed via
 * POST. Otherwise, display a confirmation form.
 */
function fasttoggle_user_option($user, $option) {
  $options = fasttoggle_get_options('user', $user);

  // Check if the action is valid. This is essential to ensure the user has
  // access to the action.
  if (isset($options[$option]) && isset($_GET['token']) && drupal_valid_token($_GET['token'], $option . '_' . $user->uid, TRUE)) {
    if ((isset($_POST['confirm']) && $_POST['confirm']) || (isset($_POST['js']) && $_POST['js'])) {
      $oldClass = 'fasttoggle-status-user-' . $user->uid . '-' . $option . '-' . $user->$option;
      $array = array($option => !$user->$option);
      $newClass = 'fasttoggle-status-user-' . $user->uid . '-' . $option . '-' . (1 - $user->$option);
      $user = user_save($user, $array);

      // Let other modules respond.
      module_invoke_all('fasttoggle_toggle', 'user', $user, $option);

      // Output the new option for the updated link text on AJAX changes
      if (isset($_POST['js']) && $_POST['js']) {
        drupal_add_http_header('Content-Type', 'text/javascript; charset=utf-8');
        $path = request_path();
        echo ajax_render(array(
          ajax_command_replace('.' . $oldClass, fasttoggle($options[$option][intval($user->$option)], $path, FASTTOGGLE_FORMAT_HTML, $option . '_' . $user->uid, $newClass)),
        ));
        exit;
      }
      else {
        drupal_goto();
      }
    }
    else {
      // The action is not confirmed. The user came here through a regular link;
      // no AJAX was involved. That means, we need a confirmation form so that
      // we get a POST form.
      $labels = _fasttoggle_get_label('user_' . $option, FASTTOGGLE_LABEL_STATUS);
      return drupal_get_form('fasttoggle_user_option_confirm', $user, $labels[intval(!$user->$option)]);
    }
  }
  else {
    return MENU_NOT_FOUND;
  }
}


/**
 * Confirmation form for the status change of a user.
 */
function fasttoggle_user_option_confirm($form, $form_state, $user, $option) {
  return confirm_form(array(),
    t('Are you sure you want to set the user %user to %option?', array('%user' => $user->name, '%option' => $option)),
    $_GET['destination'] ? $_GET['destination'] : 'user/' . $user->uid,
    '',
    t('Change'), t('Cancel')
  );
}


/**
 * Menu callback. Toggle options for a comment if the action is confirmed via
 * POST. Otherwise, display a confirmation form.
 */
function fasttoggle_comment_option($comment, $option) {
  $options = fasttoggle_get_options('comment', $comment);

  // Check if the action is valid. This is essential to ensure the user has
  // access to the action.
  if (isset($options[$option]) && isset($_GET['token']) && drupal_valid_token($_GET['token'], $option . '_' . $comment->cid, TRUE)) {
    // The action is confirmed: either via form submit or via AJAX/POST
    if ((isset($_POST['confirm']) && $_POST['confirm']) || (isset($_POST['js']) && $_POST['js'])) {
      $oldClass = 'fasttoggle-status-comment-' . $comment->cid . '-' . $option . '-' . intval($comment->$option);
      $comment->$option = intval(!$comment->$option);
      $newClass = 'fasttoggle-status-comment-' . $comment->cid . '-' . $option . '-' . intval($comment->$option);
      comment_save($comment);

      // Let other modules respond.
      module_invoke_all('fasttoggle_toggle', 'comment', $comment, $option);

      // Output the new status for the updated link text on AJAX changes
      if (isset($_POST['js']) && $_POST['js']) {
        drupal_add_http_header('Content-Type', 'text/javascript; charset=utf-8');
        $path = request_path();
        echo ajax_render(array(
          ajax_command_replace('.' . $oldClass, fasttoggle($options[$option][intval($comment->$option)], $path, FASTTOGGLE_FORMAT_HTML, $option . '_' . $comment->cid, $newClass)),
        ));
        exit;
      }
      else {
        drupal_goto();
      }
    }
    else {
      // The action is not confirmed. The user came here through a regular link;
      // no AJAX was involved. That means, we need a confirmation form so that
      // we get a POST form.
      $labels = _fasttoggle_get_label('comment_' . $option, FASTTOGGLE_LABEL_STATUS);
      return drupal_get_form('fasttoggle_comment_option_confirm', $comment, $labels[intval(!$comment->$option)]);
    }
  }
  else {
    return MENU_NOT_FOUND;
  }
}


/**
 * Confirmation form for the option change of a comment.
 */
function fasttoggle_comment_option_confirm($form, $form_state, $comment, $option) {
  return confirm_form(array(),
    t('Are you sure you want to set the comment %title to %option?', array('%title' => $comment->subject, '%option' => $option)),
    $_GET['destination'] ? $_GET['destination'] : 'comment/' . $comment->cid,
    '',
    t('Change'), t('Cancel')
  );
}
