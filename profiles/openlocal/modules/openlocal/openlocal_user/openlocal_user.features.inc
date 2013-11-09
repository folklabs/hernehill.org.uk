<?php
/**
 * @file
 * openlocal_user.features.inc
 */

/**
 * Implements hook_default_profile2_type().
 */
function openlocal_user_default_profile2_type() {
  $items = array();
  $items['ol_personal_info'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "ol_personal_info",
    "label" : "Personal info",
    "weight" : "0",
    "data" : { "registration" : 1 }
  }');
  return $items;
}
