<?php

/**
 * @file
 * Lists available colors and color schemes for the Acadmix theme.
 */

$info = [
  // Available colors and color labels used in theme.
  'fields' => [
    'topnav' => t('Header and Footer Text color'),
    'footer' => t('Header and Footer background'),
    'text' => t('Website Text color'),
    'link' => t('Link color'),
  ],
  // Pre-defined color schemes.
  'schemes' => [
    'default' => [
      'title' => t('Acadmix (default)'),
      'colors' => [
        'topnav' => '#ffffff',
        'footer' => '#444444',
        'text' => ' #343536',
        'link' => '#337ab7',
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