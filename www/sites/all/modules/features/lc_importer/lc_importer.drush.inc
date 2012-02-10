<?php
// @todo: make sure url path aliases are re-generated.

/**
 * @file lc_importer.drush.inc
 * @author Adrian Rollett
 *
 * @date 2012-01-25
 */

function lc_importer_drush_help($section) {
  switch ($section) {
    case 'drush:import-nav':
      return dt("Import navigation structure for Lynchburg College.");
      break;
    default:
      break;
  }
}

function lc_importer_drush_command() {
  $items = array();
  $items['import-nav'] = array(
    'description' => "Imports LC navigation structure.",
    'arguments' => array(
      'filename' => 'XML file.',
    ),
    'examples' => array(
      'drush import-nav reference.xml' => 'Import navigation structure from reference.xml.',
    ),
  );
  $items['import-links'] = array(
    'description' => "Imports LC link components.",
    'arguments' => array(
      'filename' => 'XML file.',
    ),
    'examples' => array(
      'drush import-links link_components.xml' => 'Import link components from link_components.xml.',
    ),
  );
  $items['import-files'] = array(
    'description' => "Imports LC files.",
    'arguments' => array(
      'filename' => 'XML file.',
      'filepath' => 'Absolute path to files directory in which to place downloaded files.',
    ),
    'examples' => array(
      'drush import-files binary_documents.xml /home/lynchburg/public_html/www/files' => 'Import files from link_components.xml.',
    ),
  );
  return $items;
}

function drush_lc_importer_import_files($file, $filepath) {
  if (!($contents = file_get_contents($file))) {
    return drush_set_error('FILE_NOT_FOUND', dt('Could not load specified filename.'));
  }
  if (!(strlen($filepath))) {
    return drush_set_error('FILE_NOT_FOUND', dt('You must specify a filepath.'));
  }

  try {
    $xml = new SimpleXMLElement($contents);
  }
  catch (Exception $e) {
    return drush_set_error('INVALID_XML', dt('Could not parse specified file as XML.'));
  }

  foreach ($xml->BinaryDocument as $file) {
    $file_id = (string) $file['ID'];
    print "file_id: $file_id\n";
    $target = (string) $file->DocumentURL;
    if (strpos($target, 'documents/') === FALSE) {
      $target = 'documents/' . $target;
    }
    print "target: $target\n";
    // Download file to local storage.
    $dir = $filepath . "/archives/" . dirname($target);
    $filename = str_replace(' ', '%20', basename($target));
    mkdir($dir, 0777, TRUE);
    file_put_contents($filepath . "/archives/" . $target, file_get_contents("http://www.lynchburg.edu/" . dirname($target) . '/' . $filename));
    lc_importer_add_redirect($link_id . '.xml', $target);
    print "\n\n";
  }
}

function drush_lc_importer_import_links($file) {
  if (!($contents = file_get_contents($file))) {
    return drush_set_error('FILE_NOT_FOUND', dt('Could not load specified filename.'));
  }

  try {
    $xml = new SimpleXMLElement($contents);
  }
  catch (Exception $e) {
    return drush_set_error('INVALID_XML', dt('Could not parse specified file as XML.'));
  }

  foreach ($xml->LinkComponent as $link) {
    $link_id = (string) $link['ID'];
    print "link_id: $link_id\n";
    $target = (string) $link->Destination;
    $target = str_replace('http://www.lynchburg.edu/', '', $target);
    print "target: $target\n";
    print "\n";
    lc_importer_add_redirect($link_id . '.xml', $target);
  }
}

function drush_lc_importer_import_nav($file) {
  // Setup.
  $vocabs = taxonomy_get_vocabularies(NULL);
  foreach ($vocabs as $vocab_object) {
    if ($vocab_object->machine_name == 'site_structure') {
      $vid = $vocab_object->vid;
    }
  }

  if (!isset($vid)) {
    return drush_set_error('VID_NOT_FOUND', dt('Could not load the vocabulary!'));
  }

  if (!($contents = file_get_contents($file))) {
    return drush_set_error('FILE_NOT_FOUND', dt('Could not load specified filename.'));
  }

  try {
    $xml = new SimpleXMLElement($contents);
  }
  catch (Exception $e) {
    return drush_set_error('INVALID_XML', dt('Could not parse specified file as XML.'));
  }

  foreach ($xml->Page[0]->Page[0]->Page[0] as $page) {
    // This is the root level of the tree for our purposes.
    lc_importer_tag_node($page, $vid, 0, 0);
  }

}

/**
 * Take a given xml element and tag the corresponding node correctly.
 *
 * @param $page
 *   object: simplexml entity.
 * @param $vid
 *   int: vid of site structure vocabulary.
 * @param $parent
 *   int: tid of parent term.
 * @param $depth
 *   int: current depth within hierarchy.
 */
