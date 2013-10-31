<?php
/**
 * @file
 * panopoly_faq_question.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function panopoly_faq_question_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'faq';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'FAQ';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['class'] = 'faq-list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_faq_group_node']['id'] = 'reverse_field_faq_group_node';
  $handler->display->display_options['relationships']['reverse_field_faq_group_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_faq_group_node']['field'] = 'reverse_field_faq_group_node';
  $handler->display->display_options['relationships']['reverse_field_faq_group_node']['label'] = 'content with term';
  $handler->display->display_options['relationships']['reverse_field_faq_group_node']['required'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: FAQ Question */
  $handler->display->display_options['fields']['field_faq_question']['id'] = 'field_faq_question';
  $handler->display->display_options['fields']['field_faq_question']['table'] = 'field_data_field_faq_question';
  $handler->display->display_options['fields']['field_faq_question']['field'] = 'field_faq_question';
  $handler->display->display_options['fields']['field_faq_question']['relationship'] = 'reverse_field_faq_group_node';
  $handler->display->display_options['fields']['field_faq_question']['label'] = '';
  $handler->display->display_options['fields']['field_faq_question']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faq_question']['element_wrapper_class'] = 'question';
  /* Field: Content: FAQ Answer */
  $handler->display->display_options['fields']['field_faq_answer']['id'] = 'field_faq_answer';
  $handler->display->display_options['fields']['field_faq_answer']['table'] = 'field_data_field_faq_answer';
  $handler->display->display_options['fields']['field_faq_answer']['field'] = 'field_faq_answer';
  $handler->display->display_options['fields']['field_faq_answer']['relationship'] = 'reverse_field_faq_group_node';
  $handler->display->display_options['fields']['field_faq_answer']['label'] = '';
  $handler->display->display_options['fields']['field_faq_answer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faq_answer']['element_wrapper_class'] = 'answer';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'faq_group' => 'faq_group',
  );


