<?php
/**
 * @file
 * openlocal_business.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function openlocal_business_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'services';
  $page->task = 'page';
  $page->admin_title = 'Services';
  $page->admin_description = '';
  $page->path = 'services/list/!term';
  $page->access = array();
  $page->menu = array(
    'type' => 'default tab',
    'title' => 'List',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Services',
      'name' => 'main-menu',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'term' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_services_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'services';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Filter',
    'no_blocks' => 1,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'harris';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Services';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'column1';
    $pane->type = 'views_panes';
    $pane->subtype = 'openlocal_business_categories-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'teaser',
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
      'view_settings' => 'fields',
      'header_type' => 'none',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'ol-2nd-nav-menu',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['column1'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'column2';
    $pane->type = 'block';
    $pane->subtype = 'block-2';
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
    $display->content['new-2'] = $pane;
    $display->panels['column2'][0] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'column2';
    $pane->type = 'block';
    $pane->subtype = 'block-7';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Your business here?',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-3'] = $pane;
    $display->panels['column2'][1] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'column2';
    $pane->type = 'views_panes';
    $pane->subtype = 'openlocal_business-panel_pane_4';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'fields_override' => array(
        'field_ol_business_category' => 1,
        'field_featured_image' => 1,
        'title' => 1,
        'field_ol_description' => 1,
      ),
      'context' => array(
        0 => 'empty',
      ),
      'view_mode' => 'teaser',
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
      'view_settings' => 'fields',
      'header_type' => 'none',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-4'] = $pane;
    $display->panels['column2'][2] = 'new-4';
    $pane = new stdClass();
    $pane->pid = 'new-5';
    $pane->panel = 'contentmain';
    $pane->type = 'views_panes';
    $pane->subtype = 'openlocal_business-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'fields_override' => array(
        'field_ol_business_category' => 1,
        'field_featured_image' => 1,
        'title' => 1,
        'field_ol_description' => 1,
      ),
      'view_mode' => 'teaser',
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
      'view_settings' => 'fields',
      'header_type' => 'none',
      'context' => array(
        0 => 'argument_term_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-5'] = $pane;
    $display->panels['contentmain'][0] = 'new-5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_services_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'services';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Facet search',
    'no_blocks' => 1,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'harris';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Services';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6';
    $pane->panel = 'column1';
    $pane->type = 'block';
    $pane->subtype = 'current_search-openlocal_current_search';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
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
    $display->content['new-6'] = $pane;
    $display->panels['column1'][0] = 'new-6';
    $pane = new stdClass();
    $pane->pid = 'new-7';
    $pane->panel = 'column1';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-92S7jjLVNm4mHAmafCXgP2s7x0qBWf9j';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_string_1',
      'override_title' => 0,
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
    $display->content['new-7'] = $pane;
    $display->panels['column1'][1] = 'new-7';
    $pane = new stdClass();
    $pane->pid = 'new-8';
    $pane->panel = 'column1';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-suVg0EF82TRmk1BIlyr5vF5kF0QvcXxt';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_string_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-8'] = $pane;
    $display->panels['column1'][2] = 'new-8';
    $pane = new stdClass();
    $pane->pid = 'new-9';
    $pane->panel = 'column2';
    $pane->type = 'block';
    $pane->subtype = 'block-2';
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
    $display->content['new-9'] = $pane;
    $display->panels['column2'][0] = 'new-9';
    $pane = new stdClass();
    $pane->pid = 'new-10';
    $pane->panel = 'column2';
    $pane->type = 'block';
    $pane->subtype = 'block-7';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Your business here?',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-10'] = $pane;
    $display->panels['column2'][1] = 'new-10';
    $pane = new stdClass();
    $pane->pid = 'new-11';
    $pane->panel = 'column2';
    $pane->type = 'views_panes';
    $pane->subtype = 'openlocal_business-panel_pane_4';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'fields_override' => array(
        'field_ol_business_category' => 1,
        'field_featured_image' => 1,
        'title' => 1,
        'field_ol_description' => 1,
      ),
      'context' => array(
        0 => 'empty',
      ),
      'view_mode' => 'teaser',
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
      'view_settings' => 'fields',
      'header_type' => 'none',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-11'] = $pane;
    $display->panels['column2'][2] = 'new-11';
    $pane = new stdClass();
    $pane->pid = 'new-12';
    $pane->panel = 'contentmain';
    $pane->type = 'views_panes';
    $pane->subtype = 'openlocal_business_facet_search-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'teaser',
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
      'view_settings' => 'fields',
      'header_type' => 'none',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-12'] = $pane;
    $display->panels['contentmain'][0] = 'new-12';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['services'] = $page;

  return $pages;

}
