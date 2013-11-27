<?php

/**
 * Import hierarchy of forums from RPForum to core forum.
 * Core forum uses vocabulary terms, under the Forums vocabulary, to
 * create the hierarchy of forums.
 */
// class HHCommentMigration extends Migration {
//   public function __construct($settings_machine_name) {
//     parent::__construct($settings_machine_name);
//     $this->description = t('Migrate Comment nodes.');

//     /**
//      * Get the bits we need, the sort order ensures root level parents appear
//      * first and that we get the children in the correct order.
//      */
//     $this->source = new MigrateSourceSQL($this->query(), array(), NULL, array('map_joinable' => FALSE));

//     // Built in destination for Taxonomy Terms
//     $this->destination = new MigrateDestinationTerm('forums');

//     $this->map = new MigrateSQLMap($this->machineName,
//       array(
//         'tid' => array('type' => 'int', 'unsigned' => TRUE, 'not null' => TRUE, 'description' => 'Source term ID')
//       ),
//       MigrateDestinationTerm::getKeySchema()
//     );
//     // Cannot import tid as it must be created new during import
//     $this->addFieldMapping('name', 'name');
//     $this->addFieldMapping('description', 'description');
//     $this->addFieldMapping('weight', 'weight');
//     $this->addUnmigratedDestinations(array('parent', 'parent_name', 'path'));
//   }

//   /**
//    * Method to return the query used in the import.
//    * Can be called by sub classes and extended if needed.
//    */
//   protected function query() {
//    return Database::getConnection('default', 'd6.hernehill')
//      ->select('term_data', 'td')
//      ->fields('td', array('tid', 'vid', 'name', 'description', 'weight'))
//      ->condition('td.vid', 3);
//   }
// }

/**
 * Import forum topics from RP Forum to core forum nodes.
 */
class HHCommentNodeMigration extends Migration {
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

    drush_print('foo');
    $result = $query->execute();
    foreach($result as $r) {
      drush_print('r');
      drush_print_r($r);
    }
    // A hack to test importing just 1 node
    // $query->condition('rp.nid', 442);

    return $query;
  }
}

class HHGroupCommentNodeMigration extends HHCommentNodeMigration {
  public function __construct($settings_machine_name, $dest_comment_type, $node_type) {
    parent::__construct($settings_machine_name, 'comment_node_group', 'group');
  }
}

class HHCampaignsCommentNodeMigration extends HHCommentNodeMigration {
  public function __construct($settings_machine_name, $dest_comment_type, $node_type) {
    parent::__construct($settings_machine_name, 'comment_node_campaigns', 'campaigns');
  }
}

class HHEventCommentNodeMigration extends HHCommentNodeMigration {
  public function __construct($settings_machine_name, $dest_comment_type, $node_type) {
    parent::__construct($settings_machine_name, 'comment_node_event', 'event');
  }
}

class HHNewsCommentNodeMigration extends HHCommentNodeMigration {
  public function __construct($settings_machine_name, $dest_comment_type, $node_type) {
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
