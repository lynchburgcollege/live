<?php

/**
 * Implements hook_panels_layouts().
 */
function lc_lc_12_threecol_3_6_3_panels_layouts() {
  $items['lc_12_threecol_3_6_3'] = array(
    'title' => t('Three column 3-6-3'),
    'category' => t('LC: 12 Column Grid'),
    'icon' => 'lc_12_threecol_3_6_3.png',
    'theme' => 'lc_12_threecol_3_6_3',
    'admin css' => '../lc_panels_admin_12.css',
    'regions' => array(
      'left' => t('Left Column'),
      'main' => t('Main Content'),
      'right' => t('Right Column'),
    ),
  );

  return $items;
}
