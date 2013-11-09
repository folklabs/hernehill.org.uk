<?php
/**
 * @file
 * openlocal_news.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function openlocal_news_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'OpenLocal News actions';
  $fe_block_boxes->format = 'panopoly_wysiwyg_text';
  $fe_block_boxes->machine_name = 'ol_news_actions';
  $fe_block_boxes->body = '<p><a href="node/add/openlocal-news-article">Add news article</a></p>';

  $export['ol_news_actions'] = $fe_block_boxes;

  return $export;
}
