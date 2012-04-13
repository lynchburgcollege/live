<div class="panel-display omega-grid lynchburg-12-twocol-5-7-bricks" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if ($content['top']) : ?>
  <div class="panel-panel grid-12 lynchburg-top">
    <div class="inside"><?php print $content['top']; ?></div>
  </div>
  <?php endif; ?>

  <?php if ($content['left_above'] || $content['rignt_above']) : ?>
  <div class="clearfix equal-height-container">
    <div class="panel-panel grid-5 equal-height-element">
      <div class="inside"><?php print $content['left_above']; ?></div>
    </div>
    <div class="panel-panel grid-7 equal-height-element">
      <div class="inside"><?php print $content['right_above']; ?></div>
    </div>
  </div>
  <?php endif; ?>

  <?php if ($content['middle']) : ?>
  <div class="panel-panel grid-12 lynchburg-middle">
    <div class="inside"><?php print $content['middle']; ?></div>
  </div>
  <?php endif; ?>

  <?php if ($content['left_below'] || $content['rignt_below']) : ?>
  <div class="clearfix equal-height-container">
    <div class="panel-panel grid-5 equal-height-element">
      <div class="inside"><?php print $content['left_below']; ?></div>
    </div>
    <div class="panel-panel grid-7 equal-height-element">
      <div class="inside"><?php print $content['right_below']; ?></div>
    </div>
  </div>
  <?php endif; ?>

  <?php if ($content['bottom']) : ?>
  <div class="panel-panel grid-12 lynchburg-bottom">
    <div class="inside"><?php print $content['bottom']; ?></div>
  </div>
  <?php endif; ?>

</div>
