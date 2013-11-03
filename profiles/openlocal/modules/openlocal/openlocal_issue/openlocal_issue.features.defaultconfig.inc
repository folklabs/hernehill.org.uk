<?php
/**
 * @file
 * openlocal_issue.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function openlocal_issue_defaultconfig_features() {
  return array(
    'openlocal_issue' => array(
      'panelizer_defaults' => 'panelizer_defaults',
    ),
  );
}

/**
 * Implements hook_defaultconfig_panelizer_defaults().
 */
function openlocal_issue_defaultconfig_panelizer_defaults() {
  $export = array();

  return $export;
}
