<?php
/**
 * @file
 * openlocal_images.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function openlocal_images_image_default_styles() {
  $styles = array();

  // Exported image style: openlocal_avatar_large.
  $styles['openlocal_avatar_large'] = array(
    'name' => 'openlocal_avatar_large',
    'label' => 'openlocal_avatar_large',
    'effects' => array(
      11 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 220,
          'height' => 216,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: openlocal_avatar_micro.
  $styles['openlocal_avatar_micro'] = array(
    'name' => 'openlocal_avatar_micro',
    'label' => 'openlocal_avatar_micro',
    'effects' => array(
      13 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 24,
          'height' => 24,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: openlocal_avatar_small.
  $styles['openlocal_avatar_small'] = array(
    'name' => 'openlocal_avatar_small',
    'label' => 'openlocal_avatar_small',
    'effects' => array(
      12 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 60,
          'height' => 60,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: openlocal_events_listing.
  $styles['openlocal_events_listing'] = array(
    'name' => 'openlocal_events_listing',
    'label' => 'openlocal_events_listing',
    'effects' => array(
      8 => array(
        'label' => 'Focus Scale And Crop',
        'help' => 'Scale and crop based on data provided by <em>ImageField Focus</em>.',
        'effect callback' => 'imagefield_focus_scale_and_crop_effect',
        'form callback' => 'imagefield_focus_scale_and_crop_form',
        'summary theme' => 'imagefield_focus_scale_and_crop_summary',
        'module' => 'imagefield_focus',
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 120,
          'height' => 80,
          'strength' => 'high',
          'fallback' => 'image',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: openlocal_node_main.
  $styles['openlocal_node_main'] = array(
    'name' => 'openlocal_node_main',
    'label' => 'openlocal_node_main',
    'effects' => array(
      9 => array(
        'label' => 'Focus Scale And Crop',
        'help' => 'Scale and crop based on data provided by <em>ImageField Focus</em>.',
        'effect callback' => 'imagefield_focus_scale_and_crop_effect',
        'form callback' => 'imagefield_focus_scale_and_crop_form',
        'summary theme' => 'imagefield_focus_scale_and_crop_summary',
        'module' => 'imagefield_focus',
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 460,
          'height' => 264,
          'strength' => 'low',
          'fallback' => 'image',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: openlocal_panel_deep.
  $styles['openlocal_panel_deep'] = array(
    'name' => 'openlocal_panel_deep',
    'label' => 'openlocal_panel_deep',
    'effects' => array(
      10 => array(
        'label' => 'Focus Scale And Crop',
        'help' => 'Scale and crop based on data provided by <em>ImageField Focus</em>.',
        'effect callback' => 'imagefield_focus_scale_and_crop_effect',
        'form callback' => 'imagefield_focus_scale_and_crop_form',
        'summary theme' => 'imagefield_focus_scale_and_crop_summary',
        'module' => 'imagefield_focus',
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 220,
          'height' => 128,
          'strength' => 'high',
          'fallback' => 'image',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: openlocal_panel_shallow.
  $styles['openlocal_panel_shallow'] = array(
    'name' => 'openlocal_panel_shallow',
    'label' => 'openlocal_panel_shallow',
    'effects' => array(
      7 => array(
        'label' => 'Focus Scale And Crop',
        'help' => 'Scale and crop based on data provided by <em>ImageField Focus</em>.',
        'effect callback' => 'imagefield_focus_scale_and_crop_effect',
        'form callback' => 'imagefield_focus_scale_and_crop_form',
        'summary theme' => 'imagefield_focus_scale_and_crop_summary',
        'module' => 'imagefield_focus',
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 220,
          'height' => 72,
          'strength' => 'medium',
          'fallback' => 'image',
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
