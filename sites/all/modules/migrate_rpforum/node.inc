<?php

/**
 * Import hierarchy of forums from RPForum to core forum.
 * Core forum uses vocabulary terms, under the Forums vocabulary, to
 * create the hierarchy of forums.
 */
class RPForumForumsMigration extends Migration {
  public function __construct($settings_machine_name) {
    parent::__construct($settings_machine_name);
    $this->description = t('Migrate forum structure from RPForum.');

    /**
     * Get the bits we need, the sort order ensures root level parents appear
     * first and that we get the children in the correct order.
     */
    $this->source = new MigrateSourceSQL($this->query(), array(), NULL, array('map_joinable' => FALSE));

    // Built in destination for Taxonomy Terms
    $this->destination = new MigrateDestinationTerm('forums');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'tid' => array('type' => 'int', 'unsigned' => TRUE, 'not null' => TRUE, 'description' => 'Source term ID')
      ),
      MigrateDestinationTerm::getKeySchema()
    );
    // Cannot import tid as it must be created new during import
    $this->addFieldMapping('name', 'name');
    $this->addFieldMapping('description', 'description');
    $this->addFieldMapping('weight', 'weight');
    $this->addUnmigratedDestinations(array('parent', 'parent_name', 'path'));
  }

  /**
   * Method to return the query used in the import.
   * Can be called by sub classes and extended if needed.
   */
  protected function query() {
   return Database::getConnection('default', 'd6.hernehill')
     ->select('term_data', 'td')
     ->fields('td', array('tid', 'vid', 'name', 'description', 'weight'))
     ->condition('td.vid', 3);
  }
}

/**
 * Import forum topics from RP Forum to core forum nodes.
 */
class RPForumTopicMigration extends Migration {
  public function __construct($settings_machine_name) {
    parent::__construct($settings_machine_name);
    $this->description = t('Migrate individual forum topics from RP Forum.');
    $this->source = new MigrateSourceSQL($this->query(), array(), NULL, array('map_joinable' => FALSE));

    $this->destination = new MigrateDestinationNode('forum');

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

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('user');
    $this->addFieldMapping('taxonomy_forums', 'tid') //->defaultValue(30)
      ->sourceMigration('RPForumForums');
    $this->addFieldMapping('taxonomy_forums:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'field_body2_value');
    $this->addFieldMapping('body:format')
      ->defaultValue('panopoly_html_text');
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
    $query = Database::getConnection('default', 'd6.hernehill')->select('content_type_rp_forum_post', 'rp');
    $query->leftJoin('node', 'n', 'rp.nid = n.nid');
    $query->leftJoin('term_node', 'tn', 'tn.nid = n.nid');
    $query->fields('n', array('nid', 'title', 'uid', 'created', 'changed'));
    $query->fields('tn', array('nid', 'tid'));
    $query->fields('rp', array('vid','nid','field_body2_value','field_parent_node_value'));
    $query->condition('field_parent_node_value', -1);

    // A hack to test importing just 1 node
    // $query->condition('rp.nid', 442);

    return $query;
  }
}

/**
 * Import forum reply posts from RP Forum to core forum comments.
 */
class RPForumPostMigration extends Migration {
  public function __construct($settings_machine_name) {
    parent::__construct($settings_machine_name);
    $this->description = t('Migrate individual forum posts from RP Forum.');
    $this->source = new MigrateSourceSQL($this->query(), array(), NULL, array('map_joinable' => FALSE));
    $this->dependencies =  array('RPForumTopic');
    $this->destination = new MigrateDestinationComment('comment_node_forum');//,

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          // 'alias' => 'p'
        )
      ),
      MigrateDestinationComment::getKeySchema()
    );

    $this->addFieldMapping('nid', 'field_parent_node_value')
      ->sourceMigration('RPForumTopic');
    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('user');
    $this->addFieldMapping('subject', 'title')
      ->callbacks(array($this, 'trimTitle'));
    $this->addFieldMapping('comment_body', 'field_body2_value');
    $this->addFieldMapping('comment_body:format')
      ->defaultValue('panopoly_html_text');
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('changed', 'changed');

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array(
      'pid', 'path', 'thread', 'name', 'mail', 'homepage'
    ));
  }

  /**
   * Method to return the query used in the import.
   * Can be called by sub classes and extended if needed.
   */
  protected function query() {
    $query = Database::getConnection('default', 'd6.hernehill')->select('content_type_rp_forum_post', 'rp');
    $query->leftJoin('node', 'n', 'rp.nid = n.nid');
    $query->fields('n', array('nid', 'title', 'uid', 'created', 'changed'));
    $query->fields('rp', array('vid','nid','field_body2_value','field_parent_node_value'));

    // Dont pick out main topics, only nodes that are replies
    $query->condition('field_parent_node_value', -1, '<>');

    // A hack to test importing just 1 node
    // $query->condition('field_parent_node_value', 442);

    return $query;
  }

  protected function trimTitle($value) {
    $value = drupal_substr($value, 0, 64);
    return $value;
  }
}
