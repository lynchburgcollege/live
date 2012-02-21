<?php
/**
 * @file
 * course_1_1.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function course_1_1_taxonomy_default_vocabularies() {
  return array(
    'course_prefix' => array(
      'name' => 'Course Prefix',
      'machine_name' => 'course_prefix',
      'description' => 'Course catalog prefix',
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
