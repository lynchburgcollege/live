<div class="panel-display omega-grid lc-12-threecol-3-6-3 equal-height-container" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="panel-panel grid-3 lc-left-sidebar equal-height-element">
    <div class="inside"><?php print $content['left']; ?></div>
  </div>

  <div class="panel-panel grid-6 lc-main equal-height-element">
    <div class="inside"><?php print $content['main']; ?></div>
  </div>

  <div class="panel-panel grid-3 lc-right-sidebar">
    <div class="inside"><?php print $content['right']; ?></div>
  </div>

</div>
