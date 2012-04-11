<div class="panel-display omega-grid lynchburg-12-threecol-5-5-2 equal-height-container" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="panel-panel grid-12 lynchburg-top equal-height-element">
    <div class="inside"><?php print $content['top']; ?></div>
  </div>

  <div class="panel-panel grid-5 lynchburg-left-main equal-height-element">
    <div class="inside"><?php print $content['left']; ?></div>
  </div>

  <div class="panel-panel grid-5 lynchburg-center-main equal-height-element">
    <div class="inside"><?php print $content['main']; ?></div>
  </div>

  <div class="panel-panel grid-2 lynchburg-right-main">
    <div class="inside"><?php print $content['right']; ?></div>
  </div>

  <div class="panel-panel grid-12 lynchburg-bottom equal-height-element">
    <div class="inside"><?php print $content['bottom']; ?></div>
  </div>

</div>
