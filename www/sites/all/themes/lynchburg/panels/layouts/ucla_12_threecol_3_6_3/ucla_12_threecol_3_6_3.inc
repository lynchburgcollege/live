<?php

/**
 * Implements hook_panels_layouts().
 */
function ucla_ucla_12_threecol_3_6_3_panels_layouts() {
  $items['ucla_12_threecol_3_6_3'] = array(
    'title' => t('Three column 3-6-3'),
    'category' => t('UCLA: 12 Column Grid'),
    'icon' => 'ucla_12_threecol_3_6_3.png',
    'theme' => 'ucla_12_threecol_3_6_3',
    'admin css' => '../ucla_panels_admin_12.css',
    'regions' => array(
      'left' => t('Left Column'),
      'main' => t('Main Content'),
      'right' => t('Right Column'),
    ),
  );

  return $items;
}
