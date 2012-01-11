<?php
/**
 * @file
 * lc_importer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function lc_importer_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