function lc_importer_tag_node($page, $vid, $parent, $depth, $parent_nid = 0) {
  print "parent: $parent, depth: $depth, parent_nid: $parent_nid\n";

  $name = (string) $page['Name'];
  $page_id = (string) $page['ID'];
  $publish_as = (string) $page['PublishAs'];
  $schema = (string) $page['Schema'];
  print "name: $name, page_id: $page_id, publish_as: $publish_as, schema: $schema\n";

  if ($schema == 'LinkComponent' || $schema == 'BinaryDocument') {
    // Fixme: perhaps remove parent_nid test for final import.
    if ($parent_nid > 0) {
      // This is a link component, add to the related links of the parent.
      $node = node_load($parent_nid);
      $add_link = TRUE;
      $path = $page_id . '.xml';
      if (isset($node->field_links[$node->language])) {
        $links = $node->field_links[$node->language];
      }
      // Check if this link is already set.
      if (count($links)) {
        foreach ($links as $link) {
          if ($link['url'] == $path) {
            // This link already exists, don't re-add it.
            $add_link = FALSE;
          }
        }
      }
      if ($add_link) {
        $new_link = array(
          'url' => $path,
          'title' => $name,
        );
        $node->field_links[$node->language][] = $new_link;
        node_save($node);
      }
    }
  }
  else {
    $tid = 0;

    // We will only use 3 levels of taxonomy.
    if ($depth < 3) {
      if ($depth >= 1) {
        // This is the deepest possible level of the taxonomy.
        // Check if this page has children - If so, use a taxonomy term.
        // If not, use nodehierarchy and tag with the parent element.
        if (count($page->children()) == 0) {
          $tid = $parent;
        }
      }

      if ($tid == 0) {
        // This page has children.
        // First, load the appropriate level of the Site Structure vocabulary.
        $tree = taxonomy_get_tree($vid, $parent, 1);

        // See if we can find a matching taxonomy term.
        foreach ($tree as $term) {
          // Ignore case for a better chance at a match.
          if (strtolower($name) == strtolower($term->name)) {
            // This is a match! Use this tid.
            $tid = $term->tid;
            continue;
          }
        }
      }

      if ($tid == 0) {
        // Couldn't find an existing tid, we need to create one.
        $new_term = new StdClass();
        $new_term->vid = $vid;
        $new_term->name = $name;
        $new_term->parent = $parent;
        $new_term->description = 'Auto-generated on import.';
        taxonomy_term_save($new_term);
        $tid = $new_term->tid;
      }
    }
    else {
      // This node is more than 2 levels deep, use the parent tid to tag.
      $tid = $parent;
    }

    // Find the node id.
    $result = db_select('feeds_item', 'f')
      ->fields('f', array('entity_id'))
      ->condition('guid', $page_id, '=')
      ->execute()
      ->fetchAssoc();

    $nid = 0;
    if (isset($result['entity_id'])) {
      $nid = $result['entity_id'];
      // Load the node
      if ($node = node_load($nid)) {
        $node->field_nav[$node->language][0]['tid'] = $tid;
        node_save($node);

        // Add a redirect from the xml url to the new url.
        lc_importer_add_redirect($page_id . '.xml', 'node/' . $nid);
        if (strlen($publish_as)) {
          // This page has a "pretty url", add redirects for it.
          lc_importer_add_redirect($publish_as, 'node/' . $nid);
          // Pretty urls on the old site worked with or without a trailing ".xml".
          lc_importer_add_redirect($publish_as . '.xml', 'node/' . $nid);
        }
      }
    }

    if ($tid == $parent) {
      // This is not a new level of the taxonomy, we need to add the nodehierarchy info.
      // Code from: http://drupal.org/node/1391578
      if (is_object($node)) {
        $plid = _nodehierarchy_get_node_mlid($parent_nid, TRUE);
        $nodehierarchy_menu_links = _nodehierarchy_default_menu_link($parent_nid, $plid);
        $nodehierarchy_menu_links['pnid']= $parent_nid;
        $nodehierarchy_menu_links['hidden'] = FALSE;
        $nodehierarchy_menu_links['enabled'] = TRUE;
        $nodehierarchy_old_menu_links = $nodehierarchy_menu_links;
        $nodehierarchy_old_menu_links['enabled'] = TRUE;
        unset($nodehierarchy_old_menu_links['hidden']);
        unset($nodehierarchy_old_menu_links['link_path']);
        $nodehierarchy_old_menu_links['link_title'] = '';
        $nodehierarchy_old_menu_links['expanded'] = '';
        $nodehierarchy_old_menu_links['description'] = '';
        $nodehierarchy_old_menu_links['customized'] = '';
        $node->nodehierarchy_menu_links[] = $nodehierarchy_menu_links;
        $node->nodehierarchy_old_menu_links[] = $nodehierarchy_old_menu_links;

        _nodehierarchy_save_node($node);
      }
    }

    // Now take care of any children.
    if (count($page->children()) > 0) {
      // This element has children, parse them recursively.
      foreach ($page->children() as $child) {
        lc_importer_tag_node($child, $vid, $tid, $depth + 1, $nid);
      }
    }
  }

  print "\n";
}

/**
 * Helper function - add 301 redirect with given params
 *
 * @param $source
 * @param $nid
 */
function lc_importer_add_redirect($source, $target) {
  $redirect = new stdClass();
  redirect_object_prepare($redirect);
  // Set the parameters.
  $redirect->source = $source;
  $redirect->redirect = $target;
  $redirect->status_code = 301;

  redirect_hash($redirect);

  // Make sure this redirect doesn't already exist.
  if (!redirect_load_by_hash($redirect->hash)) {
    redirect_save($redirect);
  }
}
