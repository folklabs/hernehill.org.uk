<?php
/**
 * @file
 * openlocal_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function openlocal_gallery_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function openlocal_gallery_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function openlocal_gallery_node_info() {
  $items = array(
    'ol_gallery' => array(
      'name' => t('Gallery'),
      'base' => 'node_content',
      'description' => t('An image/media gallery.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
