<?php
// Plugin definition
$plugin = array(
  'title' => t('Hopkins'),
  'icon' => 'hopkins.png',
  'category' => t('OpenLocal'),
  'theme' => 'hopkins',
  'css' => 'hopkins.css',
  'regions' => array(
    'header' => t('Header'),
    'sidebar' => t('Sidebar Right'),
    'contentheader' => t('Map'),
    'contentcolumn1' => t('Sidebar Left'),
    'contentcolumn2' => t('Main listing'),
  ),
);
