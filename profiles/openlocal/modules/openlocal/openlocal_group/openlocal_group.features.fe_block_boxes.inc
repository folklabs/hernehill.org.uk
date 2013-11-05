<?php
/**
 * @file
 * openlocal_group.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function openlocal_group_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'OpenLocal Group actions';
  $fe_block_boxes->format = 'panopoly_wysiwyg_text';
  $fe_block_boxes->machine_name = 'ol_group_actions';
  $fe_block_boxes->body = '<p><a href="node/add/ol-group">Add group</a></p>';

  $export['ol_group_actions'] = $fe_block_boxes;

  return $export;
}
