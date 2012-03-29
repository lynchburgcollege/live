<?php
/**
 * @file
 * Provides the LC Flickrset embed.
 */

$plugin = array(
  'title' => t('Flickr Set'),
  'description' => t('Embed Flickr photoset'),
  'single' => TRUE,
  'content_types' => array('lc_flickrset_flickrset_embed'),
  'render callback' => 'flickrset_embed_content_type_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(),
  'edit form' => 'flickrset_embed_content_type_edit_form',
  'category' => array(t('LC'), -9),
);

/**
 * Run-time rendering of the body of the block.
 *
 * @param $subtype
 * @param $conf
 *   Configuration as done at admin time.
 * @param $args
 * @param $context
 *   Context - in this case we don't have any.
 *
 * @return
 *   An object with at least title and content members.
 */
function flickrset_embed_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context) || empty($context->data->field_flickrsetid[$context->data->language][0]['safe_value'])) {
    return;
  }
  $fsid = $context->data->field_flickrsetid[$context->data->language][0]['safe_value'];
  // $fuid = variable_get('lc_flickrset_uid', '25910205@N03');

  $block = new stdClass();

  $block->title = check_plain("Flickr Set");

  $block->content = '<iframe align="center" src="http://www.flickr.com/slideShow/index.gne?' .
    'set_id=' . $fsid . '" frameBorder="0" "width=500" height="300" scrolling="no"></iframe>';
  return $block;
}

/**
 * 'Edit form' callback for the content type.
 */
function flickrset_embed_content_type_edit_form($form, &$form_state) {
  return $form;
}

