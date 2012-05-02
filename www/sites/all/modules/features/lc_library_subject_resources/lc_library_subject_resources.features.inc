<?php
/**
 * @file
 * lc_library_subject_resources.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function lc_library_subject_resources_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function lc_library_subject_resources_node_info() {
  $items = array(
    'library_subject_resources' => array(
      'name' => t('Library Subject Resources'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
