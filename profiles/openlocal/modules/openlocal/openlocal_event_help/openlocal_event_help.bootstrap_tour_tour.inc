<?php
/**
 * @file
 * openlocal_event_help.bootstrap_tour_tour.inc
 */

/**
 * Implements hook_default_bootstrap_tour().
 */
function openlocal_event_help_default_bootstrap_tour() {
  $export = array();

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'event_help';
  $bootstrap_tour->title = 'Event help';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 1;
  $bootstrap_tour->description = 'A tour of Event fields.';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '#page-title',
      'path' => 'node/add/ol-event',
      'placement' => 'top',
      'title' => 'Creating an event',
      'content' => '<p>Step through this tour for a description of how to enter an event.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '#node-edit .pane-node-field-featured-image h2',
      'path' => 'node/add/ol-event',
      'placement' => 'top',
      'title' => 'Add an image',
      'content' => '<p>Add a main image here that will be shown in teaser views and at the top of the detailed event view.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '#edit-field-ol-event-date-und-0-value-datepicker-popup-0',
      'path' => 'node/add/ol-event',
      'placement' => 'top',
      'title' => 'Set the event date',
      'content' => '<p>The start and end date are for just <strong>one</strong> event. If an event repeats over several days, or is weekly or monthly, use the repeating date field below.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['event_help'] = $bootstrap_tour;

  return $export;
}
