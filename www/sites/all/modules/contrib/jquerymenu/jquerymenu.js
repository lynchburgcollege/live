// $Id: jquerymenu.js,v 1.7 2010/05/05 07:50:55 aaronhawkins Exp $

(function ($) {

Drupal.behaviors.jquerymenu = {
    attach:function(context) {

  jqm_showit = function() {
    $(this).children('.jqm_link_edit').fadeIn();
  };
  jqm_hideit = function() {
    $(this).children('.jqm_link_edit').fadeOut();
  };
  $('ul.jquerymenu li').hover(jqm_showit, jqm_hideit);

  jqm_mouseenter = function() {
    $momma = $(this);
    if ($momma.hasClass('closed')){
      jqm_open($momma);
    }
  };

  jqm_mouseleave = function(){
    $momma = $(this);
    if ($momma.hasClass('open')){
      jqm_close($momma);
    }
  };

  function jqm_close(item) {
    $item = $(item);
    if (Drupal.settings.jquerymenu.animate === 1) {
      $($item.siblings('ul').children()).fadeOut('3000');
      $($item.children('ul')).slideUp('700');
    }
    $item.removeClass('open').addClass('closed');
    $item.children('span').removeClass('open').addClass('closed');
  }

  function jqm_open(item) {
    $item = $(item);
    if (Drupal.settings.jquerymenu.animate === 1) {
      $($item.siblings('ul').children()).hide().fadeIn('3000');
      $($item.children('ul')).slideDown('700');
    }
    $item.removeClass('closed').addClass('open');
    $item.children('span').removeClass('closed').addClass('open');
  }

$('ul.jquerymenu .active').parents('li').removeClass('closed').addClass('open');
$('ul.jquerymenu .active').parents('li').children('span.parent').removeClass('closed').addClass('open');

  if (Drupal.settings.jquerymenu.hover === 1) {
    $('ul.jquerymenu:not(.jquerymenu-processed)', context).addClass('jquerymenu-processed').each(function(){
      $(this).find('li.parent').hover(jqm_mouseenter, jqm_mouseleave);
    });
    $('ul.jquerymenu-processed span.parent').remove();
  }

  else if (Drupal.settings.jquerymenu.hover === 0) {
    $('ul.jquerymenu:not(.jquerymenu-processed)', context).addClass('jquerymenu-processed').each(function(){
      $(this).find("li.parent span.parent").click(function(){
        $element = $(this);
        $momma = $element.parent();
        if ($momma.hasClass('closed')){
          $momma.siblings('li').each(function (){
            if ($(this).hasClass('open')) {
             jqm_close($(this));
            }
          });
          jqm_open($momma);
        }
        else{
          jqm_close($momma);
        }
      });
    });
  }
}
};

})(jQuery);
