<?php
/**
 * @file
 * lc_organizations.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function lc_organizations_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'club_and_organization_directory';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Club and Organization Directory';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Club and Organization Directory';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_organization_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<?php
if ($vocab_object = taxonomy_vocabulary_machine_name_load(\'organization_type\')) {
  $vid = $vocab_object->vid;
}

if (isset($vid)) {
  $terms = taxonomy_get_tree($vid);
  foreach ($terms as $term) {
    print \'<a href="#\' . $term->name . \'">\' . $term->name . \'</a> \';
  }
}
?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
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
  $handler->display->display_options['fields']['body']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Contact */
  $handler->display->display_options['fields']['field_organization_contact']['id'] = 'field_organization_contact';
  $handler->display->display_options['fields']['field_organization_contact']['table'] = 'field_data_field_organization_contact';
  $handler->display->display_options['fields']['field_organization_contact']['field'] = 'field_organization_contact';
  $handler->display->display_options['fields']['field_organization_contact']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_contact']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_contact']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_contact']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_contact']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_contact']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_contact']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_contact']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_contact']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_contact']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_organization_contact']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_contact']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_contact']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_contact']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_organization_contact']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_contact']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_contact']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_contact']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_organization_contact']['field_api_classes'] = 0;
  /* Field: Content: Organization Type */
  $handler->display->display_options['fields']['field_organization_type']['id'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['field'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['label'] = '';
  $handler->display->display_options['fields']['field_organization_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_organization_type']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_organization_type']['alter']['text'] = '<a name="[field_organization_type]">[field_organization_type]</a>';
  $handler->display->display_options['fields']['field_organization_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_organization_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_organization_type']['field_api_classes'] = 0;
  /* Sort criterion: Content: Organization Type (field_organization_type) */
  $handler->display->display_options['sorts']['field_organization_type_tid']['id'] = 'field_organization_type_tid';
  $handler->display->display_options['sorts']['field_organization_type_tid']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['sorts']['field_organization_type_tid']['field'] = 'field_organization_type_tid';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organization' => 'organization',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'organizations';
  $export['club_and_organization_directory'] = $view;

  return $export;
}
