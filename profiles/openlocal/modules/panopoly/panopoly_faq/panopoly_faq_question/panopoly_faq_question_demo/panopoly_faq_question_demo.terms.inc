<?php
/**
 * @file
 * panopoly_faq_question_demo.inc
 */

/**
 * Awesome Roman names
 */
function panopoly_faq_question_demo_terms() {
  $export = array();

  $terms = array(
    'Demo FAQ',
  );

  foreach($terms as $term_name) {
    $term = new stdClass();
    $term->name = $term_name;
    $export[] = $term;
  }

  return $export;
}
