<?php
/**
 * @file
 * openlocal_gallery.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function openlocal_gallery_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'ol_galleries';
  $page->task = 'page';
  $page->admin_title = 'Galleries';
  $page->admin_description = 'A list of all galleries.';
  $page->path = 'galleries';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Galleries',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_ol_galleries_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'ol_galleries';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Galleries',
    'panels_breadcrumbs_paths' => '',
    'panels_breadcrumbs_home' => 1,
  );
  $display = new panels_display();
  $display->layout = 'radix_bryant_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Galleries';
  $display->uuid = 'e02724e8-2617-4181-994e-245271707b53';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ba735952-fa79-4d9d-85a9-429e8eccdf4b';
    $pane->panel = 'contentmain';
    $pane->type = 'views_panes';
    $pane->subtype = 'openlocal_gallery-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'teaser',
      'widget_title' => '<none>',
      'items_per_page' => '',
      'exposed' => array(
        'sort_by' => NULL,
        'sort_order' => NULL,
      ),
      'use_pager' => 0,
      'pager_id' => '',
      'offset' => NULL,
      'link_to_view' => NULL,
      'more_link' => NULL,
      'path' => NULL,
      'view_settings' => 'fields',
      'header_type' => 'none',
      'override_title' => '',
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ba735952-fa79-4d9d-85a9-429e8eccdf4b';
    $display->content['new-ba735952-fa79-4d9d-85a9-429e8eccdf4b'] = $pane;
    $display->panels['contentmain'][0] = 'new-ba735952-fa79-4d9d-85a9-429e8eccdf4b';
    $pane = new stdClass();
    $pane->pid = 'new-1b83dd13-6398-49bb-92d0-c46fc2cbddf5';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'block-9';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1b83dd13-6398-49bb-92d0-c46fc2cbddf5';
    $display->content['new-1b83dd13-6398-49bb-92d0-c46fc2cbddf5'] = $pane;
    $display->panels['sidebar'][0] = 'new-1b83dd13-6398-49bb-92d0-c46fc2cbddf5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ba735952-fa79-4d9d-85a9-429e8eccdf4b';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['ol_galleries'] = $page;

  return $pages;

}
