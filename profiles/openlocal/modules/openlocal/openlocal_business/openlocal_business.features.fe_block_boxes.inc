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
  $fe_block_boxes->format = 'panopoly_html_text';
  $fe_block_boxes->machine_name = 'ol_business_actions';
  $fe_block_boxes->body = '<div class="ol-action-box">

<div class="ol-action-button">
<a href="node/add/ol-business"><span class="ol-action-span"><i class="fa fa-plus"></i> add business listing</span></a>
</div>

<div>
<a href="" class="ol-action-help"><i class="fa fa-question-circle"></i> About business listings</a>
</div>
</div>';

  $export['ol_business_actions'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Your business here?';
  $fe_block_boxes->format = 'panopoly_wysiwyg_text';
  $fe_block_boxes->machine_name = 'ol_business_your_business_here';
  $fe_block_boxes->body = '<p><strong>If you would like to advertise your business on these pages, please</strong> <a href="contact">get in touch</a>.</p>';

  $export['ol_business_your_business_here'] = $fe_block_boxes;

  return $export;
}
