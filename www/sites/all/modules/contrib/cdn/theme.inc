<?php
// $Id: theme.inc,v 1.8.2.3 2011/01/04 21:25:08 wimleers Exp $

/**
 * @file
 * Theme functions.
 */

/**
 * Render the CDN integration page statistics.
 *
 * @param $variables
 *   An associative array containing:
 *   - file_count: The number of files detected on this page.
 *   - cdn_file_count: The number of files on this page that are served from a
 *     CDN.
 *   - synced_files_per_server_count: The number of files synced to each
 *     server.
 *   - total_time: The total time it took to get all current CDN URLs.
 *   - synced_files: Array of synchronized files.
 *   - unsynced_files: Array of unsynchronized files.
 * @return
 *   The rendered HTML.
 */
function theme_cdn_page_stats($variables) {
  $file_count                    = $variables['file_count'];
  $cdn_file_count                = $variables['cdn_file_count'];
  $synced_files_per_server_count = $variables['synced_files_per_server_count'];
  $total_time                    = $variables['total_time'];
  $synced_files                  = $variables['synced_files'];
  $unsynced_files                = $variables['unsynced_files'];

  $output = '';
  $items = array();
  $mode = variable_get(CDN_MODE_VARIABLE, CDN_MODE_BASIC);

  $output .= '<div id="cdn-integration-page-stats">';
  $items[] = 'Total number of files on this page: <strong>'. $file_count .'</strong>.';
  $percentage = ($file_count == 0) ? '100' : ($file_count > 0) ? number_format($cdn_file_count / $file_count * 100) : 0;
  $items[] = 'Number of files available on CDNs: <strong>'. $cdn_file_count .'</strong> ('. $percentage . '% coverage).';
  foreach (array_keys($synced_files_per_server_count) as $server) {
    $items[] = t('Number of files served from the server %server: !count', array('%server' => $server, '!count' => $synced_files_per_server_count[$server]));
  }
  $items[] = t('Total time it took to look up the CDN URLs for these files:
                !total-time ms, or !avg-time ms on average per file.',
                array(
                  '!total-time' => round($total_time * 1000, 3),
                  '!avg-time'   => ($file_count > 0) ? round($total_time * 1000 / $file_count, 3) : 0,
                )
  );


  // Nested list of unsynced files.
  if ($mode != CDN_MODE_BASIC) {
    if (count($unsynced_files)) {
      $unsynced_items = array();
      foreach ($unsynced_files as $file) {
        $unsynced_items[] = theme('cdn_page_stats_file_link', array(
          'file'          => $file,
          'absolute_path' => file_create_url($file),
          'synced'        => FALSE,
          'cdn_url'       => $file,
          'server'        => NULL,
        ));
      }
      $items[] = t('The files that are not (yet?) synchronized to the CDN:') . theme('item_list', array('items' => $unsynced_items, 'attributes' => array('class' => 'file-list')));
    }
  }

  // Nested list of synced files.
  if (count($synced_files)) {
    $synced_items = array();
    foreach ($synced_files as $synced_file) {
      $file    = $synced_file['file'];
      $cdn_url = $synced_file['cdn_url'];
      $server  = $synced_file['server'];

      $synced_items[] = theme('cdn_page_stats_file_link', array(
        'file'          => $file,
        'absolute_path' => $synced_file['absolute path'],
        'synced'        => TRUE,
        'cdn_url'       => $cdn_url,
        'server'        => $server,
      ));
    }
    $items[] = t('The files that are synchronized to the CDN:') . theme('item_list', array('items' => $synced_items, 'attributes' => array('class' => 'file-list')));
  }

  $output .= theme('item_list', array('items' => $items, 'title' => '<strong>'. t('CDN integration statistics for %drupal_path', array('%drupal_path' => $_GET['q'])) .'</strong>'));
  $output .= '</div>';
  return $output;
}

/**
 * Render a file link in the CDN integration page statistics.
 *
 * @param $variables
 *   An associative array containing:
 *   - file: A string containing the Drupal path (i.e. path relative to the
 *     Drupal root directory) of the file to generate the URL for.
 *   - absolute_path: The absolute path (on the filesystem) to the file.
 *   - synced: Whether this file has been synced to the CDN or not.
 *   - cdn_url: The CDN URL of the file, or the normal URL when the file is
 *     not on a CDN.
 *   - server: The server on which the file resides.
 * @return
 *   The rendered HTML.
 */
function theme_cdn_page_stats_file_link($variables) {
  $file          = $variables['file'];
  $absolute_path = $variables['absolute_path'];
  $synced        = $variables['synced'];
  $cdn_url       = $variables['cdn_url'];
  $server        = $variables['server'];
  
  $file_link  = l(t(($server == NULL) ? '!file' : '!file (server: !server)', array('!file' => $file, '!server' => $server)), $cdn_url, array('attributes' => array('title' => $absolute_path)));
  $touch_link = l(t('touch'), 'admin/cdn/touch/' . $file);

  $output = '';
  $output .= '<span class="file-link">' . $file_link;
  if ($synced) {
    $output .= '<span class="touch-link">';
    $output .=   '<span class="arrow">' . t('→') . '</span>';
    $output .=    $touch_link;
    $output .=   '<span class="touch-help">' . t('Touching this file will trigger a resync to the CDN.') . '</span>';
    $output .= '</span>';
  }
  $output .= '</span>';
  return $output;
}
