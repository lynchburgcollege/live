<?php

/**
 * Implements hook_panels_layouts().
 */
function lynchburg_lynchburg_12_twocol_5_7_bricks_panels_layouts() {
  $items['lynchburg_12_twocol_5_7_bricks'] = array(
    'title' => t('Two Column 5-7 bricks'),
    'category' => t('Lynchburg: 12 Column Grid'),
    'icon' => 'lynchburg_12_twocol_5_7_bricks.png',
    'theme' => 'lynchburg_12_twocol_5_7_bricks',
    'admin css' => '../lynchburg_panels_admin_12.css',
    'regions' => array(
      'top' => t('Top'),
      'left_above' => t('Left above'),
      'right_above' => t('Right above'),
      'middle' => t('Middle'),
      'left_below' => t('Left below'),
      'right_below' => t('Right below'),
      'bottom' => t('Bottom'),
    ),
  );

  return $items;
}
