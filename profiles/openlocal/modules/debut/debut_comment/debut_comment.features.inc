<?php
/**
 * @file
 * debut_comment.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function debut_comment_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}