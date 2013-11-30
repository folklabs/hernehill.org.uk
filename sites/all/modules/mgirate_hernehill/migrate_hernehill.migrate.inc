<?php

/**
 * @file
 * Because the name of this file is the module name plus '.migrate.inc', when
 * hook_migrate_api is invoked by the Migrate module this file is automatically
 * loaded - thus, you don't need to implement your hook in the .module file.
 */


/*
 * You must implement hook_migrate_api(), setting the API level to 2, if you are
 * implementing any migration classes. If your migration application is static -
 * that is, you know at implementation time exactly what migrations must be
 * instantiated - then you should register your migrations here. If your
 * application is more dynamic (for example, if selections in the UI determine
 * exactly what migrations need to be instantiated), then you would register
 * your migrations using registerMigration() - see migrate_example_baseball for
 * more information.
 */
function migrate_hernehill_migrate_api() {
  // Usually field mappings are established by code in the migration constructor -
  // a call to addFieldMapping(). They may also be passed as arguments when
  // registering a migration - in this case, they are stored in the database
  // and override any mappings for the same field in the code. To do this,
  // construct the field mapping object and configure it similarly to when
  // you call addFieldMapping, and pass your mappings as an array below.
  // $translate_mapping = new MigrateFieldMapping('translate', NULL);
  // $translate_mapping->defaultValue(0);
  // $ignore_mapping = new MigrateFieldMapping('migrate_example_beer_styles:ignore_case', NULL);
  // $ignore_mapping->defaultValue(1);

  $api = array(
    // Required - tells the Migrate module that you are implementing version 2
    // of the Migrate API.
    'api' => 2,
    // Migrations can be organized into groups. The key used here will be the
    // machine name of the group, which can be used in Drush:
    //  drush migrate-import --group=wine
    // The title is a required argument which is displayed for the group in the
    // UI. You may also have additional arguments for any other data which is
    // common to all migrations in the group.
    'groups' => array(
      'hernehill_comments' => array(
        'title' => t('hernehill Comment nodes'),
      ),
    ),

    // Here we register the individual migrations. The keys (BeerTerm, BeerUser,
    // etc.) are the machine names of the migrations, and the class_name
    // argument is required. The group_name is optional (defaulting to 'default')
    // but specifying it is a best practice.
    'migrations' => array(
      'HHGroupCommentNode' => array(
        'class_name' => 'HHGroupCommentNodeMigration',
        'group_name' => 'hernehill_comments',
      ),
      'HHCampaignsCommentNode' => array(
        'class_name' => 'HHCampaignsCommentNodeMigration',
        'group_name' => 'hernehill_comments',
      ),
      'HHEventCommentNode' => array(
        'class_name' => 'HHEventCommentNodeMigration',
        'group_name' => 'hernehill_comments',
      ),
      'HHNewsCommentNode' => array(
        'class_name' => 'HHNewsCommentNodeMigration',
        'group_name' => 'hernehill_comments',
      ),
    ),
  );
  return $api;
}
