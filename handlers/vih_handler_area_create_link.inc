<?php

/**
 * @file
 * Views_handler for area to show a create link.
 */

/**
 * Views area text handler.
 * @ingroup views_area_handlers Views' area handlers
*/
class vih_handler_area_create_link extends views_handler_area {

  function option_definition() {
    $options = parent::option_definition();
    //TODO: add a css class option
    //TODO: add a link text / image option
    $options['typetocreate'] = array('default' => 'node');
    $options['bundletocreate'] = array('default' => 'page');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['typetocreate'] = array(
      '#type' => 'textfield',
      '#title' => 'Type to create',
      '#default_value' => isset($this->options['typetocreate']) ? $this->options['typetocreate'] : "",
    );
    $form['bundletocreate'] = array(
      '#type' => 'textfield',
      '#title' => 'Bundle to create',
      '#default_value' => isset($this->options['bundletocreate']) ? $this->options['bundletocreate'] : "",
    );

  }

  function options_submit(&$form, &$form_state) {
//    $form_state['values']['options']['format'] = $form_state['values']['options']['content']['format'];
 //   $form_state['values']['options']['content'] = $form_state['values']['options']['content']['value'];
    parent::options_submit($form, $form_state);
  }

  function render($empty = FALSE) {
    // TODO: find out the path in metadata ?
    $path = $this->options['typetocreate'] . '/add/' . $this->options['bundletocreate'];
    // TODO: return link
    $link_options = array();
    $link_options['query'] = drupal_get_destination();
    return l(t('Create new'),$path, $link_options);
    dpm($this);
  }

}
