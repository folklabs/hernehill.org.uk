<?php

/**
 * @file
 * A panel plugin to provide an RSS link to the blog.
 */

$plugin = array(
  'title' => t('RSS'),
  'description' => t('This is a link to an RSS feed of the latest blog posts'),
  'content_types' => array('debut_blog_rss'),
  'category' => t('Blog'),
  'single' => TRUE,
);

/**
  * Implementation of hook_CONTENT_TYPE_content_type_render()
  */
function debut_blog_debut_blog_rss_content_type_render($subtype, $conf, $panel_args, $context) {
  $pane = new stdClass();
  $pane->content = theme_feed_icon(array('title' => t('Blog updates from from %site_name', array('%site_name' => variable_get('site_name')), 'url' => 'blog/rss'));
  return $pane;
}
