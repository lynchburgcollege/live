<?php
/**
 * @file
 * lc_calendar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function lc_calendar_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function lc_calendar_flag_default_flags() {
  $flags = array();
  // Exported flag: "Feature".
  $flags['featured_event'] = array(
    'content_type' => 'node',
    'title' => 'Feature',
    'global' => '1',
    'types' => array(
      0 => 'event',
    ),
    'flag_short' => 'Feature this event',
    'flag_long' => 'Display this event on the list of featured events',
    'flag_message' => 'This event is now featured!',
    'unflag_short' => 'Un-feature this event',
    'unflag_long' => 'Remove this event from the list of featured events',
    'unflag_message' => 'This event is no longer featured!',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '3',
      ),
      'unflag' => array(
        0 => '3',
      ),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'lc_calendar',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;
}

/**
 * Implements hook_node_info().
 */
function lc_calendar_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
