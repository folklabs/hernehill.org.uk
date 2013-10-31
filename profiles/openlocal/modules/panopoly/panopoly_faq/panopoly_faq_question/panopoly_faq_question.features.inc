<?php
/**
 * @file
 * panopoly_faq_question.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function panopoly_faq_question_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "panelizer" && $api == "panelizer") {
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
function panopoly_faq_question_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function panopoly_faq_question_node_info() {
  $items = array(
    'faq' => array(
      'name' => t('FAQ'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Administrative title'),
      'help' => '',
    ),
  );
  return $items;
}
