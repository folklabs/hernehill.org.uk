(function ($) {
  Drupal.behaviors.faq = {
    attach:function (context, settings) {
      $('body').once('faq', function(event) {
        var locked = false;
        $('ul.faq-list .question').live('click', function (event) {
          if(locked) return false;
          locked = true;
          $(this).parent().find('.answer').stop(true, true).slideToggle('slow', function() {
            locked = false;
          });
        });
      });
    }
  };
}(jQuery));