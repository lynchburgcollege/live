<?php

/**
 * Implements hook_panels_layouts().
 */
function lynchburg_lynchburg_12_twocol_3_9_panels_layouts() {
  $items['lynchburg_12_twocol_3_9'] = array(
    'title' => t('Two column 3-9'),
    'category' => t('Lynchburg: 12 Column Grid'),
    'icon' => 'lynchburg_12_twocol_3_9.png',
    'theme' => 'lynchburg_12_twocol_3_9',
    'admin css' => '../lynchburg_panels_admin_12.css',
    'regions' => array(
      'top' => t('Top'),
      'left' => t('Left Column'),
      'main' => t('Main Content'),
      'bottom' => t('Bottom'),
    ),
  );

  return $items;
}
