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
      'title' => 'Fields with a link',
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
    'title_tokenizer' => array(
      'title' => t('Tokenize title'),
      'handler' => 'views_plugin_display_extender_titletoken',
      ),

    );
  return $plugins;
}
