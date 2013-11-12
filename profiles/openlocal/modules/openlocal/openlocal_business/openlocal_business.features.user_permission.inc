<?php
/**
 * @file
 * openlocal_business.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function openlocal_business_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer panelizer node ol_business breadcrumbs.
  $permissions['administer panelizer node ol_business breadcrumbs'] = array(
    'name' => 'administer panelizer node ol_business breadcrumbs',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node ol_business content.
  $permissions['administer panelizer node ol_business content'] = array(
    'name' => 'administer panelizer node ol_business content',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node ol_business context.
  $permissions['administer panelizer node ol_business context'] = array(
    'name' => 'administer panelizer node ol_business context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node ol_business defaults.
  $permissions['administer panelizer node ol_business defaults'] = array(
    'name' => 'administer panelizer node ol_business defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node ol_business layout.
  $permissions['administer panelizer node ol_business layout'] = array(
    'name' => 'administer panelizer node ol_business layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node ol_business overview.
  $permissions['administer panelizer node ol_business overview'] = array(
    'name' => 'administer panelizer node ol_business overview',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node ol_business settings.
  $permissions['administer panelizer node ol_business settings'] = array(
    'name' => 'administer panelizer node ol_business settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: create ol_business content.
  $permissions['create ol_business content'] = array(
    'name' => 'create ol_business content',
    'roles' => array(
      'editor' => 'editor',
      'trader' => 'trader',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any ol_business content.
  $permissions['delete any ol_business content'] = array(
    'name' => 'delete any ol_business content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own ol_business content.
  $permissions['delete own ol_business content'] = array(
    'name' => 'delete own ol_business content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in 4.
  $permissions['delete terms in 4'] = array(
    'name' => 'delete terms in 4',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 5.
  $permissions['delete terms in 5'] = array(
    'name' => 'delete terms in 5',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any ol_business content.
  $permissions['edit any ol_business content'] = array(
    'name' => 'edit any ol_business content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own ol_business content.
  $permissions['edit own ol_business content'] = array(
    'name' => 'edit own ol_business content',
    'roles' => array(
      'editor' => 'editor',
      'trader' => 'trader',
    ),
    'module' => 'node',
  );

  // Exported permission: edit terms in 4.
  $permissions['edit terms in 4'] = array(
    'name' => 'edit terms in 4',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 5.
  $permissions['edit terms in 5'] = array(
    'name' => 'edit terms in 5',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
