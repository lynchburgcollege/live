<?php

/**
 * Implements hook_panels_layouts().
 */
function lynchburg_lynchburg_12_twocol_6_6_stacked_panels_layouts() {
  $items['lynchburg_12_twocol_6_6_stacked'] = array(
    'title' => t('Two Column 6-6 stacked'),
    'category' => t('lynchburg: 12 Column Grid'),
    'icon' => 'lynchburg_12_twocol_6_6_stacked.png',
    'theme' => 'lynchburg_12_twocol_6_6_stacked',
    'admin css' => '../lynchburg_panels_admin_12.css',
    'regions' => array(
      'top' => t('Top'),
      'left' => t('Left'),
      'right' => t('Right'),
      'bottom' => t('Bottom'),
    ),
  );

  return $items;
}
