<?php
/**
 * @file
 */
//module_load_include('inc', 'views', 'plugins/views_plugin_row');
//module_load_include('inc', 'views', 'plugins/views_plugin_row_fields');

class vih_addlink_row extends views_plugin_row_fields {
  function option_definition() {
    $options = parent::option_definition();
    $options['linkclasses'] = array('default' => '');
    $options['linkhref'] = array('default' => '');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['linkhref'] = array(
      '#type' => 'textfield',
      '#title' => 'Href',
      '#default_value' => isset($this->options['linkhref']) ? $this->options['linkhref'] : "",
      );
    $form['linkclasses'] = array(
      '#type' => 'textfield',
      '#title' => 'Classes',
      '#default_value' => isset($this->options['linkclasses']) ? $this->options['linkclasses'] : "",
      );
  }

  function render($row) {
    //dpm($row);
    //dpm($this);
    $r = parent::render($row);
    $rowindex = $this->view->row_index;
    // TODO : add check if tokenizing needed, like in views_plugin_style.inc
    // TODO : is there a nicer way to refer to the plgin ?
    $href = $this->view->style_plugin->tokenize_value($this->options['linkhref'],$rowindex);
    $link = l( $r, $href, array(
      'attributes' => array(
        'class' => array($this->options['linkclasses']),
        ),
      'html' => TRUE,
      ));
    return $link;
  }

}

