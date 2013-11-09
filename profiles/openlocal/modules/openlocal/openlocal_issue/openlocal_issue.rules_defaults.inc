<?php
/**
 * @file
 * openlocal_issue.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function openlocal_issue_default_rules_configuration() {
  $items = array();
  $items['rules_ol_issue_update_notify'] = entity_import('rules_config', '{ "rules_ol_issue_update_notify" : {
      "LABEL" : "OL Issue: update notify",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "openlocal" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--ol_issue" : { "bundle" : "ol_issue" } },
      "DO" : [
        { "mail" : {
            "to" : [ "node:author:mail" ],
            "subject" : "[site:name]: Issue update: [node:title]",
            "message" : "See [node:url].",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
