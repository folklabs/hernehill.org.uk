<?php
/**
 * @file
 * openlocal_event.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function openlocal_event_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'OpenLocal Event actions';
  $fe_block_boxes->format = 'panopoly_wysiwyg_text';
  $fe_block_boxes->machine_name = 'ol_event_actions';
  $fe_block_boxes->body = '<p><a href="node/add/ol-event">Add event</a></p>';

  $export['ol_event_actions'] = $fe_block_boxes;

  return $export;
}
