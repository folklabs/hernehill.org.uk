<?php
/**
 * @file
 * openlocal_issue.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function openlocal_issue_taxonomy_default_vocabularies() {
  return array(
    'ol_issue_type' => array(
      'name' => 'Issue type',
      'machine_name' => 'ol_issue_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
