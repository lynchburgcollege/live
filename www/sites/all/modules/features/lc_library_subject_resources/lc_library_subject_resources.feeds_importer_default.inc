<?php
/**
 * @file
 * lc_library_subject_resources.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function lc_library_subject_resources_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'lc_library_resources';
  $feeds_importer->config = array(
    'name' => 'Library Electronic Resources',
    'description' => 'Imports library resources by subject.',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsJSONPathParser',
      'config' => array(
        'context' => '$.Records.*',
        'sources' => array(
          'jsonpath_parser:0' => 'Subject',
          'jsonpath_parser:1' => 'Subject',
          'jsonpath_parser:4' => 'RecommendedSites',
          'jsonpath_parser:5' => 'URL',
          'jsonpath_parser:6' => 'Resource',
          'jsonpath_parser:7' => 'Description',
        ),
        'debug' => array(
          'options' => array(
            'context' => 0,
            'jsonpath_parser:0' => 0,
            'jsonpath_parser:1' => 0,
            'jsonpath_parser:4' => 0,
            'jsonpath_parser:5' => 0,
            'jsonpath_parser:6' => 0,
            'jsonpath_parser:7' => 0,
          ),
        ),
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'library_subject_resources',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'jsonpath_parser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'jsonpath_parser:1',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'jsonpath_parser:4',
            'target' => 'body',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'jsonpath_parser:5',
            'target' => 'field_subject_resources:field_resource_link:url',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'jsonpath_parser:6',
            'target' => 'field_subject_resources:field_resource_link:title',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'jsonpath_parser:7',
            'target' => 'field_subject_resources:field_resource_description',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'filtered',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['lc_library_resources'] = $feeds_importer;

  return $export;
}
