<?php
/**
 * @file
 * panopoly_faq_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function panopoly_faq_page_default_page_manager_pages() {
  // $page = new stdClass();
  // $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  // $page->api_version = 1;
  // $page->name = 'faq';
  // $page->task = 'page';
  // $page->admin_title = 'FAQ';
  // $page->admin_description = '';
  // $page->path = 'faq';
  // $page->access = array();
  // $page->menu = array();
  // $page->arguments = array();
  // $page->conf = array(
  //   'admin_paths' => FALSE,
  // );
  // $page->default_handlers = array();
  // $handler = new stdClass();
  // $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  // $handler->api_version = 1;
  // $handler->name = 'page_faq_panel_context';
  // $handler->task = 'page';
  // $handler->subtask = 'faq';
  // $handler->handler = 'panel_context';
  // $handler->weight = 0;
  // $handler->conf = array(
  //   'title' => 'Panel',
  //   'no_blocks' => 0,
  //   'pipeline' => 'standard',
  //   'body_classes_to_remove' => '',
  //   'body_classes_to_add' => '',
  //   'css_id' => '',
  //   'css' => '',
  //   'contexts' => array(),
  //   'relationships' => array(),
  // );
  // $display = new panels_display();
  // $display->layout = 'boxton';
  // $display->layout_settings = array();
  // $display->panel_settings = array(
  //   'style_settings' => array(
  //     'default' => NULL,
  //     'contentmain' => NULL,
  //   ),
  // );
  // $display->cache = array();
  // $display->title = 'FAQ';
  // $display->content = array();
  // $display->panels = array();
  //   $pane = new stdClass();
  //   $pane->pid = 'new-1';
  //   $pane->panel = 'contentmain';
  //   $pane->type = 'views_panes';
  //   $pane->subtype = 'faq-all_faq_groups';
  //   $pane->shown = TRUE;
  //   $pane->access = array();
  //   $pane->configuration = array(
  //     'view_mode' => 'teaser',
  //     'widget_title' => NULL,
  //     'items_per_page' => NULL,
  //     'exposed' => array(
  //       'sort_by' => NULL,
  //       'sort_order' => NULL,
  //     ),
  //     'use_pager' => NULL,
  //     'pager_id' => NULL,
  //     'offset' => NULL,
  //     'link_to_view' => NULL,
  //     'more_link' => NULL,
  //     'path' => NULL,
  //     'view_settings' => 'fields',
  //     'header_type' => 'none',
  //   );
  //   $pane->cache = array();
  //   $pane->style = array(
  //     'settings' => NULL,
  //   );
  //   $pane->css = array();
  //   $pane->extras = array();
  //   $pane->position = 0;
  //   $pane->locks = array();
  //   $display->content['new-1'] = $pane;
  //   $display->panels['contentmain'][0] = 'new-1';
  // $display->hide_title = PANELS_TITLE_FIXED;
  // $display->title_pane = 'new-1';
  // $handler->conf['display'] = $display;
  // $page->default_handlers[$handler->name] = $handler;
  // $pages['faq'] = $page;

  // return $pages;


  $page = new stdClass();
$page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
$page->api_version = 1;
$page->name = 'faq';
$page->task = 'page';
$page->admin_title = 'FAQ';
$page->admin_description = '';
$page->path = 'faq';
$page->access = array();
$page->menu = array();
$page->arguments = array();
$page->conf = array(
  'admin_paths' => FALSE,
);
$page->default_handlers = array();
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'page_faq_panel_context';
$handler->task = 'page';
$handler->subtask = 'faq';
$handler->handler = 'panel_context';
$handler->weight = 0;
$handler->conf = array(
  'title' => 'Panel',
  'no_blocks' => 0,
  'pipeline' => 'standard',
  'body_classes_to_remove' => '',
  'body_classes_to_add' => '',
  'css_id' => '',
  'css' => '',
  'contexts' => array(),
  'relationships' => array(),
);
$display = new panels_display();
$display->layout = 'boxton';
$display->layout_settings = array();
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'contentmain' => NULL,
  ),
);
$display->cache = array();
$display->title = 'FAQ';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1';
  $pane->panel = 'contentmain';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'fpid:5';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer nodes',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer faq',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $pane->configuration = array(
    'view_mode' => 'Full',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $display->content['new-1'] = $pane;
  $display->panels['contentmain'][0] = 'new-1';
  $pane = new stdClass();
  $pane->pid = 'new-2';
  $pane->panel = 'contentmain';
  $pane->type = 'views_panes';
  $pane->subtype = 'faq-all_faq_groups';
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
  $pane->position = 1;
  $pane->locks = array();
  $display->content['new-2'] = $pane;
  $display->panels['contentmain'][1] = 'new-2';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = 'new-2';
$handler->conf['display'] = $display;
$page->default_handlers[$handler->name] = $handler;
$pages['faq'] = $page;

return $pages;

}