<div class="panel-display omega-grid lynchburg-12-threecol-3-6-3 equal-height-container" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if ($content['top']) : ?>
  <div class="panel-panel grid-12 lynchburg-top">
    <div class="inside"><?php print $content['top']; ?></div>
  </div>
  <?php endif; ?>

  <div class="panel-panel grid-9 lynchburg-main equal-height-element">
    <div class="inside"><?php print $content['main']; ?></div>
  </div>

  <div class="panel-panel grid-3 lynchburg-right-sidebar equal-height-element">
    <div class="inside"><?php print $content['right']; ?></div>
  </div>

  <?php if ($content['bottom']) : ?>
  <div class="panel-panel grid-12 lynchburg-bottom">
    <div class="inside"><?php print $content['bottom']; ?></div>
  </div>
  <?php endif; ?>

</div>
