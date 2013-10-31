<?php
/**
 * @file
 * panopoly_faq_question.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function panopoly_faq_question_taxonomy_default_vocabularies() {
  return array(
    'faq_group' => array(
      'name' => 'FAQ Group',
      'machine_name' => 'faq_group',
      'description' => '',
      'hierarchy' => '1',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
