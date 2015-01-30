<?php


class UserMigration extends DrupalUser6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // TODO: removed because of warning
    // $this->addFieldMapping('roles', 'roles')
    //   ->sourceMigration('role');

    // Set user picture field to null, no user pictures are imported
    $this->addFieldMapping('field_user_picture')
      ->defaultValue(0);
  }
}

class NewsTermsMigration extends DrupalTerm6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('path', 'path')
      ->callbacks(array($this, 'checkPath'));
  }

  protected function checkPath($value) {
    // drush_print($value);
    $value = preg_replace('#category/news/#', 'taxonomy/ol_tags/', $value);
    // drush_print($value);
    return $value;
  }
}

class NewsMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    // $this->sourceFields['f.field_audio_description'] = 'field_audio_description';
    // $this->sourceFields['News'] = 'Summary string from D6';

    parent::__construct($arguments);

    // $this->addUnmigratedSources(array('field_audio_description'), t('Do Not Migrate'));

    $this->addFieldMapping('uid', 'uid')
         ->sourceMigration('user');
    $this->addFieldMapping('body', 'body')
      ->callbacks(array($this, 'removeNewlinesFromText'));
    $this->addFieldMapping('body:format')
      ->defaultValue('panopoly_wysiwyg_text');
    $this->addFieldMapping('field_ol_tags', 8)
         ->sourceMigration('News_terms')
         ->arguments(array('source_type' => 'tid'));
  }

  protected function removeNewlinesFromText($value) {
    // drush_print($value);
    $value = preg_replace('/\<p\>\&nbsp;\<\/p\>/', '', $value);
    // drush_print($value);
    return $value;
  }
}

class CampaignsMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('field_ol_description', 'field_overview');
    $this->addFieldMapping('field_ol_details', 'body');
    $this->addFieldMapping('field_ol_details:format')
      ->defaultValue('panopoly_wysiwyg_text');
    $this->addFieldMapping('field_ol_group_campaign')
      ->defaultValue('1');
    $this->addFieldMapping('pathauto', FALSE);
    // $this->addFieldMapping('field_ol_tags', 8)
    //      ->sourceMigration('News_terms')
    //      ->arguments(array('source_type' => 'tid'));
  }
}

class EventMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('field_ol_description', 'field_eventteaser');
    $this->addFieldMapping('field_ol_details', 'body')
      ->callbacks(array($this, 'removeNewlinesFromText'));
    $this->addFieldMapping('field_ol_event_date', 'field_eventdate');
    $this->addFieldMapping('field_ol_wheelchair_accessible', 'field_wheelchair')
      ->callbacks(array($this, 'convertBoolean'));
    // $this->addFieldMapping('', 'field_location');

    $this->addFieldMapping('field_ol_details:format')
      ->defaultValue('panopoly_wysiwyg_text');
    // $this->addFieldMapping('field_ol_tags', 8)
    //      ->sourceMigration('News_terms')
    //      ->arguments(array('source_type' => 'tid'));
  }

  protected function removeNewlinesFromText($value) {
    // drush_print($value);
    $value = preg_replace('/\<p\>\&nbsp;\<\/p\>/', '', $value);
    // drush_print($value);
    return $value;
  }

  protected function convertBoolean($value) {
    // drush_print($value);
    $value = ($value == "Yes") ? 1 : 0;
    return $value;
  }
}

class GalleryMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    // $this->sourceFields['News'] = 'Summary string from D6';
    parent::__construct($arguments);

    $this->addFieldMapping('field_ol_description', 'field_overview');
    $this->addFieldMapping('field_ol_details', 'body');
    $this->addFieldMapping('field_ol_details:format')
      ->defaultValue('panopoly_wysiwyg_text');

    $this->addFieldMapping('field_ol_gallery_images', 'body');

    // $this->addFieldMapping('field_ol_tags', 8)
    //      ->sourceMigration('News_terms')
    //      ->arguments(array('source_type' => 'tid'));
  }
}

class GroupMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    // $this->sourceFields['News'] = 'Summary string from D6';
    parent::__construct($arguments);

    $this->addFieldMapping('field_ol_description', 'field_overview');
    $this->addFieldMapping('field_ol_details', 'body');
    $this->addFieldMapping('field_ol_details:format')
      ->defaultValue('panopoly_wysiwyg_text');
    $this->addFieldMapping('pathauto', FALSE);
    // $this->addFieldMapping('field_ol_tags', 8)
    //      ->sourceMigration('News_terms')
    //      ->arguments(array('source_type' => 'tid'));
  }
}

class ServiceMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    // $this->sourceFields['News'] = 'Summary string from D6';
    parent::__construct($arguments);

    $this->addFieldMapping('field_ol_description', 'field_tags');
    $this->addFieldMapping('field_ol_details', 'body')
      ->callbacks(array($this, 'stripBlankLines'));
    $this->addFieldMapping('field_ol_business_website', 'field_website');
    $this->addFieldMapping('field_ol_business_email', 'field_service_email');
    $this->addFieldMapping('field_ol_business_telephone', 'field_telephonenumber');
    $this->addFieldMapping('field_ol_business_opening_hours', 'field_openinghours');
    // $this->addFieldMapping('field_ol_address', 'field_address');
    $this->addFieldMapping('field_ol_business_twitter', 'field_servicetwitter');

    $this->addFieldMapping('field_ol_details:format')
      ->defaultValue('panopoly_wysiwyg_text');
    // $this->addFieldMapping('field_ol_local_business_category', 8)
    //      ->sourceMigration('News_terms')
    //      ->arguments(array('source_type' => 'tid'));
    $this->addFieldMapping('field_ol_business_tags', 4)
         ->sourceMigration('service_tags_terms')
         ->arguments(array('source_type' => 'tid'));
  }

  protected function stripBlankLines($value) {
    $value = preg_replace('#<p>\&nbsp;</p>#', '', $value);
    return $value;
  }
}

class GroupPostMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    // $this->sourceFields['News'] = 'Summary string from D6';
    parent::__construct($arguments);

    $this->addFieldMapping('field_ol_details', 'body');
    $this->addFieldMapping('body:format')
      ->defaultValue('panopoly_wysiwyg_text');
    // $this->addFieldMapping('field_ol_tags', 8)
    //      ->sourceMigration('News_terms')
    //      ->arguments(array('source_type' => 'tid'));
  }
}


class Drupal6GalleryImageMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = 'Image table data';
    // $this->softDependencies = array('WineComment');
    $table_name = 'field_data_field_ol_gallery_images';
    $this->map = new MigrateSQLMap($this->machineName,
      array('nid' => array(
              'type' => 'int',
              'unsigned' => TRUE,
              'not null' => TRUE,
             )
           ),
        MigrateDestinationTable::getKeySchema($table_name)
      );
    // $query = db_select('content_type_gallery_image', 't', array('target' => 'd6.hernehill'))
    //          ->fields('t', array('nid', 'field_gallery_image_fid', 'field_gallery_nid', 'field_gallerypicdescription_value'));
    $query = Database::getConnection('default', 'd6.hernehill')->select('content_type_gallery_image', 't')
             ->fields('t', array('nid', 'field_gallery_image_fid', 'field_gallery_nid', 'field_gallerypicdescription_value'));
    $this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));
    $this->destination = new MigrateDestinationTable($table_name);
    // Mapped fields
    $this->removeFieldMapping('nid');
    $this->addFieldMapping('entity_type')
      ->defaultValue('node');
    $this->addFieldMapping('bundle')
      ->defaultValue('ol_gallery');
    $this->addFieldMapping('deleted')
      ->defaultValue('0');
    $this->addFieldMapping('entity_id', 'field_gallery_nid')
      ->sourceMigration('Gallery');
    $this->addFieldMapping('revision_id')
      ->defaultValue('0');
    $this->addFieldMapping('language')
      ->defaultValue('und');
    // TODO: Needs improving
    $this->addFieldMapping('delta', 'field_gallery_nid')
      ->callbacks(array($this, 'calcDelta'));
    $this->addFieldMapping('field_ol_gallery_images_fid', 'field_gallery_image_fid')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_ol_gallery_images_alt')
      ->defaultValue('');
    // TODO: what should description be mapped to if not title?
    $this->addFieldMapping('field_ol_gallery_images_title', 'field_gallerypicdescription_value')
      ->callbacks(array($this, 'trimTitle'));
    $this->addFieldMapping('field_ol_gallery_images_width')
      ->defaultValue('100');
    $this->addFieldMapping('field_ol_gallery_images_height')
      ->defaultValue('100');

    $this->deltas = array();
  }

  protected function calcDelta($value) {
    drush_print_r('calcDelta');
    drush_print_r($value);
    // Start delta at 0 or increment
    if ($this->deltas[$value] == nil) {
      drush_print_r('init delta');
      $this->deltas[$value] = 0;
    }
    else {
      drush_print_r('increment delta');
      $this->deltas[$value] = $this->deltas[$value] + 1;
    }
    drush_print_r($this->deltas[$value]);
    return $this->deltas[$value];
  }

  protected function trimTitle($value) {
    $value = drupal_substr($value, 0, 1024);
    return $value;
  }
}

