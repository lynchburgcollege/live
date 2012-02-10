<?php
/**
 * @file
 * course_1_1.features.inc
 */

/**
 * Implements hook_node_info().
 */
function course_1_1_node_info() {
  $items = array(
    'course' => array(
      'name' => t('Course'),
      'base' => 'node_content',
      'description' => t('Single course listing'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
