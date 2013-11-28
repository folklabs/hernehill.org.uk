<?php


class NewsMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    // $this->sourceFields['f.field_audio_description'] = 'field_audio_description';
    $this->sourceFields['News'] = 'Summary string from D6';

    parent::__construct($arguments);

    $this->addUnmigratedSources(array('field_audio_description'), t('Do Not Migrate'));

    // $this->addFieldMapping('body', 'body')
    //   ->arguments(array('format' => 'panopoly_html_text'));

    $this->addFieldMapping('body:format')
      ->defaultValue('panopoly_wysiwyg_text');
    // $this->addFieldMapping('News', 'field_ol_tags');
    $this->addFieldMapping('field_ol_tags', 8)
         ->sourceMigration('News_terms')
         ->arguments(array('source_type' => 'tid'));

    // $this->addFieldMapping('field_image', 'field_lead_graphic')
    //      ->sourceMigration('Image');
    // // Note that we map migrated terms by the vocabulary ID.
    // $this->addFieldMapping('field_countries', '1')
    //      ->sourceMigration('Countries')
    //      ->arguments(array('source_type' => 'tid'));
    // $this->addFieldMapping('field_topics', '2')
    //      ->sourceMigration('Topics')
    //      ->arguments(array('source_type' => 'tid'));
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

    $this->addFieldMapping('uid', 'uid');
    // $this->addFieldMapping('taxonomy_forums', 'tid') //->defaultValue(30)
    //   ->sourceMigration('RPForumForums')
    //   ->arguments(array('source_type' => 'tid'));
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body')
      ->arguments(array('format' => 'panopoly_html_text'));
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('changed', 'changed');

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array('is_new', 'promote',
      'revision', 'language', 'sticky', 'revision_uid', 'path','tnid'));
  }

  /**
   * Method to return the query used in the import.
   * Can be called by sub classes and extended if needed.
   */
  protected function query() {
    $query = Database::getConnection('default', 'd6.hernehill')->select('node', 'n');

    $query->leftJoin('node_comments', 'nc', 'n.nid = nc.cid');
    $query->leftJoin('node', 'n2', 'nc.nid = n2.nid');

    $query->fields('n', array('nid', 'title', 'uid', 'type', 'created', 'changed'));
    $query->fields('n2', array('nid', 'title', 'uid', 'type', 'created', 'changed'));
    $query->fields('nc', array('nid', 'cid'));
    // $query->fields('tn', array('nid', 'tid'));
    // $query->fields('rp', array('vid','nid','field_body2_value','field_parent_node_value'));
    $query->condition('n.type', 'comment');
    $query->condition('n2.type', $this->destNodeType);
    // $query->condition('n2.type', 'group');
    // $query->condition('n2.type', 'campaigns');
    // $query->condition('n2.type', 'blog');
    // $query->condition('n2.type', 'event');
    // $query->condition('n2.type', 'news');

    // drush_print('foo');
    // $result = $query->execute();
    // foreach($result as $r) {
    //   drush_print('r');
    //   drush_print_r($r);
    // }
    // A hack to test importing just 1 node
    // $query->condition('rp.nid', 442);

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
    parent::__construct($settings_machine_name, 'comment_node_news', 'news');
  }
}

// class HHBlogCommentNodeMigration extends Migration {
//   public function __construct($settings_machine_name, $dest_comment_type, $node_type) {
//     parent::__construct($settings_machine_name, 'comment_node_blog', 'blog');
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
