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
<a href="/node/add/ol-business"><span class="ol-action-span"><i class="fa fa-plus"></i> add business listing</span></a>
</div>

<div>
<a href="/contextual_help/how-add-business" class="ol-action-help"><i class="fa fa-question-circle"></i> About business listings</a>
</div>
</div>';

  $export['ol_business_actions'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'OL Business page description';
  $fe_block_boxes->format = 'panopoly_wysiwyg_text';
  $fe_block_boxes->machine_name = 'ol_business_page_description';
  $fe_block_boxes->body = '<div class="panels-ipe-portlet-content"><div class="panel-pane pane-fieldable-panels-pane pane-fpid-2 pane-bundle-text"><div class="fieldable-panels-pane"><div class="field field-name-field-basic-text-text field-type-text-long field-label-hidden"><div class="field-items"><div class="field-item even"><p>This is a list of locally based service companies based in or around the Herne Hill, SE24 area. The contents are entirely the responsibility of the traders themselves so read them in that light.</p><p>If you wish to post a review of a local trader, or request recommendations then please use the Discuss area on the web site - check out the "Local traders" Forum.</p><p>If you are a local trader, shop or someone offering a service then you would be very welcome to have a listing on this web site. Please check out the criteria guidelines first before submitting your details via the "+add business listing" button.</p></div></div></div></div></div></div>';

  $export['ol_business_page_description'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Your business here?';
  $fe_block_boxes->format = 'panopoly_wysiwyg_text';
  $fe_block_boxes->machine_name = 'ol_business_your_business_here';
  $fe_block_boxes->body = '<p><strong>If you would like to advertise your business on these pages, please</strong> <a href="contact">get in touch</a>.</p>';

  $export['ol_business_your_business_here'] = $fe_block_boxes;

  return $export;
}