/* Display: All FAQ Groups */
$handler = $view->new_display('panel_pane', 'All FAQ Groups', 'all_faq_groups');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Draggableviews: Weight */
$handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
$handler->display->display_options['sorts']['weight_1']['table'] = 'draggableviews_structure';
$handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
$handler->display->display_options['sorts']['weight_1']['relationship'] = 'reverse_field_faq_group_node';
$handler->display->display_options['sorts']['weight_1']['draggableviews_setting_view'] = 'faq:faq_page_manage_order';
$handler->display->display_options['sorts']['weight_1']['draggableviews_setting_arguments_php'] = 'dsm($data);';
$handler->display->display_options['sorts']['weight_1']['draggableviews_setting_new_items_bottom_list'] = 1;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Taxonomy vocabulary: Machine name */
$handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
$handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
$handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
$handler->display->display_options['filters']['machine_name']['value'] = array(
  'faq_group' => 'faq_group',
);
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_faq_group_node';
$handler->display->display_options['filters']['type']['value'] = array(
  'faq' => 'faq',
);
/* Filter criterion: Taxonomy term: Show on FAQ page (field_show_on_faq_page) */
$handler->display->display_options['filters']['field_show_on_faq_page_value']['id'] = 'field_show_on_faq_page_value';
$handler->display->display_options['filters']['field_show_on_faq_page_value']['table'] = 'field_data_field_show_on_faq_page';
$handler->display->display_options['filters']['field_show_on_faq_page_value']['field'] = 'field_show_on_faq_page_value';
$handler->display->display_options['filters']['field_show_on_faq_page_value']['value'] = array(
  1 => '1',
);


  // /* Display: All FAQ Groups */
  // $handler = $view->new_display('panel_pane', 'All FAQ Groups', 'all_faq_groups');
  // $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  // $handler->display->display_options['defaults']['sorts'] = FALSE;
  // /* Sort criterion: Draggableviews: Weight */
  // $handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
  // $handler->display->display_options['sorts']['weight_1']['table'] = 'draggableviews_structure';
  // $handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
  // $handler->display->display_options['sorts']['weight_1']['relationship'] = 'reverse_field_faq_group_node';
  // $handler->display->display_options['sorts']['weight_1']['draggableviews_setting_view'] = 'faq:faq_page_manage_order';
  // $handler->display->display_options['sorts']['weight_1']['draggableviews_setting_arguments_php'] = 'dsm($data);';
  // $handler->display->display_options['sorts']['weight_1']['draggableviews_setting_new_items_bottom_list'] = 1;
  // $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  // $handler->display->display_options['defaults']['filters'] = FALSE;
  // /* Filter criterion: Taxonomy vocabulary: Machine name */
  // $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  // $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  // $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  // $handler->display->display_options['filters']['machine_name']['value'] = array(
  //   'faq_group' => 'faq_group',
  // );
  // /* Filter criterion: Content: Type */
  // $handler->display->display_options['filters']['type']['id'] = 'type';
  // $handler->display->display_options['filters']['type']['table'] = 'node';
  // $handler->display->display_options['filters']['type']['field'] = 'type';
  // $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_faq_group_node';
  // $handler->display->display_options['filters']['type']['value'] = array(
  //   'faq' => 'faq',
  // );
  // /* Filter criterion: Taxonomy term: Show on FAQ page (field_show_on_faq_page) */
  // $handler->display->display_options['filters']['field_show_on_faq_page_value']['id'] = 'field_show_on_faq_page_value';
  // $handler->display->display_options['filters']['field_show_on_faq_page_value']['table'] = 'field_data_field_show_on_faq_page';
  // $handler->display->display_options['filters']['field_show_on_faq_page_value']['field'] = 'field_show_on_faq_page_value';
  // $handler->display->display_options['filters']['field_show_on_faq_page_value']['value'] = array(
  //   1 => '1',
  // );

  /* Display: FAQ Group Renderer */
  $handler = $view->new_display('panel_pane', 'FAQ Group Renderer', 'faq_group_renderer');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['class'] = 'faq-list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: FAQ Question */
  $handler->display->display_options['fields']['field_faq_question']['id'] = 'field_faq_question';
  $handler->display->display_options['fields']['field_faq_question']['table'] = 'field_data_field_faq_question';
  $handler->display->display_options['fields']['field_faq_question']['field'] = 'field_faq_question';
  $handler->display->display_options['fields']['field_faq_question']['relationship'] = 'reverse_field_faq_group_node';
  $handler->display->display_options['fields']['field_faq_question']['label'] = '';
  $handler->display->display_options['fields']['field_faq_question']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faq_question']['element_wrapper_class'] = 'question';
  /* Field: Content: FAQ Answer */
  $handler->display->display_options['fields']['field_faq_answer']['id'] = 'field_faq_answer';
  $handler->display->display_options['fields']['field_faq_answer']['table'] = 'field_data_field_faq_answer';
  $handler->display->display_options['fields']['field_faq_answer']['field'] = 'field_faq_answer';
  $handler->display->display_options['fields']['field_faq_answer']['relationship'] = 'reverse_field_faq_group_node';
  $handler->display->display_options['fields']['field_faq_answer']['label'] = '';
  $handler->display->display_options['fields']['field_faq_answer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faq_answer']['element_wrapper_class'] = 'answer';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
  $handler->display->display_options['sorts']['weight_1']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight_1']['relationship'] = 'reverse_field_faq_group_node';
  $handler->display->display_options['sorts']['weight_1']['draggableviews_setting_view'] = 'faq:faq_manage_order';
  $handler->display->display_options['sorts']['weight_1']['draggableviews_setting_new_items_bottom_list'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'faq_group' => 'faq_group',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_faq_group_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'faq' => 'faq',
  );
  $handler->display->display_options['argument_input'] = array(
    'tid' => array(
      'type' => 'user',
      'context' => 'entity:commerce_customer_profile.commerce_customer_address',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Taxonomy term: Term ID',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';


/* Display: FAQ Manage Groups  */
$handler = $view->new_display('panel_pane', 'FAQ Manage Groups ', 'faq_manage_groups');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['query'] = FALSE;
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['class'] = 'faq-groups-list';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'tid' => 'tid',
  'name' => 'name',
  'nothing' => 'nothing',
);
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area1']['id'] = 'area';
$handler->display->display_options['header']['area1']['table'] = 'views';
$handler->display->display_options['header']['area1']['field'] = 'area';
$handler->display->display_options['header']['area1']['empty'] = TRUE;
$handler->display->display_options['header']['area1']['content'] = '<h3>FAQ Groupings</h3>';
$handler->display->display_options['header']['area1']['format'] = 'panopoly_wysiwyg_text';
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['empty'] = TRUE;
$handler->display->display_options['header']['area']['content'] = '<a href="/admin/structure/taxonomy/faq_group/add">Add new group</a>';
$handler->display->display_options['header']['area']['format'] = 'panopoly_wysiwyg_text';
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Footer: Global: Text area */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['content'] = '<a href="/admin/structure/faq/reorder/page?destination=/admin/structure/faq">Manage FAQ page ordering</a>';
$handler->display->display_options['footer']['area']['format'] = 'panopoly_wysiwyg_text';
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = '<div></div>';
$handler->display->display_options['empty']['area']['format'] = 'panopoly_wysiwyg_text';
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Entity Reference: Referencing entity */
$handler->display->display_options['relationships']['reverse_field_faq_group_node']['id'] = 'reverse_field_faq_group_node';
$handler->display->display_options['relationships']['reverse_field_faq_group_node']['table'] = 'taxonomy_term_data';
$handler->display->display_options['relationships']['reverse_field_faq_group_node']['field'] = 'reverse_field_faq_group_node';
$handler->display->display_options['relationships']['reverse_field_faq_group_node']['label'] = 'content with term';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Taxonomy term: Term ID */
$handler->display->display_options['fields']['tid']['id'] = 'tid';
$handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['tid']['field'] = 'tid';
$handler->display->display_options['fields']['tid']['label'] = '';
$handler->display->display_options['fields']['tid']['exclude'] = TRUE;
$handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['tid']['separator'] = '';
/* Field: Taxonomy term: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['name']['alter']['path'] = 'admin/structure/faq/[tid]';
$handler->display->display_options['fields']['name']['alter']['absolute'] = TRUE;
$handler->display->display_options['fields']['name']['alter']['path_case'] = 'lower';
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '     ( <a href ="/taxonomy/term/[tid]" >View Page</a> | <a href="/admin/structure/faq/[tid]">Edit FAQ</a> | <a href="/taxonomy/term/[tid]/edit">Edit Page Details</a> )';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;


  // /* Display: FAQ Manage Groups  */
  // $handler = $view->new_display('panel_pane', 'FAQ Manage Groups ', 'faq_manage_groups');
  // $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  // $handler->display->display_options['defaults']['query'] = FALSE;
  // $handler->display->display_options['query']['type'] = 'views_query';
  // $handler->display->display_options['query']['options']['distinct'] = TRUE;
  // $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  // $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  // $handler->display->display_options['style_plugin'] = 'list';
  // $handler->display->display_options['style_options']['class'] = 'faq-groups-list';
  // $handler->display->display_options['defaults']['style_options'] = FALSE;
  // $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  // $handler->display->display_options['row_plugin'] = 'fields';
  // $handler->display->display_options['defaults']['row_options'] = FALSE;
  // $handler->display->display_options['defaults']['header'] = FALSE;

  // $handler->display->display_options['header']['area1']['id'] = 'area';
  // $handler->display->display_options['header']['area1']['table'] = 'views';
  // $handler->display->display_options['header']['area1']['field'] = 'area';
  // $handler->display->display_options['header']['area1']['empty'] = TRUE;
  // $handler->display->display_options['header']['area1']['content'] = '<h3>FAQ Groupings</h3>';
  // $handler->display->display_options['header']['area1']['format'] = 'panopoly_wysiwyg_text';

  // /* Header: Global: Text area */
  // $handler->display->display_options['header']['area']['id'] = 'area';
  // $handler->display->display_options['header']['area']['table'] = 'views';
  // $handler->display->display_options['header']['area']['field'] = 'area';
  // $handler->display->display_options['header']['area']['empty'] = TRUE;
  // $handler->display->display_options['header']['area']['content'] = '<a href="/admin/structure/taxonomy/faq_group/add?destination=/admin/structure/faq">Add new group</a>';
  // $handler->display->display_options['header']['area']['format'] = 'panopoly_wysiwyg_text';
  // $handler->display->display_options['defaults']['footer'] = FALSE;
  // /* Footer: Global: Text area */
  // $handler->display->display_options['footer']['area']['id'] = 'area';
  // $handler->display->display_options['footer']['area']['table'] = 'views';
  // $handler->display->display_options['footer']['area']['field'] = 'area';
  // $handler->display->display_options['footer']['area']['content'] = '<a href="/admin/structure/faq/reorder/page?destination=/admin/structure/faq">Manage FAQ page ordering</a>';
  // $handler->display->display_options['footer']['area']['format'] = 'panopoly_wysiwyg_text';
  // $handler->display->display_options['defaults']['empty'] = FALSE;
  // /* No results behavior: Global: Text area */
  // $handler->display->display_options['empty']['area']['id'] = 'area';
  // $handler->display->display_options['empty']['area']['table'] = 'views';
  // $handler->display->display_options['empty']['area']['field'] = 'area';
  // $handler->display->display_options['empty']['area']['empty'] = TRUE;
  // $handler->display->display_options['empty']['area']['content'] = '<div></div>';
  // $handler->display->display_options['empty']['area']['format'] = 'panopoly_wysiwyg_text';
  // $handler->display->display_options['defaults']['relationships'] = FALSE;
  // /* Relationship: Entity Reference: Referencing entity */
  // $handler->display->display_options['relationships']['reverse_field_faq_group_node']['id'] = 'reverse_field_faq_group_node';
  // $handler->display->display_options['relationships']['reverse_field_faq_group_node']['table'] = 'taxonomy_term_data';
  // $handler->display->display_options['relationships']['reverse_field_faq_group_node']['field'] = 'reverse_field_faq_group_node';
  // $handler->display->display_options['relationships']['reverse_field_faq_group_node']['label'] = 'content with term';
  // $handler->display->display_options['defaults']['fields'] = FALSE;
  // /* Field: Taxonomy term: Term ID */
  // $handler->display->display_options['fields']['tid']['id'] = 'tid';
  // $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  // $handler->display->display_options['fields']['tid']['field'] = 'tid';
  // $handler->display->display_options['fields']['tid']['label'] = '';
  // $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  // $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  // $handler->display->display_options['fields']['tid']['separator'] = '';
  // /* Field: Taxonomy term: Name */
  // $handler->display->display_options['fields']['name']['id'] = 'name';
  // $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  // $handler->display->display_options['fields']['name']['field'] = 'name';
  // $handler->display->display_options['fields']['name']['label'] = '';
  // $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  // $handler->display->display_options['fields']['name']['alter']['path'] = 'admin/structure/faq/[tid]';
  // $handler->display->display_options['fields']['name']['alter']['absolute'] = TRUE;
  // $handler->display->display_options['fields']['name']['alter']['path_case'] = 'lower';
  // $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;






  /* Display: FAQ Manage Questions */
$handler = $view->new_display('panel_pane', 'FAQ Manage Questions', 'faq_manage_questions');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['empty'] = TRUE;
$handler->display->display_options['header']['area']['content'] = '<a href="/node/add/faq?field_faq_group=!1">Add new question</a>';
$handler->display->display_options['header']['area']['format'] = 'panopoly_wysiwyg_text';
$handler->display->display_options['header']['area']['tokenize'] = TRUE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area_1']['id'] = 'area_1';
$handler->display->display_options['header']['area_1']['table'] = 'views';
$handler->display->display_options['header']['area_1']['field'] = 'area';
$handler->display->display_options['header']['area_1']['content'] = '<a href="/admin/structure/faq/reorder/[tid]?destination=/admin/structure/faq/[tid]">Manage Questions and Ordering</a>';
$handler->display->display_options['header']['area_1']['format'] = 'panopoly_wysiwyg_text';
$handler->display->display_options['header']['area_1']['tokenize'] = TRUE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area_2']['id'] = 'area_1';
$handler->display->display_options['header']['area_2']['table'] = 'views';
$handler->display->display_options['header']['area_2']['field'] = 'area';
$handler->display->display_options['header']['area_2']['content'] = '<a href="/taxonomy/term/[tid]/edit">Edit FAQ Page Details</a>';
$handler->display->display_options['header']['area_2']['format'] = 'panopoly_wysiwyg_text';
$handler->display->display_options['header']['area_2']['tokenize'] = TRUE;
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = '<div></div>';
$handler->display->display_options['empty']['area']['format'] = 'panopoly_wysiwyg_text';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Taxonomy term: Term ID */
$handler->display->display_options['fields']['tid']['id'] = 'tid';
$handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['tid']['field'] = 'tid';
$handler->display->display_options['fields']['tid']['label'] = '';
$handler->display->display_options['fields']['tid']['exclude'] = TRUE;
$handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['tid']['separator'] = '';
/* Field: Taxonomy term: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['exclude'] = TRUE;
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
/* Field: Content: FAQ Question */
$handler->display->display_options['fields']['field_faq_question']['id'] = 'field_faq_question';
$handler->display->display_options['fields']['field_faq_question']['table'] = 'field_data_field_faq_question';
$handler->display->display_options['fields']['field_faq_question']['field'] = 'field_faq_question';
$handler->display->display_options['fields']['field_faq_question']['relationship'] = 'reverse_field_faq_group_node';
$handler->display->display_options['fields']['field_faq_question']['label'] = '';
$handler->display->display_options['fields']['field_faq_question']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_faq_question']['element_wrapper_class'] = 'question';
/* Field: Content: FAQ Answer */
$handler->display->display_options['fields']['field_faq_answer']['id'] = 'field_faq_answer';
$handler->display->display_options['fields']['field_faq_answer']['table'] = 'field_data_field_faq_answer';
$handler->display->display_options['fields']['field_faq_answer']['field'] = 'field_faq_answer';
$handler->display->display_options['fields']['field_faq_answer']['relationship'] = 'reverse_field_faq_group_node';
$handler->display->display_options['fields']['field_faq_answer']['label'] = '';
$handler->display->display_options['fields']['field_faq_answer']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_faq_answer']['element_wrapper_class'] = 'answer';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Draggableviews: Weight */
$handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
$handler->display->display_options['sorts']['weight_1']['table'] = 'draggableviews_structure';
$handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
$handler->display->display_options['sorts']['weight_1']['relationship'] = 'reverse_field_faq_group_node';
$handler->display->display_options['sorts']['weight_1']['draggableviews_setting_view'] = 'faq:faq_manage_order';
$handler->display->display_options['sorts']['weight_1']['draggableviews_setting_new_items_bottom_list'] = 1;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Taxonomy term: Term ID */
$handler->display->display_options['arguments']['tid']['id'] = 'tid';
$handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
$handler->display->display_options['arguments']['tid']['field'] = 'tid';
$handler->display->display_options['arguments']['tid']['default_action'] = 'default';
$handler->display->display_options['arguments']['tid']['default_argument_type'] = 'php';
$handler->display->display_options['arguments']['tid']['default_argument_options']['code'] = '$arg = arg(3);
if(is_numeric($arg)) return $arg;';
$handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['argument_input'] = array(
  'tid' => array(
    'type' => 'user',
    'context' => 'entity:commerce_customer_profile.commerce_customer_address',
    'context_optional' => 0,
    'panel' => '0',
    'fixed' => '',
    'label' => 'Taxonomy term: Term ID',
  ),
);

  


/* Display: FAQ Manage Order */
$handler = $view->new_display('panel_pane', 'FAQ Manage Order', 'faq_manage_order');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'name' => 'name',
  'field_faq_question' => 'field_faq_question',
  'draggableviews' => 'draggableviews',
  'edit_node' => 'edit_node',
  'delete_node' => 'delete_node',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'name' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_faq_question' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'draggableviews' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'edit_node' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'delete_node' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['footer'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Taxonomy term: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['exclude'] = TRUE;
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
/* Field: Content: FAQ Question */
$handler->display->display_options['fields']['field_faq_question']['id'] = 'field_faq_question';
$handler->display->display_options['fields']['field_faq_question']['table'] = 'field_data_field_faq_question';
$handler->display->display_options['fields']['field_faq_question']['field'] = 'field_faq_question';
$handler->display->display_options['fields']['field_faq_question']['relationship'] = 'reverse_field_faq_group_node';
$handler->display->display_options['fields']['field_faq_question']['label'] = 'Question';
$handler->display->display_options['fields']['field_faq_question']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_faq_question']['element_wrapper_class'] = 'question';
/* Field: Draggableviews: Content */
$handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
$handler->display->display_options['fields']['draggableviews']['table'] = 'node';
$handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
$handler->display->display_options['fields']['draggableviews']['relationship'] = 'reverse_field_faq_group_node';
$handler->display->display_options['fields']['draggableviews']['label'] = '';
$handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
/* Field: Content: Edit link */
$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['relationship'] = 'reverse_field_faq_group_node';
$handler->display->display_options['fields']['edit_node']['label'] = '';
$handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
/* Field: Content: Delete link */
$handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
$handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
$handler->display->display_options['fields']['delete_node']['relationship'] = 'reverse_field_faq_group_node';
$handler->display->display_options['fields']['delete_node']['label'] = '';
$handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Draggableviews: Weight */
$handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
$handler->display->display_options['sorts']['weight_1']['table'] = 'draggableviews_structure';
$handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
$handler->display->display_options['sorts']['weight_1']['relationship'] = 'reverse_field_faq_group_node';
$handler->display->display_options['sorts']['weight_1']['draggableviews_setting_view'] = 'self';
$handler->display->display_options['sorts']['weight_1']['draggableviews_setting_new_items_bottom_list'] = 1;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Taxonomy term: Term ID */
$handler->display->display_options['arguments']['tid']['id'] = 'tid';
$handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
$handler->display->display_options['arguments']['tid']['field'] = 'tid';
$handler->display->display_options['arguments']['tid']['default_action'] = 'default';
$handler->display->display_options['arguments']['tid']['default_argument_type'] = 'php';
$handler->display->display_options['arguments']['tid']['default_argument_options']['code'] = '$arg = arg(4);
if(is_numeric($arg)) return $arg;';
$handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['inherit_panels_path'] = '1';



//   /* Display: FAQ Manage Order */
//   $handler = $view->new_display('panel_pane', 'FAQ Manage Order', 'faq_manage_order');
//   $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
//   $handler->display->display_options['defaults']['style_plugin'] = FALSE;
//   $handler->display->display_options['style_plugin'] = 'table';
//   $handler->display->display_options['style_options']['columns'] = array(
//     'name' => 'name',
//     'field_faq_question' => 'field_faq_question',
//     'nid' => 'nid',
//   );
//   $handler->display->display_options['style_options']['default'] = '-1';
//   $handler->display->display_options['style_options']['info'] = array(
//     'name' => array(
//       'sortable' => 0,
//       'default_sort_order' => 'asc',
//       'align' => '',
//       'separator' => '',
//       'empty_column' => 0,
//     ),
//     'field_faq_question' => array(
//       'sortable' => 0,
//       'default_sort_order' => 'asc',
//       'align' => '',
//       'separator' => '',
//       'empty_column' => 0,
//     ),
//     'nid' => array(
//       'sortable' => 0,
//       'default_sort_order' => 'asc',
//       'align' => '',
//       'separator' => '',
//       'empty_column' => 0,
//     ),
//   );
//   $handler->display->display_options['defaults']['style_options'] = FALSE;
//   $handler->display->display_options['defaults']['row_plugin'] = FALSE;
//   $handler->display->display_options['defaults']['row_options'] = FALSE;
//   $handler->display->display_options['defaults']['footer'] = FALSE;
//   $handler->display->display_options['defaults']['fields'] = FALSE;
//   /* Field: Taxonomy term: Name */
//   $handler->display->display_options['fields']['name']['id'] = 'name';
//   $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
//   $handler->display->display_options['fields']['name']['field'] = 'name';
//   $handler->display->display_options['fields']['name']['label'] = '';
//   $handler->display->display_options['fields']['name']['exclude'] = TRUE;
//   $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
//   /* Field: Content: FAQ Question */
//   $handler->display->display_options['fields']['field_faq_question']['id'] = 'field_faq_question';
//   $handler->display->display_options['fields']['field_faq_question']['table'] = 'field_data_field_faq_question';
//   $handler->display->display_options['fields']['field_faq_question']['field'] = 'field_faq_question';
//   $handler->display->display_options['fields']['field_faq_question']['relationship'] = 'reverse_field_faq_group_node';
//   $handler->display->display_options['fields']['field_faq_question']['label'] = 'Question';
//   $handler->display->display_options['fields']['field_faq_question']['element_label_colon'] = FALSE;
//   $handler->display->display_options['fields']['field_faq_question']['element_wrapper_class'] = 'question';
// /***********************************************************/
//   $handler->display->display_options['fields']['field_faq_question_edit']['id'] = 'field_faq_question_edit_operation';
//   $handler->display->display_options['fields']['field_faq_question_edit']['table'] = 'field_data_field_faq_question';
//   $handler->display->display_options['fields']['field_faq_question_edit']['field'] = 'entity_id';
//   $handler->display->display_options['fields']['field_faq_question_edit']['relationship'] = 'reverse_field_faq_group_node';
//   $handler->display->display_options['fields']['field_faq_question_edit']['label'] = 'Edit';
//   $handler->display->display_options['fields']['field_faq_question_edit']['element_label_colon'] = FALSE;
//   $handler->display->display_options['fields']['field_faq_question_edit']['element_wrapper_class'] = 'question_edit_operation';

//   $handler->display->display_options['fields']['field_faq_question_delete']['id'] = 'field_faq_question_edit_operation';
//   $handler->display->display_options['fields']['field_faq_question_delete']['table'] = 'field_data_field_faq_question';
//   $handler->display->display_options['fields']['field_faq_question_delete']['field'] = 'entity_id';
//   $handler->display->display_options['fields']['field_faq_question_delete']['relationship'] = 'reverse_field_faq_group_node';
//   $handler->display->display_options['fields']['field_faq_question_delete']['label'] = 'Delete';
//   $handler->display->display_options['fields']['field_faq_question_delete']['element_label_colon'] = FALSE;
//   $handler->display->display_options['fields']['field_faq_question_delete']['element_wrapper_class'] = 'question_edit_operation';
// /************************************************************/
//   /* Field: Draggableviews: Content */
//   $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
//   $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
//   $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
//   $handler->display->display_options['fields']['draggableviews']['relationship'] = 'reverse_field_faq_group_node';
//   $handler->display->display_options['fields']['draggableviews']['label'] = '';
//   $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
//   $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
//   $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
//   $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
//   $handler->display->display_options['defaults']['sorts'] = FALSE;
//   /* Sort criterion: Draggableviews: Weight */
//   $handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
//   $handler->display->display_options['sorts']['weight_1']['table'] = 'draggableviews_structure';
//   $handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
//   $handler->display->display_options['sorts']['weight_1']['relationship'] = 'reverse_field_faq_group_node';
//   $handler->display->display_options['sorts']['weight_1']['draggableviews_setting_view'] = 'self';
//   $handler->display->display_options['sorts']['weight_1']['draggableviews_setting_new_items_bottom_list'] = 1;
//   $handler->display->display_options['defaults']['arguments'] = FALSE;
//   /* Contextual filter: Taxonomy term: Term ID */
//   $handler->display->display_options['arguments']['tid']['id'] = 'tid';
//   $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
//   $handler->display->display_options['arguments']['tid']['field'] = 'tid';
//   $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
//   $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'php';
//   $handler->display->display_options['arguments']['tid']['default_argument_options']['code'] = '$arg = arg(4);
// if(is_numeric($arg)) return $arg;';
//   $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
//   $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
//   $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
//   $handler->display->display_options['inherit_panels_path'] = '1';

  


/* Display: FAQ Page Manage Order */
$handler = $view->new_display('panel_pane', 'FAQ Page Manage Order', 'faq_page_manage_order');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['grouping'] = array(
  0 => array(
    'field' => 'name',
    'rendered' => 1,
    'rendered_strip' => 0,
  ),
);
$handler->display->display_options['style_options']['columns'] = array(
  'name' => 'name',
  'field_faq_question' => 'field_faq_question',
  'draggableviews' => 'draggableviews',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'name' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_faq_question' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'draggableviews' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['footer'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Taxonomy term: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['exclude'] = TRUE;
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
/* Field: Content: FAQ Question */
$handler->display->display_options['fields']['field_faq_question']['id'] = 'field_faq_question';
$handler->display->display_options['fields']['field_faq_question']['table'] = 'field_data_field_faq_question';
$handler->display->display_options['fields']['field_faq_question']['field'] = 'field_faq_question';
$handler->display->display_options['fields']['field_faq_question']['relationship'] = 'reverse_field_faq_group_node';
$handler->display->display_options['fields']['field_faq_question']['label'] = 'Question';
$handler->display->display_options['fields']['field_faq_question']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_faq_question']['element_wrapper_class'] = 'question';
/* Field: Draggableviews: Content */
$handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
$handler->display->display_options['fields']['draggableviews']['table'] = 'node';
$handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
$handler->display->display_options['fields']['draggableviews']['relationship'] = 'reverse_field_faq_group_node';
$handler->display->display_options['fields']['draggableviews']['label'] = '';
$handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
/* Field: Content: Edit link */
$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['relationship'] = 'reverse_field_faq_group_node';
$handler->display->display_options['fields']['edit_node']['label'] = '';
$handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
/* Field: Content: Delete link */
$handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
$handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
$handler->display->display_options['fields']['delete_node']['relationship'] = 'reverse_field_faq_group_node';
$handler->display->display_options['fields']['delete_node']['label'] = '';
$handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Draggableviews: Weight */
$handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
$handler->display->display_options['sorts']['weight_1']['table'] = 'draggableviews_structure';
$handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
$handler->display->display_options['sorts']['weight_1']['relationship'] = 'reverse_field_faq_group_node';
$handler->display->display_options['sorts']['weight_1']['draggableviews_setting_view'] = 'self';
$handler->display->display_options['sorts']['weight_1']['draggableviews_setting_new_items_bottom_list'] = 1;
$handler->display->display_options['defaults']['arguments'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Taxonomy vocabulary: Machine name */
$handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
$handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
$handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
$handler->display->display_options['filters']['machine_name']['value'] = array(
  'faq_group' => 'faq_group',
);
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_faq_group_node';
$handler->display->display_options['filters']['type']['value'] = array(
  'faq' => 'faq',
);




  // /* Display: FAQ Page Manage Order */
  // $handler = $view->new_display('panel_pane', 'FAQ Page Manage Order', 'faq_page_manage_order');
  // $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  // $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  // $handler->display->display_options['style_plugin'] = 'table';
  // $handler->display->display_options['style_options']['grouping'] = array(
  //   0 => array(
  //     'field' => 'name',
  //     'rendered' => 1,
  //     'rendered_strip' => 0,
  //   ),
  // );
  // $handler->display->display_options['style_options']['columns'] = array(
  //   'name' => 'name',
  //   'field_faq_question' => 'field_faq_question',
  //   'draggableviews' => 'draggableviews',
  // );
  // $handler->display->display_options['style_options']['default'] = '-1';
  // $handler->display->display_options['style_options']['info'] = array(
  //   'name' => array(
  //     'sortable' => 0,
  //     'default_sort_order' => 'asc',
  //     'align' => '',
  //     'separator' => '',
  //     'empty_column' => 0,
  //   ),
  //   'field_faq_question' => array(
  //     'sortable' => 0,
  //     'default_sort_order' => 'asc',
  //     'align' => '',
  //     'separator' => '',
  //     'empty_column' => 0,
  //   ),
  //   'draggableviews' => array(
  //     'align' => '',
  //     'separator' => '',
  //     'empty_column' => 0,
  //   ),
  // );
  // $handler->display->display_options['defaults']['style_options'] = FALSE;
  // $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  // $handler->display->display_options['defaults']['row_options'] = FALSE;
  // $handler->display->display_options['defaults']['footer'] = FALSE;
  // $handler->display->display_options['defaults']['fields'] = FALSE;
  // /* Field: Taxonomy term: Name */
  // $handler->display->display_options['fields']['name']['id'] = 'name';
  // $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  // $handler->display->display_options['fields']['name']['field'] = 'name';
  // $handler->display->display_options['fields']['name']['label'] = '';
  // $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  // $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  // /* Field: Content: FAQ Question */
  // $handler->display->display_options['fields']['field_faq_question']['id'] = 'field_faq_question';
  // $handler->display->display_options['fields']['field_faq_question']['table'] = 'field_data_field_faq_question';
  // $handler->display->display_options['fields']['field_faq_question']['field'] = 'field_faq_question';
  // $handler->display->display_options['fields']['field_faq_question']['relationship'] = 'reverse_field_faq_group_node';
  // $handler->display->display_options['fields']['field_faq_question']['label'] = 'Question';
  // $handler->display->display_options['fields']['field_faq_question']['element_label_colon'] = FALSE;
  // $handler->display->display_options['fields']['field_faq_question']['element_wrapper_class'] = 'question';
  // /* Field: Draggableviews: Content */
  // $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  // $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  // $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  // $handler->display->display_options['fields']['draggableviews']['relationship'] = 'reverse_field_faq_group_node';
  // $handler->display->display_options['fields']['draggableviews']['label'] = '';
  // $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  // $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  // $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  // $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  // $handler->display->display_options['defaults']['sorts'] = FALSE;
  // /* Sort criterion: Draggableviews: Weight */
  // $handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
  // $handler->display->display_options['sorts']['weight_1']['table'] = 'draggableviews_structure';
  // $handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
  // $handler->display->display_options['sorts']['weight_1']['relationship'] = 'reverse_field_faq_group_node';
  // $handler->display->display_options['sorts']['weight_1']['draggableviews_setting_view'] = 'self';
  // $handler->display->display_options['sorts']['weight_1']['draggableviews_setting_new_items_bottom_list'] = 1;
  // $handler->display->display_options['defaults']['arguments'] = FALSE;
  // $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  // $handler->display->display_options['defaults']['filters'] = FALSE;
  // /* Filter criterion: Taxonomy vocabulary: Machine name */
  // $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  // $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  // $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  // $handler->display->display_options['filters']['machine_name']['value'] = array(
  //   'faq_group' => 'faq_group',
  // );
  // /* Filter criterion: Content: Type */
  // $handler->display->display_options['filters']['type']['id'] = 'type';
  // $handler->display->display_options['filters']['type']['table'] = 'node';
  // $handler->display->display_options['filters']['type']['field'] = 'type';
  // $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_faq_group_node';
  // $handler->display->display_options['filters']['type']['value'] = array(
  //   'faq' => 'faq',
  // );



  $export['faq'] = $view;

  return $export;
}
