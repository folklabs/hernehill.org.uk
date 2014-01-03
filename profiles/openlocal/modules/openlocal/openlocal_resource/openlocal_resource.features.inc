<?php
/**
 * @file
 * openlocal_resource.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function openlocal_resource_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function openlocal_resource_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function openlocal_resource_node_info() {
  $items = array(
    'ol_resource' => array(
      'name' => t('Resource'),
      'base' => 'node_content',
      'description' => t('A link to an external website or other information.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
