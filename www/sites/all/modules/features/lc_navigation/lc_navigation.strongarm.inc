<?php
/**
 * @file
 * lc_navigation.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function lc_navigation_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_site_structure_pattern';
  $strongarm->value = '[term:vocabulary]/[term:parents:join-path]/[term:name]';
  $export['pathauto_taxonomy_term_site_structure_pattern'] = $strongarm;

  return $export;
}
