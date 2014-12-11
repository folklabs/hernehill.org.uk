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
  $handler->name = 'page_services_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'services';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
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
  $display->layout = 'radix_harris';
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
  $display->uuid = 'b8adfd2f-7b45-4321-b43b-d2f1c1eea737';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e82f6a5f-0324-4688-aa4b-e8204ecb815c';
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
    $pane->uuid = 'e82f6a5f-0324-4688-aa4b-e8204ecb815c';
    $display->content['new-e82f6a5f-0324-4688-aa4b-e8204ecb815c'] = $pane;
    $display->panels['column1'][0] = 'new-e82f6a5f-0324-4688-aa4b-e8204ecb815c';
    $pane = new stdClass();
    $pane->pid = 'new-f990ddeb-bedf-45ab-a31b-8dd9f2302610';
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
    $pane->uuid = 'f990ddeb-bedf-45ab-a31b-8dd9f2302610';
    $display->content['new-f990ddeb-bedf-45ab-a31b-8dd9f2302610'] = $pane;
    $display->panels['column1'][1] = 'new-f990ddeb-bedf-45ab-a31b-8dd9f2302610';
    $pane = new stdClass();
    $pane->pid = 'new-dc58544c-8400-40f4-8381-ef508eff8987';
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
    $pane->uuid = 'dc58544c-8400-40f4-8381-ef508eff8987';
    $display->content['new-dc58544c-8400-40f4-8381-ef508eff8987'] = $pane;
    $display->panels['column1'][2] = 'new-dc58544c-8400-40f4-8381-ef508eff8987';
    $pane = new stdClass();
    $pane->pid = 'new-19b0efcb-d5a0-4a6e-92b1-3491c40818f7';
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
    $pane->uuid = '19b0efcb-d5a0-4a6e-92b1-3491c40818f7';
    $display->content['new-19b0efcb-d5a0-4a6e-92b1-3491c40818f7'] = $pane;
    $display->panels['column2'][0] = 'new-19b0efcb-d5a0-4a6e-92b1-3491c40818f7';
    $pane = new stdClass();
    $pane->pid = 'new-d104ae1b-73c1-4b44-945e-488c45ca0cd0';
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
    $pane->uuid = 'd104ae1b-73c1-4b44-945e-488c45ca0cd0';
    $display->content['new-d104ae1b-73c1-4b44-945e-488c45ca0cd0'] = $pane;
    $display->panels['column2'][1] = 'new-d104ae1b-73c1-4b44-945e-488c45ca0cd0';
    $pane = new stdClass();
    $pane->pid = 'new-de28df7d-8eaf-4443-b499-9c54cc64c272';
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
    $pane->uuid = 'de28df7d-8eaf-4443-b499-9c54cc64c272';
    $display->content['new-de28df7d-8eaf-4443-b499-9c54cc64c272'] = $pane;
    $display->panels['column2'][2] = 'new-de28df7d-8eaf-4443-b499-9c54cc64c272';
    $pane = new stdClass();
    $pane->pid = 'new-0dfe9f57-731f-4778-b0fc-e2c8760942c4';
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
    $pane->uuid = '0dfe9f57-731f-4778-b0fc-e2c8760942c4';
    $display->content['new-0dfe9f57-731f-4778-b0fc-e2c8760942c4'] = $pane;
    $display->panels['contentmain'][0] = 'new-0dfe9f57-731f-4778-b0fc-e2c8760942c4';
    $pane = new stdClass();
    $pane->pid = 'new-ffd9dbcd-25ad-4e8b-a028-b61826855042';
    $pane->panel = 'header';
    $pane->type = 'block';
    $pane->subtype = 'block-13';
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
    $pane->uuid = 'ffd9dbcd-25ad-4e8b-a028-b61826855042';
    $display->content['new-ffd9dbcd-25ad-4e8b-a028-b61826855042'] = $pane;
    $display->panels['header'][0] = 'new-ffd9dbcd-25ad-4e8b-a028-b61826855042';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_services_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'services';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
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
  $display->layout = 'radix_harris';
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
  $display->uuid = '83259497-8868-41a9-a944-49578286381a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a16644a0-be7b-47c3-8e42-cefd550981b1';
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
    $pane->uuid = 'a16644a0-be7b-47c3-8e42-cefd550981b1';
    $display->content['new-a16644a0-be7b-47c3-8e42-cefd550981b1'] = $pane;
    $display->panels['column1'][0] = 'new-a16644a0-be7b-47c3-8e42-cefd550981b1';
    $pane = new stdClass();
    $pane->pid = 'new-e58d2d94-4e94-4e3e-b3df-25c2d4a418e0';
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
    $pane->uuid = 'e58d2d94-4e94-4e3e-b3df-25c2d4a418e0';
    $display->content['new-e58d2d94-4e94-4e3e-b3df-25c2d4a418e0'] = $pane;
    $display->panels['column2'][0] = 'new-e58d2d94-4e94-4e3e-b3df-25c2d4a418e0';
    $pane = new stdClass();
    $pane->pid = 'new-295884a2-f828-4cc5-80d3-ccbc38e5ec9a';
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
    $pane->uuid = '295884a2-f828-4cc5-80d3-ccbc38e5ec9a';
    $display->content['new-295884a2-f828-4cc5-80d3-ccbc38e5ec9a'] = $pane;
    $display->panels['column2'][1] = 'new-295884a2-f828-4cc5-80d3-ccbc38e5ec9a';
    $pane = new stdClass();
    $pane->pid = 'new-701aa93d-5c15-4385-b2d9-757adcfc72e2';
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
    $pane->uuid = '701aa93d-5c15-4385-b2d9-757adcfc72e2';
    $display->content['new-701aa93d-5c15-4385-b2d9-757adcfc72e2'] = $pane;
    $display->panels['column2'][2] = 'new-701aa93d-5c15-4385-b2d9-757adcfc72e2';
    $pane = new stdClass();
    $pane->pid = 'new-d224b5b4-311a-4c8f-a43a-d71a4705601a';
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
    $pane->uuid = 'd224b5b4-311a-4c8f-a43a-d71a4705601a';
    $display->content['new-d224b5b4-311a-4c8f-a43a-d71a4705601a'] = $pane;
    $display->panels['contentmain'][0] = 'new-d224b5b4-311a-4c8f-a43a-d71a4705601a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['services'] = $page;

  return $pages;

}
