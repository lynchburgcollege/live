<?php
/**
 * @file
 * Provides the LC News search pane
 */

$plugin = array(
  'title' => t('Search News'),
  'description' => t('Search News by Keyword'),
  'single' => TRUE,
  'content_types' => array('lc_calendar_search_news_pane'),
  'render callback' => 'search_news_content_type_render',
  'defaults' => array(),
  'edit form' => 'search_news_content_type_edit_form',
  'category' => array(t('LC'), -9),
);

/**
 * Run-time rendering of the body of the block.
 *
 * @param $subtype
 * @param $conf
 *   Configuration as done at admin time.
 * @param $args
 * @param $context
 *   Context - in this case we don't have any.
 *
 * @return
 *   An object with at least title and content members.
 */
function search_news_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  $block->title = check_plain("Search News");

  $block->content = drupal_get_form('lc_news_search_news_form');
  return $block;
}

/**
 * 'Edit form' callback for the content type.
 */
function search_news_content_type_edit_form($form, &$form_state) {
  return $form;
}

