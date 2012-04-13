<?php
/**
 * @file
 * lc_styles.stylizer.inc
 */

/**
 * Implements hook_default_stylizer().
 */
function lc_styles_default_stylizer() {
  $export = array();

  $style = new stdClass();
  $style->disabled = FALSE; /* Edit this to true to make a default style disabled initially */
  $style->api_version = 1;
  $style->name = 'lc_rounded_pane';
  $style->admin_title = 'LC Rounded';
  $style->admin_description = 'Lynchburg custom rounded pane style.';
  $style->settings = array(
    'name' => 'lc_rounded_pane',
    'style_base' => 'pane_plain_box',
    'font' => array(
      'font' => '',
      'size' => '',
      'letter_spacing' => '',
      'word_spacing' => '',
      'decoration' => '',
      'weight' => '',
      'style' => '',
      'variant' => '',
      'case' => '',
      'alignment' => '',
    ),
    'header_font' => array(
      'font' => '',
      'size' => '',
      'letter_spacing' => '',
      'word_spacing' => '',
      'decoration' => '',
      'weight' => '',
      'style' => '',
      'variant' => '',
      'case' => '',
      'alignment' => '',
    ),
    'border' => array(
      'thickness' => '',
      'style' => '',
    ),
    'header_border' => array(
      'thickness' => '',
      'style' => '',
    ),
    'padding' => array(
      'top' => '',
      'right' => '',
      'bottom' => '',
      'left' => '',
    ),
    'palette' => array(
      'background' => '#FFFFFF',
      'text' => '#000000',
      'border' => '#000000',
      'header-background' => '#FFFFFF',
      'header-text' => '#000000',
      'header-border' => '#000000',
    ),
  );
  $export['lc_rounded_pane'] = $style;

  $style = new stdClass();
  $style->disabled = FALSE; /* Edit this to true to make a default style disabled initially */
  $style->api_version = 1;
  $style->name = 'lc_rounded_region';
  $style->admin_title = 'LC Rounded';
  $style->admin_description = 'Lynchburg custom rounded region style.';
  $style->settings = array(
    'name' => 'lc_rounded_region',
    'style_base' => 'region_plain_box',
    'font' => array(
      'font' => '',
      'size' => '',
      'letter_spacing' => '',
      'word_spacing' => '',
      'decoration' => '',
      'weight' => '',
      'style' => '',
      'variant' => '',
      'case' => '',
      'alignment' => '',
    ),
    'border' => array(
      'thickness' => '',
      'style' => '',
    ),
    'padding' => array(
      'top' => '',
      'right' => '',
      'bottom' => '',
      'left' => '',
    ),
    'palette' => array(
      'background' => '#FFFFFF',
      'text' => '#000000',
      'border' => '#000000',
    ),
  );
  $export['lc_rounded_region'] = $style;

  return $export;
}
