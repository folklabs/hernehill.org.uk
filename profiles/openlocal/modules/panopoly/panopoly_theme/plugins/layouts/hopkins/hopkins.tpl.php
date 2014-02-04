<?php
/**
 * @file
 * Template for OpenLocal Hopkins.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display hopkins clearfix <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="hopkins-container hopkins-header clearfix panel-panel">
    <div class="hopkins-container-inner hopkins-header-inner panel-panel-inner">
      <?php print $content['header']; ?>
    </div>
  </div>

  <div class="hopkins-container hopkins-column-content clearfix">

    <div class="hopkins-content-container">
      <div class="hopkins-content-container-inner">

        <div class="hopkins-column-content-region hopkins-content-header panel-panel clearfix">
          <div class="hopkins-column-content-region-inner hopkins-content-header-inner panel-panel-inner">
            <?php print $content['contentheader']; ?>
          </div>
        </div>

        <div class="hopkins-content-container-column-container clearfix">
          <div class="hopkins-column-content-region hopkins-content-column1 hopkins-column panel-panel">
            <div class="hopkins-column-content-region-inner hopkins-content-column1-inner hopkins-column-inner panel-panel-inner">
              <?php print $content['contentcolumn1']; ?>
            </div>
          </div>
          <div class="hopkins-column-content-region hopkins-content-column2 hopkins-column panel-panel">
            <div class="hopkins-column-content-region-inner hopkins-content-column2-inner hopkins-column-inner panel-panel-inner">
              <?php print $content['contentcolumn2']; ?>
            </div>
          </div>
        </div><!-- /.hopkins-content-container-column-container -->

      </div>
    </div><!-- /.hopkins-content-container -->

    <div class="hopkins-sidebar hopkins-column-content-region hopkins-column panel-panel">
      <div class="hopkins-sidebar-inner hopkins-column-content-region-inner hopkins-column-inner panel-panel-inner">
        <?php print $content['sidebar']; ?>
      </div>
    </div>

  </div><!-- /.hopkins-column-content -->

</div><!-- /.hopkins -->
