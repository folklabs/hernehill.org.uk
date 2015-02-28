<?php


class HHNode6Migration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }

  protected function removeNewlinesFromText($value) {
    // drush_print($value);
    $value = preg_replace('/\<p\>\&nbsp;\<\/p\>/', '', $value);
    // drush_print($value);
    return $value;
  }
}

class UserMigration extends DrupalUser6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Set user picture field to null, no user pictures are imported
    $this->addFieldMapping('field_user_picture')
      ->defaultValue(0);
  }
}

/**
 * Migration class to test import of various date fields.
 */
class Profile2Migration extends Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    $this->dependencies = array('user');
    $this->description = t('Profile fields');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'uid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 Unique User ID',
          'alias' => 'u',
        )
      ),
      MigrateDestinationProfile2::getKeySchema()
    );

    $source_fields = array(
      'uid' => t('User ID'),
      'profile_streetaddress' => t(''),
      'profile_postcode' => t(''),
      'profile_typeofuser' => t(''),
    );
    $this->source = new MigrateSourceSQL($this->query(), array($source_fields), NULL, array('map_joinable' => FALSE));
    $this->destination = new MigrateDestinationProfile2('ol_personal_info');

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('user');

    $this->addFieldMapping('field_ol_address')->defaultValue('UK');
    $this->addFieldMapping('field_ol_address:thoroughfare', 'profile_streetaddress');
    $this->addFieldMapping('field_ol_address:postal_code', 'profile_postcode');

    $this->addFieldMapping('field_ol_personal_type_of_user', 'profile_typeofuser')
      ->callbacks(array($this, 'mapUserTypeValues'));
  }

  protected function mapUserTypeValues($value) {
    if ($value == 'Local Resident') {
      $value = 'resident';
    } elseif ($value == 'Local Trader') {
      $value = 'trader';
    } elseif ($value == 'Just interested') {
      $value = 'interested';
    }
    return $value;
  }

  public function prepareRow($row) {
    $profile_fields = Database::getConnection('default', 'd6.hernehill')
      ->select('profile_values', 'pv')
      ->fields('pv', array('fid', 'value'))
      ->condition('uid', $row->uid)
      ->execute()
      ->fetchAllKeyed();

    $row->profile_postcode = $profile_fields[2];
    $row->profile_streetaddress = $profile_fields[3];
    $row->profile_typeofuser = $profile_fields[4];
  }

  /**
   * Method to return the query used in the import.
   * Can be called by sub classes and extended if needed.
   */
  protected function query() {
    $query = Database::getConnection('default', 'd6.hernehill')->select('users', 'u');
    // $query->leftJoin('node', 'n', 'gi.nid = n.nid');
    $query->fields('u', array('uid'));
    $query->condition('u.uid', 1, '>'); // You do not want to mess with User-1
    return $query;
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

class NewsMigration extends HHNode6Migration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    // $this->sourceFields['f.field_audio_description'] = 'field_audio_description';
    // $this->sourceFields['News'] = 'Summary string from D6';

    parent::__construct($arguments);

    $this->addFieldMapping('uid', 'uid')
         ->sourceMigration('user');

    $this->addFieldMapping('body', 'body')
      ->callbacks(array($this, 'removeNewlinesFromText'));
    $this->addFieldMapping('body:format')
      ->defaultValue('panopoly_wysiwyg_text');
    $this->addFieldMapping('field_ol_tags', 8)
         ->sourceMigration('News_terms');
    $this->addFieldMapping('field_ol_tags:source_type')
      ->defaultValue('tid');
  }

  // protected function removeNewlinesFromText($value) {
  //   // drush_print($value);
  //   $value = preg_replace('/\<p\>\&nbsp;\<\/p\>/', '', $value);
  //   // drush_print($value);
  //   return $value;
  // }
}

class CampaignsMigration extends HHNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('user');

    $this->addFieldMapping('field_ol_description', 'field_overview');
    $this->addFieldMapping('field_ol_details', 'body')
      ->callbacks(array($this, 'removeNewlinesFromText'));
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

class EventMigration extends HHNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('user');
    $this->addFieldMapping('field_ol_description', 'field_eventteaser');
    $this->addFieldMapping('field_ol_details', 'body')
      ->callbacks(array($this, 'removeNewlinesFromText'));
    $this->addFieldMapping('field_ol_event_date', 'field_eventdate');
    $this->addFieldMapping('field_ol_wheelchair_accessible', 'field_wheelchair')
      ->callbacks(array($this, 'convertBoolean'));

    $this->addFieldMapping('field_ol_details:format')
      ->defaultValue('panopoly_wysiwyg_text');
  }

  protected function convertBoolean($value) {
    // drush_print($value);
    $value = ($value == "Yes") ? 1 : 0;
    return $value;
  }
}

class GalleryMigration extends HHNode6Migration {
  public function __construct(array $arguments) {
    // $this->sourceFields['News'] = 'Summary string from D6';
    parent::__construct($arguments);

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('user');
    $this->addFieldMapping('field_ol_description', 'field_overview');
    $this->addFieldMapping('field_ol_details', 'body')
      ->callbacks(array($this, 'removeNewlinesFromText'));
    $this->addFieldMapping('field_ol_details:format')
      ->defaultValue('panopoly_wysiwyg_text');
  }
}

