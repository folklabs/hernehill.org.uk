<?php
/**
 * @file
 * openlocal_gallery.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function openlocal_gallery_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:ol_gallery:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'ol_gallery';
  $panelizer->no_blocks = TRUE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array(
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Galleries
%node:title',
    'panels_breadcrumbs_paths' => 'galleries',
    'panels_breadcrumbs_home' => 1,
  );
  $display = new panels_display();
  $display->layout = 'radix_bryant_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '7b3c3b9f-db1b-4d21-95e2-e44b83a34c4a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-812e47ed-ff5d-4f46-a1bd-1bb7aeb44a03';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_ol_details';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => array(),
      'override_title' => 0,
      'override_title_text' => '',
      'view_mode' => NULL,
      'widget_title' => NULL,
      'items_per_page' => NULL,
      'exposed' => array(
        'sort_by' => NULL,
        'sort_order' => NULL,
      ),
      'use_pager' => NULL,
      'pager_id' => NULL,
      'offset' => NULL,
      'link_to_view' => NULL,
      'more_link' => NULL,
      'path' => NULL,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '812e47ed-ff5d-4f46-a1bd-1bb7aeb44a03';
    $display->content['new-812e47ed-ff5d-4f46-a1bd-1bb7aeb44a03'] = $pane;
    $display->panels['contentmain'][0] = 'new-812e47ed-ff5d-4f46-a1bd-1bb7aeb44a03';
    $pane = new stdClass();
    $pane->pid = 'new-8aea17eb-75aa-4b64-a762-eb1c1581379e';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_ol_gallery_images';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'colorbox',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'colorbox_node_style' => 'openlocal_panel_deep',
        'colorbox_image_style' => '',
        'colorbox_gallery' => 'page',
        'colorbox_gallery_custom' => '',
        'colorbox_caption' => 'title',
        'colorbox_caption_custom' => '',
        'colorbox_multivalue_index' => NULL,
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
      'view_mode' => NULL,
      'widget_title' => NULL,
      'items_per_page' => NULL,
      'exposed' => array(
        'sort_by' => NULL,
        'sort_order' => NULL,
      ),
      'use_pager' => NULL,
      'pager_id' => NULL,
      'offset' => NULL,
      'link_to_view' => NULL,
      'more_link' => NULL,
      'path' => NULL,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8aea17eb-75aa-4b64-a762-eb1c1581379e';
    $display->content['new-8aea17eb-75aa-4b64-a762-eb1c1581379e'] = $pane;
    $display->panels['contentmain'][1] = 'new-8aea17eb-75aa-4b64-a762-eb1c1581379e';
    $pane = new stdClass();
    $pane->pid = 'new-ddb96cbc-f2e9-4654-9f22-c94f4905126f';
    $pane->panel = 'contentmain';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => FALSE,
      'override_title_text' => '',
      'build_mode' => 'page_manager',
      'identifier' => '',
      'link' => TRUE,
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_class' => 'link-wrapper',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ddb96cbc-f2e9-4654-9f22-c94f4905126f';
    $display->content['new-ddb96cbc-f2e9-4654-9f22-c94f4905126f'] = $pane;
    $display->panels['contentmain'][2] = 'new-ddb96cbc-f2e9-4654-9f22-c94f4905126f';
    $pane = new stdClass();
    $pane->pid = 'new-f96c6517-cae7-471c-9736-478c180a8a90';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:og_group_ref';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'og_list_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f96c6517-cae7-471c-9736-478c180a8a90';
    $display->content['new-f96c6517-cae7-471c-9736-478c180a8a90'] = $pane;
    $display->panels['sidebar'][0] = 'new-f96c6517-cae7-471c-9736-478c180a8a90';
    $pane = new stdClass();
    $pane->pid = 'new-80eab4c4-73b8-442f-a6b8-695bbff4f9cc';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '80eab4c4-73b8-442f-a6b8-695bbff4f9cc';
    $display->content['new-80eab4c4-73b8-442f-a6b8-695bbff4f9cc'] = $pane;
    $display->panels['sidebar'][1] = 'new-80eab4c4-73b8-442f-a6b8-695bbff4f9cc';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ddb96cbc-f2e9-4654-9f22-c94f4905126f';
  $panelizer->display = $display;
  $export['node:ol_gallery:default'] = $panelizer;

  return $export;
}
