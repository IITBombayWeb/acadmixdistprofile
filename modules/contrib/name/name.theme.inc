<?php

/**
 * @file
 * Theme functions for name module.
 */

use Drupal\Component\Utility\SafeMarkup;
use Drupal\name\NameFormatParser;

/**
 * Wrapper theming function for name_format().
 */
function theme_name_item($variables) {
  $variables['settings'] += array(
    'markup' => 0,
  );
  $format = name_get_format_by_machine_name($variables['format']);
  if (empty($format)) {
    $format = name_get_format_by_machine_name('default');
  }
  return NameFormatParser::parse($variables['item'], $format, $variables['settings']);
}

/**
 * Themes a list of names.
 *
 * Note: This function expects a list of sanitised name items.
 */
function theme_name_item_list($variables) {
  $items = $variables['items'];
  if (empty($items)) {
    return '';
  }
  $original_count = count($items);
  if ($original_count == 1) {
    return array_pop($items);
  }
  $settings = $variables['settings'];
  $settings += array(
    'output' => 'default', // default, plain, or raw
    'multiple_delimiter' => ', ',
    'multiple_and' => 'text', // and or symbol
    'multiple_delimiter_precedes_last' => 'never', // contextual, always, never
    'multiple_el_al_min' => 3,
    'multiple_el_al_first' => 1,
  );
  $delimiter = $settings['multiple_delimiter'];
  if ($settings['output'] == 'default') {
    $etal = t('<em>et al</em>', array(), array('context' => 'name'));
    $delimiter = SafeMarkup::checkPlain($delimiter);
  }
  else {
    $etal = t('et al', array(), array('context' => 'name'));
    if ($settings['output'] == 'plain') {
      $delimiter = strip_tags($delimiter);
    }
  }
  $t_args = array(
    '@delimiter' => $delimiter,
    '@etal' => $etal,
  );
  if ($original_count > $settings['multiple_el_al_min']) {
    $limit = min(array($settings['multiple_el_al_min'], $settings['multiple_el_al_first']));
    $items = array_slice($items, 0, $limit);
    if (count($items) == 1) {
      $t_args['@name'] = $items[0];
      return t('@name @etal', $t_args);
    }
    else {
      $t_args['@names'] = implode($delimiter . ' ', $items);
      return t('@names@delimiter @etal', $t_args);
    }
  }
  else {
    $t_args['@lastname'] = array_pop($items);
    $t_args['@names'] = implode($delimiter . ' ', $items);
    if ($settings['multiple_and'] == 'text') {
      $t_args['@and'] = t('and', array(), array('context' => 'name'));
    }
    else {
      $t_args['@and'] = $settings['output'] == 'default' ? '&amp' : '&';
    }

    // Strange rule from http://citationstyles.org/downloads/specification.html.
    if (($settings['multiple_delimiter_precedes_last'] == 'contextual' && $original_count > 2)
        || $settings['multiple_delimiter_precedes_last'] == 'always') {
      return t('@names@delimiter @and @lastname', $t_args);
    }
    else {
      return t('@names @and @lastname', $t_args);
    }
  }
}

