<?php
/**
 * @file
 * views
 */

/**
 * function refces_views_plugins
 */
function vih_views_plugins() {
  $plugins = array();
  $plugins['row'] = array(
    'vih_addlink_row' => array(
      'title' => 'add link',
      'help' => 'display link',
      'theme' => 'views_view_fields',
      'parent' => 'views_plugin_row_fields',
      'handler' => 'vih_addlink_row',
      'uses fields' => TRUE,
      'uses options' => TRUE,
      'type' => 'normal'
    ),
  );
  $plugins['display_extender'] = array(
    'rowlink' => array(
      'title' => t('Row link'),
      'handler' => 'vih_plugin_display_extender_rowlink',
      ),
    );
  return $plugins;
}
