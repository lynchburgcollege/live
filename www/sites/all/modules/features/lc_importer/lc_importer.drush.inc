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
  $items['import-images'] = array(
    'description' => "Imports LC images.",
    'arguments' => array(
      'filename' => 'XML file.',
      'filepath' => 'Absolute path to files directory in which to place downloaded files.',
    ),
    'examples' => array(
      'drush import-images all.xml /home/lynchburg/public_html/www/files' => 'Import images from all.xml.',
    ),
  );
  $items['clean-text'] = array(
    'description' => "Cleans text in imported pages.",
    'examples' => array(
      'drush clean-text' => 'Clean up text in all pages.',
    ),
  );
  return $items;
}

function drush_lc_importer_clean_text() {
  $query = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('type', 'page', '=');
  $result = $query->execute();

  foreach ($result as $record) {
    $modified = FALSE;
    $node = node_load($record->nid);
    // Fix Image paths.
    $node->body[$node->language][0]['value'] = preg_replace('#\ssrc="images/#i', ' src="/Images/', $node->body[$node->language][0]['value'], -1, $strings_replaced);
    if ($strings_replaced > 0) {
      $modified = TRUE;
    }
    // Change formmail paths.
    $node->body[$node->language][0]['value'] = preg_replace('#\saction="[^"]*formmail.asp"#i', ' action="/lc_formhandler"', $node->body[$node->language][0]['value'], -1, $strings_replaced);
    if ($strings_replaced > 0) {
      $modified = TRUE;
      // print($node->body[$node->language][0]['value']);
    }
    if ($modified) {
      node_save($node);
    }
  }

}

function drush_lc_importer_import_images($file, $filepath) {
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

  foreach ($xml->Page1 as $page) {
    $page_id = (string) $page['ID'];
    $page_html = (string) $page->BodyCopy;
    // print "page_id: $page_id\n";
    // Parse this page for images.
    $DOM = new DOMDocument;
    @$DOM->loadHTML($page_html);
    // Get all img elements
    $images = $DOM->getElementsByTagName('img');
    foreach ($images as $image) {
      $target = $image->getAttribute('src');
      $target = str_replace('http://www.lynchburg.edu/', '', $target);
      // Get rid of leading ../s.
      while (strpos($target, '../', 0) !== FALSE) {
        $target = substr($target, 3);
      }
      print "target: $target\n";
      if (strpos($target, 'http', 0) !== FALSE) {
        print "Not on lynchburg.edu!\n\n";
        continue;
      }
      if (strpos($target, 'data:image', 0) !== FALSE) {
        print "Inline data!";
        continue;
      }
      // Download file to local storage.
      $dir = $filepath . "/" . dirname($target);
      $filename = str_replace(' ', '%20', basename($target));
      // Download the file if we haven't already.
      if (!file_exists($filepath . "/" . $target)) {
        @mkdir($dir, 0777, TRUE);
        file_put_contents($filepath . "/" . $target, file_get_contents("http://www.lynchburg.edu/" . str_replace(' ', '%20', dirname($target)) . '/' . $filename));
      }
      lc_importer_add_redirect($file_id . '.xml', "files/archives/" . $target);
      print "\n\n";
    }
  }
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
    // Get rid of anchors.
    $target = preg_replace('/#.*$/', '', $target);
    print "target: $target\n";
    // Download file to local storage.
    $dir = $filepath . "/archives/" . dirname($target);
    $filename = str_replace(' ', '%20', basename($target));
    // Download the file if we haven't already.
    if (!file_exists($filepath . "/archives/" . $target)) {
      mkdir($dir, 0777, TRUE);
      file_put_contents($filepath . "/archives/" . $target, file_get_contents("http://www.lynchburg.edu/" . dirname($target) . '/' . $filename));
    }
    lc_importer_add_redirect($file_id . '.xml', "files/archives/" . $target);
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

    // Find how many levels deep we go below this node.
    $childdepth = 0;
    if (count($page->children()) > 0) {
      $childdepth = 1;
      foreach ($page->children() as $child) {
        if (count($child->children()) > 0) {
          $childdepth = 2;
          foreach ($child->children() as $second_level) {
            if (count($second_level->children()) > 0) {
              $childdepth = 3;
              continue;
            }
          }
        }
      }
    }
    print "Child depth is $childdepth.\n";

    // Use taxonomy for at least the top 3 levels, nodehierarchy for bottom two levels.
    if ($depth == 0 || $childdepth > 1) {
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
            print "Using term with name $term->name\n";
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
        print "Using term with name $new_term->name\n";
      }
    }
    else {
      // This is a section node, use the parent tid to tag.
      print "Using references for this node!\n";
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
        print $tid;
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
      // This is not a new level of the taxonomy, we need to add the node reference info.
      if (is_object($node)) {
        // Clear out existing references.
        if (isset($node->field_parents[$node->language])) {
          unset($node->field_parents[$node->language]);
        }
        if (isset($node->field_children[$node->language])) {
          unset($node->field_children[$node->language]);
        }
        $node->field_parents[$node->language] = array(
          0 => array(
            'nid' => $parent_nid,
          ),
        );
        node_save($node);
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
}

/**
 * Helper function - add 301 redirect with given params
 *
 * @param $source
 * @param $target
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
