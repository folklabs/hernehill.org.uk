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
  $fe_block_boxes->format = 'panopoly_html_text';
  $fe_block_boxes->machine_name = 'ol_event_actions';
  $fe_block_boxes->body = '<p><a href="node/add/ol-event">Add event</a></p>
<p><a href="node/add/ol-place">Add place</a></p>';

  $export['ol_event_actions'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'OpenLocal Venue help';
  $fe_block_boxes->format = 'panopoly_wysiwyg_text';
  $fe_block_boxes->machine_name = 'ol_event_venue_help';
  $fe_block_boxes->body = '<p>These event venues are a mix of local places where events might be held or local businesses that are willing to be used as event venues (but please check first!). If you know of somewhere you want to use for an event that you dont see here, either add as a new place or contact the local business and ask them to update their page.</p>';

  $export['ol_event_venue_help'] = $fe_block_boxes;

  return $export;
}