/**
 * Import forum topics from RP Forum to core forum nodes.
 */
class HHCommentNodeMigrationBase extends Migration {
  public function __construct($settings_machine_name, $dest_comment_type, $node_type) {
    parent::__construct($settings_machine_name);
    $this->destNodeType = $node_type;
    $this->description = t('Migrate Comment nodes into D7 regular comments.');
    $this->source = new MigrateSourceSQL($this->query(), array(), NULL, array('map_joinable' => FALSE));

    $this->destination = new MigrateDestinationComment($dest_comment_type);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $this->addFieldMapping('nid', 'n2_nid')
      ->sourceMigration($node_type);

    // TODO: check for User migration mapping
    $this->addFieldMapping('uid', 'uid');
    // $this->addFieldMapping('cid', 'cid');
    // $this->addFieldMapping('taxonomy_forums', 'tid') //->defaultValue(30)
    //   ->sourceMigration('RPForumForums')
    //   ->arguments(array('source_type' => 'tid'));
    $this->addFieldMapping('subject', 'title')
      ->callbacks(array($this, 'trimTitle'));
    $this->addFieldMapping('comment_body', 'body')
      // ->callbacks(array($this, 'checkBody'));
      ->callbacks(array($this, 'stripBlankLines'))
      ->arguments(array('format' => 'panopoly_html_text'));
    $this->addFieldMapping('comment_body_format')
      ->defaultValue('panopoly_wysiwyg_text');
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('changed', 'changed');

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array('is_new', 'promote',
      'revision', 'language', 'sticky', 'revision_uid', 'path','tnid'));
  }

  protected function stripBlankLines($value) {
    $value = preg_replace('#<p>\&nbsp;</p>#', '', $value);
    return $value;
  }

  protected function checkBody($value) {
    // drush_print($value);
    return $value;
  }

  protected function trimTitle($value) {
    $value = drupal_substr($value, 0, 64);
    return $value;
  }

  /**
   * Method to return the query used in the import.
   * Can be called by sub classes and extended if needed.
   */
  protected function query() {
    $query = Database::getConnection('default', 'd6.hernehill')->select('node', 'n');

    $query->leftJoin('node_comments', 'nc', 'n.nid = nc.cid');
    $query->leftJoin('node', 'n2', 'nc.nid = n2.nid');
    $query->leftJoin('node_revisions', 'nr', 'n.nid = nr.nid');

    $query->fields('n', array('nid', 'title', 'uid', 'type', 'created', 'changed'));
    $query->fields('n2', array('nid', 'title', 'uid', 'type', 'created', 'changed'));
    $query->fields('nc', array('nid', 'cid'));
    $query->fields('nr', array('nid', 'body'));
    // $query->fields('tn', array('nid', 'tid'));
    // $query->fields('rp', array('vid','nid','field_body2_value','field_parent_node_value'));
    $query->condition('n.type', 'comment');
    $query->condition('n2.type', $this->destNodeType);
    // $query->condition('n2.type', 'group');
    // $query->condition('n2.type', 'campaigns');
    // $query->condition('n2.type', 'blog');
    // $query->condition('n2.type', 'event');
    // $query->condition('n2.type', 'news');

    // drush_print('parent nid: '  );
    $result = $query->execute();
    foreach($result as $r) {
      // drush_print('r');
      // drush_print_r($r);
    }

    return $query;
  }
}

class HHGroupCommentNodeMigration extends HHCommentNodeMigrationBase {
  public function __construct($settings_machine_name) {
    parent::__construct($settings_machine_name, 'comment_node_group', 'group');
  }
}

class HHCampaignsCommentNodeMigration extends HHCommentNodeMigrationBase {
  public function __construct($settings_machine_name) {
    parent::__construct($settings_machine_name, 'comment_node_campaigns', 'campaigns');
  }
}

class HHEventCommentNodeMigration extends HHCommentNodeMigrationBase {
  public function __construct($settings_machine_name) {
    parent::__construct($settings_machine_name, 'comment_node_event', 'event');
  }
}

class HHNewsCommentNodeMigration extends HHCommentNodeMigrationBase {
  public function __construct($settings_machine_name) {
    parent::__construct($settings_machine_name, 'comment_node_openlocal_news_article', 'news');
  }
}

// class HHBlogCommentNodeMigration extends Migration {
//   public function __construct($settings_machine_name, $dest_comment_type, $node_type) {
//     parent::__construct($settings_machine_name, 'comment_node_blog', 'blog');
//   }
// }


