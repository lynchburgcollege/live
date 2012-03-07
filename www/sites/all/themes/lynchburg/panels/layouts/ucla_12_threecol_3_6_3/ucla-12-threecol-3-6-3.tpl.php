<div class="panel-display omega-grid ucla-12-threecol-3-6-3 equal-height-container" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="panel-panel grid-3 ucla-left-sidebar equal-height-element">
    <div class="inside"><?php print $content['left']; ?></div>
  </div>

  <div class="panel-panel grid-6 ucla-main equal-height-element">
    <div class="inside"><?php print $content['main']; ?></div>
  </div>

  <div class="panel-panel grid-3 ucla-right-sidebar">
    <div class="inside"><?php print $content['right']; ?></div>
  </div>

</div>
