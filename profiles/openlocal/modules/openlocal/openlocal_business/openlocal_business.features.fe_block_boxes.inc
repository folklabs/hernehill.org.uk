<?php
/**
 * @file
 * openlocal_business.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function openlocal_business_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'OpenLocal Business actions';
  $fe_block_boxes->format = 'panopoly_wysiwyg_text';
  $fe_block_boxes->machine_name = 'ol_business_actions';
  $fe_block_boxes->body = '<p><a href="node/add/ol-business">Add business listing</a></p>';

  $export['ol_business_actions'] = $fe_block_boxes;

  return $export;
}