// class GalleryMigration extends Migration {
//   public function __construct($settings_machine_name) {
//     parent::__construct($settings_machine_name);
//     $this->description = t('Migrate individual forum topics from RP Forum.');
//     $this->source = new MigrateSourceSQL($this->query(), array(), NULL, array('map_joinable' => FALSE));

//     $this->destination = new MigrateDestinationNode('ol_gallery');

//     $this->map = new MigrateSQLMap($this->machineName,
//       array(
//         'nid' => array(
//           'type' => 'int',
//           'unsigned' => TRUE,
//           'not null' => TRUE,
//         )
//       ),
//       MigrateDestinationNode::getKeySchema()
//     );

//     $this->addFieldMapping('uid', 'uid');
//     // $this->addFieldMapping('taxonomy_forums', 'tid') //->defaultValue(30)
//     //   ->sourceMigration('RPForumForums')
//     //   ->arguments(array('source_type' => 'tid'));
//     $this->addFieldMapping('title', 'title');
//     $this->addFieldMapping('field_ol_details', 'field_body2_value')
//       ->arguments(array('format' => 'panopoly_html_text'));
//     $this->addFieldMapping('created', 'created');
//     $this->addFieldMapping('changed', 'changed');

//     // Unmapped destination fields
//     $this->addUnmigratedDestinations(array('is_new', 'promote',
//       'revision', 'language', 'sticky', 'revision_uid', 'path','tnid'));
//   }

//   /**
//    * Method to return the query used in the import.
//    * Can be called by sub classes and extended if needed.
//    */
//   protected function query() {
//     $query = Database::getConnection('default', 'd6.hernehill')->select('content_type_rp_forum_post', 'rp');
//     $query->leftJoin('node', 'n', 'rp.nid = n.nid');
//     $query->leftJoin('term_node', 'tn', 'tn.nid = n.nid');
//     $query->fields('n', array('nid', 'title', 'uid', 'created', 'changed'));
//     $query->fields('tn', array('nid', 'tid'));
//     $query->fields('rp', array('vid','nid','field_body2_value','field_parent_node_value'));
//     $query->condition('field_parent_node_value', -1);

//     // A hack to test importing just 1 node
//     // $query->condition('rp.nid', 442);

//     return $query;
//   }
// }

/**
 * Import forum reply posts from RP Forum to core forum comments.
 */
// class RPForumPostMigration extends Migration {
//   public function __construct($settings_machine_name) {
//     parent::__construct($settings_machine_name);
//     $this->description = t('Migrate individual forum posts from RP Forum.');
//     $this->source = new MigrateSourceSQL($this->query(), array(), NULL, array('map_joinable' => FALSE));
//     $this->dependencies =  array('RPForumTopic');
//     $this->destination = new MigrateDestinationComment('comment_node_forum');//,

//     $this->map = new MigrateSQLMap($this->machineName,
//       array(
//         'nid' => array(
//           'type' => 'int',
//           'unsigned' => TRUE,
//           'not null' => TRUE,
//           // 'alias' => 'p'
//         )
//       ),
//       MigrateDestinationComment::getKeySchema()
//     );

//     $this->addFieldMapping('nid', 'field_parent_node_value')
//       ->sourceMigration('RPForumTopic');;
//     $this->addFieldMapping('uid', 'uid');
//     $this->addFieldMapping('subject', 'title')
//       ->callbacks(array($this, 'trimTitle'));
//     $this->addFieldMapping('comment_body', 'field_body2_value')
//       ->arguments(array('format' => 'panopoly_html_text'));
//     $this->addFieldMapping('created', 'created');
//     $this->addFieldMapping('changed', 'changed');

//     // Unmapped destination fields
//     $this->addUnmigratedDestinations(array(
//       'pid', 'path', 'thread', 'name', 'mail', 'homepage'
//     ));
//   }

//   /**
//    * Method to return the query used in the import.
//    * Can be called by sub classes and extended if needed.
//    */
//   protected function query() {
//     $query = Database::getConnection('default', 'd6.hernehill')->select('content_type_rp_forum_post', 'rp');
//     $query->leftJoin('node', 'n', 'rp.nid = n.nid');
//     $query->fields('n', array('nid', 'title', 'uid', 'created', 'changed'));
//     $query->fields('rp', array('vid','nid','field_body2_value','field_parent_node_value'));

//     // Dont pick out main topics, only nodes that are replies
//     $query->condition('field_parent_node_value', -1, '<>');

//     // A hack to test importing just 1 node
//     // $query->condition('field_parent_node_value', 442);

//     return $query;
//   }

//   protected function trimTitle($value) {
//     $value = drupal_substr($value, 0, 64);
//     return $value;
//   }
// }
