<?php
/**
 * @file
 * lc_styles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function lc_styles_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "stylizer" && $api == "stylizer") {
    return array("version" => "1");
  }
}
