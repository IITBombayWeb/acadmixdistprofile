<?php

namespace Drupal\name\Plugin\migrate\cckfield;

use Drupal\migrate\Plugin\MigrationInterface;
use Drupal\migrate_drupal\Plugin\migrate\cckfield\CckFieldPluginBase;

/**
 * @MigrateCckField(
 *   id = "name",
 *   core = {7}
 * )
 */
class NameItem extends CckFieldPluginBase {

  /**
   * {@inheritdoc}
   */
  public function getFieldFormatterMap() {
    return [
      'name_formatter' => 'name_default',
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function getFieldWidgetMap() {
    return [
      'name_widget' => 'name_default',
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function processCckFieldValues(MigrationInterface $migration, $field_name, $data) {
    $process = [
      'plugin' => 'iterator',
      'source' => $field_name,
      'process' => [
        'title' => 'title',
        'given' => 'given',
        'middle' => 'middle',
        'family' => 'family',
        'generational' => 'generational',
        'credentials' => 'credentials',
      ],
    ];
    $migration->mergeProcessOfProperty($field_name, $process);
  }

}