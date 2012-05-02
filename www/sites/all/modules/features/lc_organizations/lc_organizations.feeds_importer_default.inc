<?php
/**
 * @file
 * lc_organizations.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function lc_organizations_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'lc_organizations';
  $feeds_importer->config = array(
    'name' => 'Lynchburg Organizations',
    'description' => 'Imports lynchburg clubs & orgs',
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
          'jsonpath_parser:0' => 'OrgName',
          'jsonpath_parser:1' => 'OrgName',
          'jsonpath_parser:2' => 'MeetingFreq',
          'jsonpath_parser:3' => 'MeetingDay',
          'jsonpath_parser:4' => 'MeetingTime',
          'jsonpath_parser:5' => 'MeetingAMPM',
          'jsonpath_parser:6' => 'OrgDescription',
          'jsonpath_parser:7' => 'MeetingPlace',
          'jsonpath_parser:8' => 'PresName',
          'jsonpath_parser:9' => 'OrgType',
        ),
        'debug' => array(
          'options' => array(
            'context' => 0,
            'jsonpath_parser:0' => 0,
            'jsonpath_parser:1' => 0,
            'jsonpath_parser:2' => 0,
            'jsonpath_parser:3' => 0,
            'jsonpath_parser:4' => 0,
            'jsonpath_parser:5' => 0,
            'jsonpath_parser:6' => 0,
            'jsonpath_parser:7' => 0,
            'jsonpath_parser:8' => 0,
            'jsonpath_parser:9' => 0,
          ),
        ),
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'organization',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'jsonpath_parser:0',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'jsonpath_parser:1',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'jsonpath_parser:2',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'jsonpath_parser:3',
            'target' => 'Temporary target 2',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'jsonpath_parser:4',
            'target' => 'Temporary target 3',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'jsonpath_parser:5',
            'target' => 'Temporary target 4',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'jsonpath_parser:6',
            'target' => 'body',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'jsonpath_parser:7',
            'target' => 'field_meeting_location',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'jsonpath_parser:8',
            'target' => 'field_organization_contact',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Blank source 1',
            'target' => 'field_meeting_time',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'jsonpath_parser:9',
            'target' => 'field_organization_type',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '86400',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['lc_organizations'] = $feeds_importer;

  return $export;
}
