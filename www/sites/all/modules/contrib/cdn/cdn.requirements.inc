<?php
// $Id: cdn.requirements.inc,v 1.13.2.2 2011/01/04 18:57:14 wimleers Exp $

/**
 * @file
 * Functionality to automatically detect if a patch has been applied.
 */


/**
 * Generates a requirement for the given patch.
 */
function _cdn_requirements_generate_requirement_for_patch(&$requirements, $patch_name, $title, $not_properly_applied_severity = REQUIREMENT_ERROR) {
  $t = get_t();

  $patterns_function = '_cdn_requirements_' . $patch_name . '_patch_patterns';
  $patterns = $patterns_function();

  // No patterns means the patch file could not be found.
  if ($patterns !== FALSE) {
    $unpatched_files = _cdn_requirements_check_patch_applied($patterns);
  }

  $key = 'cdn_' . $patch_name . '_patch';

  $requirements[$key]['title'] = $title;
  if ($patterns === FALSE) {
    $requirements[$key] += array(
      'description' => $t('This patch file has been moved or deleted by the administrator. Please restore it, so we can verify that the patch has been properly applied.'),
      'severity'    => REQUIREMENT_ERROR,
      'value'       => $t('Unable to check'),
    );
  }
  elseif (count($unpatched_files) == 0) {
    $requirements[$key] += array(
      'severity'    => REQUIREMENT_OK,
      'value'       => $t('Applied'),
    );
  }
  else {
    $requirements[$key] += array(
      'description' => $t('This patch has not been properly applied to the following files (or the patch has been updated):') . '<br />' . theme('item_list', array('items' => $unpatched_files)) . '<br />' . t('Please consult the installation instructions in the included README.txt.'),
      'severity'    => $not_properly_applied_severity,
      'value'       => $t('Not/incompletely applied patch or updated patch.'),
    );
  }
}

/**
 * Check if a patch has been applied, given a set of patterns.
 */
function _cdn_requirements_check_patch_applied($patterns) {
  $drupal_root = realpath('.');
  $patched = TRUE;
  $unpatched_files = array();
  foreach ($patterns as $kind => $details) {
    foreach ($details as $file_info => $patterns) {
      foreach ($patterns as $pattern) {
        if ($kind == 'core') {
          $filename = $file_info;
          $full_path = $drupal_root . '/' . $filename;
        }
        else {
          list($name, $filename) = explode('|', $file_info);
          $full_path = $drupal_root . '/' . drupal_get_path($kind, $name) . '/' . $filename;
        }

        if ($full_path) {
          $match = preg_match('|' . preg_quote($pattern) . '|m', file_get_contents($full_path));
          // If it didn't match, try allowing \r\n line endings and see if it
          // it then matches. This is of course also qualifies as a correctly
          // applied patch.
          if (!$match) {
            $match = preg_match('|' . preg_quote($pattern) . '|m', str_replace("\n", "\r\n", file_get_contents($full_path)));
          }
          $patched = $patched && $match;

          // Remember unpatched files.
          if (!$match && !in_array($full_path, $unpatched_files)) {
            $unpatched_files[] = $full_path;
          }
        }
      }
    }
  }
  return $unpatched_files;
}

/**
 * Generate patterns for a patch, given the full path to a patch. This
 * effectively parses the patch and stores it in a meaningful structure.
 */
function _cdn_requirements_generate_patterns_for_patch($full_path) {
  // The patch file must exist, otherwise we can't generate any patterns.
  if (!file_exists($full_path)) {
    return FALSE;
  }

  $file_kinds = array(
    '/cvs/drupal/drupal/modules'                => 'core',
    '/cvs/drupal/drupal/themes'                 => 'core',
    '/cvs/drupal/drupal'                        => 'core',
    '/cvs/drupal-contrib/contributions/modules' => 'module',
    '/cvs/drupal-contrib/contributions/themes'  => 'theme',
  );


  $fp = fopen($full_path, 'r');
  $patch_block = '';
  while (!feof($fp) ) {
    $line = fgets($fp);

    // Check if the current line indicates the next file.
    if (drupal_substr($line, 0, 7) == 'Index: ') {
      $file_to_patch = drupal_substr($line, 7, drupal_strlen($line) - 7 - 1);
    }

    // Find out which kind of file this is: a core file, a module file or a
    // theme file.
    if (drupal_substr($line, 0, 10) == 'RCS file: ') {
      $rcs_file = drupal_substr($line, 10);
      foreach ($file_kinds as $patch_rcs_file => $patch_type) {
        if (drupal_substr($rcs_file, 0, drupal_strlen($patch_rcs_file)) == $patch_rcs_file) {
          $kind = $patch_type;
          // For files of the module or theme kind, also store the exact name.
          if ($kind == 'module' || $kind == 'theme') {
            $start = drupal_strlen($patch_rcs_file) + 1;
            $module_or_theme = drupal_substr($rcs_file, $start, strpos($rcs_file, '/', $start) - $start);
          }
          break;
        }
      }
    }

    // Finally, store the lines that have been added (+): concatenate them in
    // a "patch block".
    if ($line[0] == '+' && ($line[1] == ' ' | $line[1] == "\n")) {
      $patch_block .= drupal_substr($line, 1);
    }
    // When we encounter a line that has not been added (+), the current patch
    // block has ended and we should store it as a pattern.
    else {
      if ($patch_block != '') {
        if ($kind == 'core') {
          $patterns[$patch_type][$file_to_patch][] = $patch_block;
        }
        else {
          $patterns[$patch_type][$module_or_theme . '|' . $file_to_patch][] = $patch_block;
        }
      }
      $patch_block = '';
    }
  }
  fclose($fp);

  return $patterns;
}
