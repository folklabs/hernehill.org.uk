<?php
/**
 * @file
 * panopoly_faq_question_demo.features.content.inc
 */

/**
 * Implements hook_content_defaults().
 */
function panopoly_faq_question_demo_content_defaults() {
  $content = array();

  $content['panopoly-faq-demo-0'] = (object) array(
    'exported_path' => 'faq/what-drupal',
    'title' => 'What is Drupal?',
    'status' => '1',
    'promote' => '0',
    'sticky' => '0',
    'type' => 'faq',
    'language' => 'und',
    'created' => '1362604269',
    'comment' => '0',
    'translate' => '0',
    'machine_name' => 'panopoly-faq-demo-0',
    'field_faq_answer' => array(
      'und' => array(
        0 => array(
          'value' => '<p><span>Drupal is an open-source platform and content management system for building dynamic web sites offering a broad range of features and services including user administration, publishing workflow, discussion capabilities, news aggregation, metadata functionalities using controlled vocabularies and XML publishing for content sharing purposes. Equipped with a powerful blend of features and configurability, Drupal can support a diverse range of web projects ranging from personal weblogs to large community-driven sites.</span></p>',
          'format' => 'panopoly_wysiwyg_text',
          'safe_value' => '<p><span>Drupal is an open-source platform and content management system for building dynamic web sites offering a broad range of features and services including user administration, publishing workflow, discussion capabilities, news aggregation, metadata functionalities using controlled vocabularies and XML publishing for content sharing purposes. Equipped with a powerful blend of features and configurability, Drupal can support a diverse range of web projects ranging from personal weblogs to large community-driven sites.</span></p>
',
        ),
      ),
    ),
    'field_faq_group' => array(
      'und' => array(
        0 => array(
          'target_id' => '4',
        ),
      ),
    ),
    'field_faq_question' => array(
      'und' => array(
        0 => array(
          'value' => '<p>What is Drupal?</p>',
          'format' => 'panopoly_wysiwyg_text',
          'safe_value' => '<p>What is Drupal?</p>
',
        ),
      ),
    ),
  );

  $content['panopoly-faq-demo-1'] = (object) array(
    'exported_path' => 'faq/drupal-right-cms-my-needs',
    'title' => 'Is Drupal the right CMS for my needs?',
    'status' => '1',
    'promote' => '0',
    'sticky' => '0',
    'type' => 'faq',
    'language' => 'und',
    'created' => '1362604569',
    'comment' => '0',
    'translate' => '0',
    'machine_name' => 'panopoly-faq-demo-1',
    'field_faq_answer' => array(
      'und' => array(
        0 => array(
          'value' => '<p><span>We\'ve set up&nbsp;</span><a href="http://drupal.org/node/346217">a page</a><span>&nbsp;to specifically answer this question.</span></p>',
          'format' => 'panopoly_wysiwyg_text',
          'safe_value' => '<p><span>We\'ve set up </span><a href="http://drupal.org/node/346217">a page</a><span> to specifically answer this question.</span></p>
',
        ),
      ),
    ),
    'field_faq_group' => array(
      'und' => array(
        0 => array(
          'target_id' => '4',
        ),
      ),
    ),
    'field_faq_question' => array(
      'und' => array(
        0 => array(
          'value' => '<p><span>Is Drupal the right CMS for my needs?</span></p>',
          'format' => 'panopoly_wysiwyg_text',
          'safe_value' => '<p><span>Is Drupal the right CMS for my needs?</span></p>
',
        ),
      ),
    ),
  );

  $content['panopoly-faq-demo-2'] = (object) array(
    'exported_path' => 'faq/can-i-see-some-drupal-screenshots',
    'title' => 'Can I see some Drupal screenshots?',
    'status' => '1',
    'promote' => '0',
    'sticky' => '0',
    'type' => 'faq',
    'language' => 'und',
    'created' => '1362604602',
    'comment' => '0',
    'translate' => '0',
    'machine_name' => 'panopoly-faq-demo-2',
    'field_faq_answer' => array(
      'und' => array(
        0 => array(
          'value' => '<p><span>The&nbsp;</span><a href="http://drupal.org/image">Image galleries</a><span>&nbsp;include screenshots of Drupal installations, themes, websites and modules.</span></p>',
          'format' => 'panopoly_wysiwyg_text',
          'safe_value' => '<p><span>The </span><a href="http://drupal.org/image">Image galleries</a><span> include screenshots of Drupal installations, themes, websites and modules.</span></p>
',
        ),
      ),
    ),
    'field_faq_group' => array(
      'und' => array(
        0 => array(
          'target_id' => '4',
        ),
      ),
    ),
    'field_faq_question' => array(
      'und' => array(
        0 => array(
          'value' => '<p><span>Can I see some Drupal screenshots?</span></p>',
          'format' => 'panopoly_wysiwyg_text',
          'safe_value' => '<p><span>Can I see some Drupal screenshots?</span></p>
',
        ),
      ),
    ),
  );

return $content;
}
