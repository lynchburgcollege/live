<?php
/**
 * @file
 * lc_library_subject_resources.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function lc_library_subject_resources_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'library_subject_resources';
  $formatter->label = 'Library Subject Resources';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'field_collection';
  $formatter->code = '$text = \'\';
$options = array();
$icon_path = drupal_get_path(\'module\', \'lc_library_subject_resources\') . \'/images/info.png\';

foreach (array_values($variables[\'#items\']) as $item) {
  $id = $item[\'value\'];
  // Load the field collection item.
  $field = field_collection_item_load($id);
  $text .= l($field->field_resource_link[\'und\'][0][\'title\'], $field->field_resource_link[\'und\'][0][\'url\']);
  $text .= \'<img id="bt_library_resource_info_\' . $id . \'" src="/\' . $icon_path . \'" >\';
  $text .= \'<br />\';

  $options[\'bt_library_resource_\' . $id] = array(
    \'cssSelect\' => \'#bt_library_resource_info_\' . $id,
    \'text\' => $field->field_resource_description[\'und\'][0][\'safe_value\'],
    \'trigger\' => array(\'mouseover\', \'click\'),
  );
}

beautytips_add_beautytips($options);

return $text;';
  $export['library_subject_resources'] = $formatter;

  return $export;
}
