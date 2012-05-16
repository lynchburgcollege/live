<?php

/**
 * Implements hook_panels_layouts().
 */
function lynchburg_lynchburg_12_twocol_9_3_panels_layouts() {
  $items['lynchburg_12_twocol_9_3'] = array(
    'title' => t('Two column 9-3'),
    'category' => t('Lynchburg: 12 Column Grid'),
    'icon' => 'lynchburg_12_twocol_9_3.png',
    'theme' => 'lynchburg_12_twocol_9_3',
    'admin css' => '../lynchburg_panels_admin_12.css',
    'regions' => array(
      'top' => t('Top'),
      'main' => t('Main Content'),
      'right' => t('Right Column'),
      'bottom' => t('Bottom'),
    ),
  );

  return $items;
}
