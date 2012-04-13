<?php
/**
 * @file Shared Drush settings for all server environments.
 *
 * These settings are included by the specific drushrc.php files located in
 * the various server-specific Drupal multi-site folders, eg.,
 * sites/example.com/drushrc.php
 *
 * @see /path/to/drush/examples/example.drushrc.php
 */

# Store database dumps from sql-sync and sql-dump in the assets/db_snapshot folder.
$options['dump-dir'] = realpath(dirname(__FILE__) . '/../../../../assets/db_snapshot');

/**
 * Do not export data from the following Drupal database tables, during
 * 'sql-dump' and 'sql-sync'.
 */
$options['structure-tables'] = array(
  'common' => array(
    'cache',
//    'cache_admin_menu',
    'cache_block',
    'cache_bootstrap',
    'cache_field',
//    'cache_file_styles',
    'cache_filter',
    'cache_form',
    'cache_image',
    'cache_location',
    'cache_media_xml',
    'cache_menu',
    'cache_page',
    'cache_path',
//    'cache_styles',
    'cache_token',
    'cache_update',
    'cache_views',
    'cache_views_data',
    'ctools_css_cache',
    'history',
    'search_index',
    'search_total',
    'sessions',
    'watchdog',
  ),
);

# Use the above by default.
$options['structure-tables-key'] = 'common';

# Output sql dumps to a file with the database name and current date.
$options['result-file'] = '@DATABASE_@DATE.sql';

# Order the SQL dump by primary key.
$options['ordered-dump'] = TRUE;

# Don't notify about Drush updates.
$options['self-update'] = FALSE;

# Don't make backups of the files that are updated.
$options['no-backup'] = TRUE;

/**
 * Useful shell aliases.
 */
$options['shell-aliases']['pull'] = '!git pull'; // We've all done it.
$options['shell-aliases']['pulldb'] = '!git pull && drush updatedb';
$options['shell-aliases']['noncore'] = 'pm-list --no-core';
$options['shell-aliases']['wipe'] = 'cache-clear all';
$options['shell-aliases']['unsuck'] = 'pm-disable -y overlay,dashboard';
$options['shell-aliases']['offline'] = 'variable-set -y --always-set maintenance_mode 1';
$options['shell-aliases']['online'] = 'variable-delete -y --exact maintenance_mode';
