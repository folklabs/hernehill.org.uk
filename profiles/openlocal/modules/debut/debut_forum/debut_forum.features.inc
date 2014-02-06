<?php
/**
 * @file
 * debut_forum.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function debut_forum_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function debut_forum_views_api() {
  return array("api" => "3.0");
}
