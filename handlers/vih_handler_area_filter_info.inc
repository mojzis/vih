<?php

/**
 * @file
 * Contains views_handler_area_text handler.
 */

/**
 * Views area text handler.
 * @ingroup views_area_handlers Views' area handlers
*/
class vih_handler_area_filter_info extends views_handler_area {

  function option_definition() {
    // todo : list filters in view, allow to select which ones to deal with ...
    // todo : rendering options ?
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function options_submit(&$form, &$form_state) {
//    $form_state['values']['options']['format'] = $form_state['values']['options']['content']['format'];
 //   $form_state['values']['options']['content'] = $form_state['values']['options']['content']['value'];
    parent::options_submit($form, $form_state);
  }

  function render($empty = FALSE) {
    // this is a raw first attempt :) we will have to dive in it more, to be able to show data properly ...
    $checked_vals = array();
    foreach ($this->view->filter as $fname => $filter) {
      if (isset($filter->validated_exposed_input) && count($filter->validated_exposed_input) ) { //$fname == 'field_news_section_tid'
        $checked_vals[$fname] = array(
          'filter' => $fname,
          'vals' => $filter->validated_exposed_input,
          'type' => 'taxo',
          'vocabulary' => $filter->options['vocabulary'],
          );
        foreach ($checked_vals[$fname]['vals'] as $key => &$value) {
          $term = taxonomy_term_load($key);
          $value = $term->name;
        }
      }
    }
    if (count($checked_vals)) {
      $output = '<div class="tags"><span class="label">Filtered :<span>';
      foreach ($checked_vals as $fname => $fil) {
        foreach ($fil['vals'] as $tkey => $tname) {
          $output .= '<em>';
          $output .= $tname;
          $output .= '</em>';
        }
      }
      return $output;
    } else {
      // todo : no filter option into form
      return '';
    }



  }

}
