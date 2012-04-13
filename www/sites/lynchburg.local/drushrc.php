<?php
/**
 * @file Drush settings for local environment.
 */

# Include shared Drush settings.
require_once realpath(dirname(__FILE__) . '/../all/drush/drushrc_shared.php');

# Specify a particular multisite.
$options['uri'] = 'http://lynchburg.local';

# Specify the default dump directory.
$options['dump-dir'] = realpath(dirname(__FILE__) . '/../../../assets/db_snapshot/');