class GroupMigration extends HHNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('user');
    $this->addFieldMapping('field_ol_description', 'field_overview');
    $this->addFieldMapping('field_ol_details', 'body')
      ->callbacks(array($this, 'removeNewlinesFromText'));
    $this->addFieldMapping('field_ol_details:format')
      ->defaultValue('panopoly_wysiwyg_text');
    $this->addFieldMapping('pathauto', FALSE);
  }
}

class ServiceMigration extends HHNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('user');
    $this->addFieldMapping('field_ol_description', 'field_tags');
    $this->addFieldMapping('field_ol_details', 'body')
      ->callbacks(array($this, 'removeNewlinesFromText'));
    $this->addFieldMapping('field_ol_website', 'field_website');
    $this->addFieldMapping('field_ol_email', 'field_service_email');
    $this->addFieldMapping('field_ol_telephone', 'field_telephonenumber');
    $this->addFieldMapping('field_ol_opening_hours', 'field_openinghours');
    $this->addFieldMapping('field_ol_twitter', 'field_servicetwitter');

    $this->addFieldMapping('field_ol_details:format')
      ->defaultValue('panopoly_wysiwyg_text');
    // $this->addFieldMapping('field_ol_local_business_category', 8)
    //      ->sourceMigration('News_terms')
    //      ->arguments(array('source_type' => 'tid'));
    $this->addFieldMapping('field_ol_business_tags', 4)
         ->sourceMigration('service_tags_terms');
    $this->addFieldMapping('field_ol_business_tags:source_type')
      ->defaultValue('tid');
  }
}

class GroupPostMigration extends HHNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('user');
    $this->addFieldMapping('field_ol_details', 'body');
    $this->addFieldMapping('body:format')
      ->defaultValue('panopoly_wysiwyg_text');
  }
}


class Drupal6GalleryImageMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = 'Image table data';
    $table_name = 'field_data_field_ol_images';
    $this->map = new MigrateSQLMap($this->machineName,
      array('nid' => array(
              'type' => 'int',
              'unsigned' => TRUE,
              'not null' => TRUE,
             )
           ),
        MigrateDestinationTable::getKeySchema($table_name)
      );
    $this->source = new MigrateSourceSQL($this->query(), array(), NULL, array('map_joinable' => FALSE));
    $this->destination = new MigrateDestinationTable($table_name);
    // Mapped fields
    $this->removeFieldMapping('nid');
    $this->addFieldMapping('entity_type')
      ->defaultValue('node');
    $this->addFieldMapping('bundle')
      ->defaultValue('ol_photo_album');
    $this->addFieldMapping('deleted')
      ->defaultValue('0');
    $this->addFieldMapping('entity_id', 'field_gallery_nid')
      ->sourceMigration('Gallery');
    $this->addFieldMapping('revision_id')
      ->defaultValue('0');
    $this->addFieldMapping('language')
      ->defaultValue('und');
    $this->addFieldMapping('delta', 'field_gallery_nid')
      ->callbacks(array($this, 'calcDelta'));
    $this->addFieldMapping('field_ol_galleryimages_fid', 'field_gallery_image_fid')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_ol_images_alt')
      ->defaultValue('');

    // TODO: what should description be mapped to if not title?
    $this->addFieldMapping('field_ol_images_title', 'new_title')
      ->callbacks(array($this, 'trimTitle'));
    $this->addFieldMapping('field_ol_images_width')
      ->defaultValue('100');
    $this->addFieldMapping('field_ol_images_height')
      ->defaultValue('100');

    $this->deltas = array();
  }

  /**
   * Method to return the query used in the import.
   * Can be called by sub classes and extended if needed.
   */
  protected function query() {
    $query = Database::getConnection('default', 'd6.hernehill')->select('content_type_gallery_image', 'gi');
    $query->leftJoin('node', 'n', 'gi.nid = n.nid');
    $query->fields('n', array('nid', 'title', 'uid', 'created', 'changed'));
    $query->fields('gi', array('nid', 'field_gallery_image_fid', 'field_gallery_nid', 'field_gallerypicdescription_value'));

    // A hack to test importing just 1 node
    // $query->condition('rp.nid', 442);

    return $query;
  }

  public function prepareRow($row) {
    // drush_print_r($row->title);
    // drush_print_r($row->field_gallerypicdescription_value);
    $row->new_title = "$row->title. $row->field_gallerypicdescription_value";
    // drush_print_r($row->new_title);
  }

  protected function calcDelta($value) {
    // drush_print_r('calcDelta');
    // drush_print_r($value);
    // Start delta at 0 or increment
    if ($this->deltas[$value] == nil) {
      // drush_print_r('init delta');
      $this->deltas[$value] = 0;
    }
    else {
      // drush_print_r('increment delta');
      $this->deltas[$value] = $this->deltas[$value] + 1;
    }
    // drush_print_r($this->deltas[$value]);
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
      ->callbacks(array($this, 'stripBlankLines'));
    $this->addFieldMapping('comment_body:format')
      ->defaultValue('panopoly_html_text');
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



