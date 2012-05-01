<?php
/**
 * @file
 * Provides the LC Event search pane
 */

$plugin = array(
  'title' => t('News Archives Month Picker'),
  'description' => t('Display News month date picker.'),
  'single' => TRUE,
  'content_types' => array('lc_news_date_picker_pane'),
  'render callback' => 'news_date_picker_content_type_render',
  'defaults' => array(),
  'edit form' => 'news_date_picker_content_type_edit_form',
  'category' => array(t('LC'), -9),
);

/**
 * Run-time rendering of the body of the block.
 *
 * @param $subtype
 * @param $conf
 *   Configuration as done at admin time.
 * @param $args
 * @param $context
 *   Context - in this case we don't have any.
 *
 * @return
 *   An object with at least title and content members.
 */
function news_date_picker_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  // Get current date.
  $arguments = explode('/', $_GET['q']);
  $active_search_terms = '';
  if (isset($arguments[1])) {
    $active_date = $arguments[1];
    if (strpos($active_date, '--') !== FALSE) {
      $date_parts = explode('--', $active_date);
      $active_date = $date_parts[1];
    }
  }
  $date = date_parse($active_date);
  $current_month = $date['month'];
  $current_year = $date['year'];
  // Get news category.
  if (isset($_GET['category'])) {
    $tid = $_GET['category'];
    $term = taxonomy_term_load($tid);
    if (isset($term->name)) {
      $category = $term->name;
    }
  }

  // Get previous year.
  $prev_year = $current_year - 1;
  // Get next year.
  $next_year = $current_year + 1;

  // Find out if the previous and next years have news articles.
  $prev_year_link = FALSE;
  $next_year_link = FALSE;
  $content_type = 'news_article';
  $query = "SELECT DISTINCT DATE_FORMAT(field_date_value, '%Y') AS year FROM {field_data_field_date} WHERE DATE_FORMAT(field_date_value, '%Y') = :year AND bundle = :content_type";
  $result = db_query($query, array(':year' => $prev_year, ':content_type' => $content_type))->fetchAll(PDO::FETCH_ASSOC);
  if (count($result)) {
    $prev_year_link = TRUE;
  }
  $content_type = 'news_article';
  $query = "SELECT DISTINCT DATE_FORMAT(field_date_value, '%Y') AS year FROM {field_data_field_date} WHERE DATE_FORMAT(field_date_value, '%Y') = :year AND bundle = :content_type";
  $result = db_query($query, array(':year' => $next_year, ':content_type' => $content_type))->fetchAll(PDO::FETCH_ASSOC);
  if (count($result)) {
    $next_year_link = TRUE;
  }

  // Find out which months have news articles.
  $query = "SELECT DISTINCT DATE_FORMAT(field_date_value, '%c') AS month FROM {field_data_field_date} WHERE DATE_FORMAT(field_date_value, '%Y') = :year AND bundle = :content_type";
  $result = db_query($query, array(':year' => $current_year, ':content_type' => $content_type))->fetchAll(PDO::FETCH_ASSOC);
  $active_months = array();
  foreach ($result as $key => $value) {
    $active_months[] = $value['month'];
  }

  $block->title = check_plain("News Archives");

  $block->content = '<div class="lc-news-month-picker">';
  // Block header.
  $block->content .= '<div class="lc-news-month-picker-header">';
  $block->content .= $prev_year_link ? l('<', 'news/' . $prev_year . '-01-01--' . $prev_year . '-12-31', array('attributes' => array ('class' => array('lc-news-previous-link')))) : '<span class="lc-news-previous-link">&lt;</span>';
  $block->content .= '<span class="lc-news-current">' . $current_year . '</span>';
  $block->content .= $next_year_link ? l('>',  'news/' . $next_year . '-01-01--' . $next_year . '-12-31', array('attributes' => array ('class' => array('lc-news-next-link')))) : '<span class="lc-news-next-link">&gt;</span>';
  $block->content .= '</div>';
  // Block body.
  $block->content .= '<div class="lc-news-month-picker-body">';
  $block->content .= '<table class="month-picker"><tbody><tr>';
  for ($m = 1; $m <= 12; $m++) {
    $month = date("M", mktime(0, 0, 0, $m, 1)); 
    // Link this month if it has news articles.
    if (array_search($m, $active_months) !== FALSE) {
      $month = l($month, 'news/' . $current_year . '-' . $m);
    }
    $block->content .= '<td>' . $month . '</td>';
    if (!($m % 3)) {
      if ($m < 12) {
        $block->content .= '</tr><tr>';
      }
    }
  }
  $block->content .= '</tbody></tr></table>';
  $block->content .= '</div>';
  $block->content .= '</div>';
  return $block;
}

/**
 * 'Edit form' callback for the content type.
 */
function news_date_picker_content_type_edit_form($form, &$form_state) {
  return $form;
}

