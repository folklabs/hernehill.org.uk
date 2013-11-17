<?php
/**
 * @file
 * openlocal_core.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function openlocal_core_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer panelizer node ol_place breadcrumbs.
  $permissions['administer panelizer node ol_place breadcrumbs'] = array(
    'name' => 'administer panelizer node ol_place breadcrumbs',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node ol_place content.
  $permissions['administer panelizer node ol_place content'] = array(
    'name' => 'administer panelizer node ol_place content',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node ol_place context.
  $permissions['administer panelizer node ol_place context'] = array(
    'name' => 'administer panelizer node ol_place context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node ol_place defaults.
  $permissions['administer panelizer node ol_place defaults'] = array(
    'name' => 'administer panelizer node ol_place defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node ol_place layout.
  $permissions['administer panelizer node ol_place layout'] = array(
    'name' => 'administer panelizer node ol_place layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node ol_place overview.
  $permissions['administer panelizer node ol_place overview'] = array(
    'name' => 'administer panelizer node ol_place overview',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node ol_place settings.
  $permissions['administer panelizer node ol_place settings'] = array(
    'name' => 'administer panelizer node ol_place settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: create ol_place content.
  $permissions['create ol_place content'] = array(
    'name' => 'create ol_place content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'contributor' => 'contributor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any ol_place content.
  $permissions['delete any ol_place content'] = array(
    'name' => 'delete any ol_place content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own ol_place content.
  $permissions['delete own ol_place content'] = array(
    'name' => 'delete own ol_place content',
    'roles' => array(
      'contributor' => 'contributor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any ol_place content.
  $permissions['edit any ol_place content'] = array(
    'name' => 'edit any ol_place content',
    'roles' => array(
      'contributor' => 'contributor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own ol_place content.
  $permissions['edit own ol_place content'] = array(
    'name' => 'edit own ol_place content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'contributor' => 'contributor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
