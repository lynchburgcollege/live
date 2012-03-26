<?php
/**
 * @file
 * Provides the LC Event search pane
 */

$plugin = array(
  'title' => t('Events Header'),
  'description' => t('Display events header with month pager, etc.'),
  'single' => TRUE,
  'content_types' => array('lc_calendar_events_header_pane'),
  'render callback' => 'events_header_content_type_render',
  'defaults' => array(),
  'edit form' => 'events_header_content_type_edit_form',
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
function events_header_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  $arguments = explode('/', $_GET['q']);
  $active_search_terms = '';
  if (isset($arguments[1])) {
    $active_date = $arguments[1];
  }
  $date = date_parse($active_date);
  $current_month = $date['month'];
  $current_year = $date['year'];

  // Get previous month dates + name.
  $prev_year = $current_month > 1 ? $current_year : $current_year - 1;
  $prev_month = $current_month == 1 ? 12 : $current_month - 1;
  $prev = $prev_year . '-' . $prev_month;
  $prev_month_name = date('F', strtotime($prev));

  // Get next month dates + name.
  $next_year = $current_month < 12 ? $current_year : $current_year + 1;
  $next_month = $current_month == 12 ? 1 : $current_month + 1;
  $next = $next_year . '-' . $next_month;
  $next_month_name = date('F', strtotime($next));

  // Get default date string.
  $default_date = date('Y-m-d--') . (date('Y-m-d', strtotime("+1 month")));

  $block->title = check_plain("Events");

  $block->content = l('< ' . $prev_month_name, 'events/' . $prev, array('attributes' => array ('class' => array('lc-calendar-previous-link'))));
  // Output current link if we're not already there.
  if ($active_date != $default_date) {
    $block->content .= l('Current', 'events/' . $default_date, array('attributes' => array ('class' => array('lc-calendar-current-link'))));
  }
  $block->content .= l($next_month_name . ' >',  'events/' . $next, array('attributes' => array ('class' => array('lc-calendar-next-link'))));
  return $block;
}

/**
 * 'Edit form' callback for the content type.
 */
function events_header_content_type_edit_form($form, &$form_state) {
  return $form;
}

