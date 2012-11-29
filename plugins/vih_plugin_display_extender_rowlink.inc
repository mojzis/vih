<?php

/**
 * @file
 * Definition of views_plugin_display_extender_rowlink.
 */

/**
 * @todo try to declare plugins and change the plugin if the link is set.
 * @todo dont forget about tokens
 * @todo allow to set only 1 display or all
 *
 */
class vih_plugin_display_extender_rowlink extends views_plugin_display_extender {
  function init(&$view, &$display) {
    $this->view = $view;
    $this->display = $display;
  }


  /**
   * Provide a form to edit options for this plugin.
   */
  function options_definition_alter(&$options) {
    //dpm('fantomas');
    $options['linkclasses'] = array('default' => '');
    $options['linkhref'] = array('default' => '');
  }

  /**
   * Provide a form to edit options for this plugin.
   */
  function options_form(&$form, &$form_state) {
    switch ($form_state['section']) {
      case 'rowlink':
        $form['linkhref'] = array(
          '#type' => 'textfield',
          '#title' => 'Href',
          '#default_value' => $this->display->options['linkhref'],
          );
        $form['linkclasses'] = array(
          '#type' => 'textfield',
          '#title' => 'Classes',
          '#default_value' => $this->display->options['linkclasses'],
          );
      break;
    }
  }



  /**
   * Provide the default summary for options in the views UI.
   *
   * This output is returned as an array.
   */
  function options_summary(&$categories, &$options) {
    // TODO: find out if it was set or not
    $options['rowlink'] = array(
      'category' => 'format',
      'title' => t('Link around the row'),
      'value' => 'see',
      'desc' => t('Add a link around the entire row.'),
    );
  }

  function options_submit(&$form, &$form_state) {
    switch ($form_state['section']) {
      case 'rowlink':
        $this->display->set_option('linkhref',$form_state['values']['linkhref']);
        $this->display->set_option('linkclasses',$form_state['values']['linkclasses']);
      break;
    }
  }
}
