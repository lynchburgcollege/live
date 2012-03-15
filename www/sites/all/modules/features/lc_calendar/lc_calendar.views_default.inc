<?php
/**
 * @file
 * lc_calendar.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function lc_calendar_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'lc_events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'LC Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = 'field_date';
  $handler->display->display_options['style_options']['group_rendered'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: When */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Event date';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'lc_event_calendar_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_date']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: When */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_date_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_date_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_date_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_date_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_date_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_date_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_date_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_date_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_date_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_date_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_date_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_date_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_date_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_date_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'lc_12hr',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_date_1']['field_api_classes'] = 0;
  /* Field: Content: Where */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = '';
  $handler->display->display_options['fields']['field_location']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_location']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_location']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_location']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_location']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_location']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_location']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_location']['field_api_classes'] = 0;
  /* Field: Content: Campus Location */
  $handler->display->display_options['fields']['field_campus_location']['id'] = 'field_campus_location';
  $handler->display->display_options['fields']['field_campus_location']['table'] = 'field_data_field_campus_location';
  $handler->display->display_options['fields']['field_campus_location']['field'] = 'field_campus_location';
  $handler->display->display_options['fields']['field_campus_location']['label'] = '';
  $handler->display->display_options['fields']['field_campus_location']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_campus_location']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_campus_location']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_campus_location']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_campus_location']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_campus_location']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_campus_location']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_campus_location']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_campus_location']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_campus_location']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_campus_location']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_campus_location']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_campus_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campus_location']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_campus_location']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_campus_location']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_campus_location']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_campus_location']['field_api_classes'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Ticket */
  $handler->display->display_options['fields']['field_ticket']['id'] = 'field_ticket';
  $handler->display->display_options['fields']['field_ticket']['table'] = 'field_data_field_ticket';
  $handler->display->display_options['fields']['field_ticket']['field'] = 'field_ticket';
  $handler->display->display_options['fields']['field_ticket']['label'] = 'Tickets required';
  $handler->display->display_options['fields']['field_ticket']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_ticket']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_ticket']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_ticket']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_ticket']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_ticket']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_ticket']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_ticket']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_ticket']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_ticket']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_ticket']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_ticket']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_ticket']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_ticket']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_ticket']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_ticket']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_ticket']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_ticket']['field_api_classes'] = 0;
  /* Field: Content: Contact */
  $handler->display->display_options['fields']['field_contact']['id'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['table'] = 'field_data_field_contact';
  $handler->display->display_options['fields']['field_contact']['field'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_contact']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_contact']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: When (field_date) */
  $handler->display->display_options['arguments']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['arguments']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['arguments']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['arguments']['field_date_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_date_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_date_value']['glossary'] = 0;
  $handler->display->display_options['arguments']['field_date_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_date_value']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['field_date_value']['break_phrase'] = 0;
  /* Contextual filter: Content: Event Category (field_event_category) */
  $handler->display->display_options['arguments']['field_event_category_tid']['id'] = 'field_event_category_tid';
  $handler->display->display_options['arguments']['field_event_category_tid']['table'] = 'field_data_field_event_category';
  $handler->display->display_options['arguments']['field_event_category_tid']['field'] = 'field_event_category_tid';
  $handler->display->display_options['arguments']['field_event_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_event_category_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_event_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_event_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_event_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_event_category_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_event_category_tid']['not'] = 0;
  /* Contextual filter: Search: Search Terms */
  $handler->display->display_options['arguments']['keys']['id'] = 'keys';
  $handler->display->display_options['arguments']['keys']['table'] = 'search_index';
  $handler->display->display_options['arguments']['keys']['field'] = 'keys';
  $handler->display->display_options['arguments']['keys']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['keys']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['keys']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['keys']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['keys']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  $export['lc_events'] = $view;

  return $export;
}
