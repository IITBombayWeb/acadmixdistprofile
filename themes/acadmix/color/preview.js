/**
* DO NOT EDIT THIS FILE.
* See the following change record for more information,
* https://www.drupal.org/node/2815083
* @preserve
**/

(function ($, Drupal, drupalSettings) {
  Drupal.color = {
    logoChanged: false,
    bgChanged: false,
    callback: function callback(context, settings, $form) {
     
      var $colorPreview = $form.find('.color-preview');
      var $colorPalette = $form.find('.js-color-palette');


      $colorPreview.find('.color-preview-header').css('color', $colorPalette.find('input[name="palette[topnav]"]').val());
      // $colorPreview.find('').css('color', $colorPalette.find('input[name="palette[topnavtext]"]').val());
      $colorPreview.find('.color-preview-header, .color-preview-footer-wrapper').css('background-color', $colorPalette.find('input[name="palette[footer]"]').val());

    }
  };
})(jQuery, Drupal, drupalSettings);