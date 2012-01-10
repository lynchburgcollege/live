<?php
/**
 * @file
 * lc_navigation.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function lc_navigation_taxonomy_default_vocabularies() {
  return array(
    'site_structure' => array(
      'name' => 'Site Structure',
      'machine_name' => 'site_structure',
      'description' => 'The site\'s structure - used for navigation',
      'hierarchy' => '1',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
