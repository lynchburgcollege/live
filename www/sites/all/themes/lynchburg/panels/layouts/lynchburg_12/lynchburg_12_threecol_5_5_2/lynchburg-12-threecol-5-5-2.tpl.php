<div class="panel-display omega-grid lynchburg-12-threecol-5-5-2 equal-height-container" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="panel-panel grid-5 lynchburg-left-sidebar equal-height-element">
    <div class="inside"><?php print $content['left']; ?></div>
  </div>

  <div class="panel-panel grid-5 lynchburg-main equal-height-element">
    <div class="inside"><?php print $content['main']; ?></div>
  </div>

  <div class="panel-panel grid-2 lynchburg-right-sidebar">
    <div class="inside"><?php print $content['right']; ?></div>
  </div>

</div>
