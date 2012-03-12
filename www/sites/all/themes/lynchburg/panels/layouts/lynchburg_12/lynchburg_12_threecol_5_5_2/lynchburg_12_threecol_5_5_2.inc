<?php

/**
 * Implements hook_panels_layouts().
 */
function lynchburg_lynchburg_12_threecol_5_5_2_panels_layouts() {
  $items['lynchburg_12_threecol_5_5_2'] = array(
    'title' => t('Three column 5-5-2'),
    'category' => t('lynchburg: 12 Column Grid'),
    'icon' => 'lynchburg_12_threecol_5_5_2.png',
    'theme' => 'lynchburg_12_threecol_5_5_2',
    'admin css' => '../lynchburg_panels_admin_12.css',
    'regions' => array(
      'left' => t('Left Column'),
      'main' => t('Main Content'),
      'right' => t('Right Column'),
    ),
  );

  return $items;
}
