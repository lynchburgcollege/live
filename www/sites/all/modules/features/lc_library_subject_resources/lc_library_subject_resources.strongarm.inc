<?php
/**
 * @file
 * lc_library_subject_resources.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function lc_library_subject_resources_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_library_subject_resources';
  $strongarm->value = 0;
  $export['comment_anonymous_library_subject_resources'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_library_subject_resources';
  $strongarm->value = 1;
  $export['comment_default_mode_library_subject_resources'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_library_subject_resources';
  $strongarm->value = '50';
  $export['comment_default_per_page_library_subject_resources'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_library_subject_resources';
  $strongarm->value = 1;
  $export['comment_form_location_library_subject_resources'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_library_subject_resources';
  $strongarm->value = '2';
  $export['comment_library_subject_resources'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_library_subject_resources';
  $strongarm->value = '1';
  $export['comment_preview_library_subject_resources'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_library_subject_resources';
  $strongarm->value = 1;
  $export['comment_subject_field_library_subject_resources'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_library_subject_resources';
  $strongarm->value = array(
    0 => 'menu-about-us',
    1 => 'menu-academic-divisions',
    2 => 'menu-academics',
    3 => 'menu-activities',
    4 => 'menu-admission',
    5 => 'menu-campus-life',
    6 => 'menu-centers',
    7 => 'devel',
    8 => 'menu-financial-aid',
    9 => 'menu-footer-bar-left',
    10 => 'menu-footer-bar-right',
    11 => 'menu-graduate-programs',
    12 => 'main-menu',
    13 => 'management',
    14 => 'navigation',
    15 => 'menu-student-services',
    16 => 'user-menu',
  );
  $export['menu_options_library_subject_resources'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_library_subject_resources';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_library_subject_resources'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_library_subject_resources';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_library_subject_resources'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_library_subject_resources';
  $strongarm->value = '1';
  $export['node_preview_library_subject_resources'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_library_subject_resources';
  $strongarm->value = 1;
  $export['node_submitted_library_subject_resources'] = $strongarm;

  return $export;
}