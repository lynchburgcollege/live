<?php
/**
 * @file
 * tour_location.features.inc
 */

/**
 * Implements hook_node_info().
 */
function tour_location_node_info() {
  $items = array(
    'tour' => array(
      'name' => t('Tour'),
      'base' => 'node_content',
      'description' => t('Virtual Tour location'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
