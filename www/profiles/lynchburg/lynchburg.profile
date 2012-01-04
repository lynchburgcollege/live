<?php
/**
 * @file
 * Main hook implementations for the BSP Installer 7 installation profile.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function lynchburg_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = 'Lynchburg College';
  $form['site_information']['site_mail']['#default_value'] = 'webmaster@bluesparklabs.com';

  // Admin account.
  $form['admin_account']['account']['name']['#default_value'] = 'admin';
  $form['admin_account']['account']['mail']['#default_value'] = 'webmaster@bluesparklabs.com';

  // Default server settings.
  $form['server_settings']['site_default_country']['#default_value'] = 'US';
  $form['server_settings']['clean_url']['#default_value'] = '1';
  // This is automatic.
  // $form['server_settings']['date_default_timezone']['#default_value'] = 'America/New_York';

  // Update notifications
  $form['update_notifications']['update_status_module']['#default_value'][0] = 0;
  $form['update_notifications']['update_status_module']['#default_value'][1] = 0;
}
