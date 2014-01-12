<?php
/**
 * @file
 * openlocal_event_help.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function openlocal_event_help_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "bootstrap_tour" && $api == "bootstrap_tour_tour") {
    return array("version" => "1");
  }
}
