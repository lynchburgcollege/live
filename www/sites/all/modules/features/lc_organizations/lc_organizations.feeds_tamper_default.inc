<?php
/**
 * @file
 * lc_organizations.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function lc_organizations_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'lc_organizations-blank_source_1-rewrite';
  $feeds_tamper->importer = 'lc_organizations';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[jsonpath_parser:2] on [jsonpath_parser:3] at [jsonpath_parser:4][jsonpath_parser:5]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['lc_organizations-blank_source_1-rewrite'] = $feeds_tamper;

  return $export;
}
