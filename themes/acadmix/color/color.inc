<?php

/**
 * @file
 * Lists available colors and color schemes for the Acadmix theme.
 */

$info = [
  // Available colors and color labels used in theme.
  'fields' => [
    'topnav' => t('Header background'),
    'footer' => t('header and Footer background'),
  ],
  // Pre-defined color schemes.
  'schemes' => [
    'default' => [
      'title' => t('Blue Lagoon (default)'),
      'colors' => [
        'topnav' => '#4c4c4c',
        'footer' => '#444444',
      ],
    ],
    'firehouse' => [
      'title' => t('Firehouse'),
      'colors' => [
      'topnav' => '#4d4f4c',
      'footer' => '#edf2fe',        
      ],
    ],
  ],

  // CSS files (excluding @import) to rewrite with new color scheme.
  'css' => [
    'css/colors.css',
  ],

  // Files to copy.
  'copy' => [
    'logo.png',
  ],

  // Gradient definitions.
  'gradients' => [
    [
      // (x, y, width, height).
      //'dimension' => [0, 0, 0, 0],
      // Direction of gradient ('vertical' or 'horizontal').
      //'direction' => 'vertical',
      // Keys of colors to use for the gradient.
      //'colors' => ['top', 'bottom'],
    ],
  ],

  // Preview files.
  'preview_library' => 'acadmix/color.preview',
  'preview_html' => 'color/preview.html',

  // Attachments.
  '#attached' => [
    'drupalSettings' => [
      'color' => [
        // Put the logo path into JavaScript for the live preview.
        'logo' => theme_get_setting('logo.url', 'acadmix'),
      ],
    ],
  ],
];