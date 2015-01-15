<?php
/**
 * @file
 * openlocal_user.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function openlocal_user_default_rules_configuration() {
  $items = array();
  $items['rules_ol_user_new_user_notification'] = entity_import('rules_config', '{ "rules_ol_user_new_user_notification" : {
      "LABEL" : "OL User: new user notification",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "openlocal" ],
      "REQUIRES" : [ "rules", "logintoboggan_rules" ],
      "ON" : { "logintoboggan_validated" : [] },
      "DO" : [
        { "mail" : {
            "to" : "[site:mail]",
            "subject" : "[site:name]: New user registered: [account:name]",
            "message" : "[account:url]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
