<?php
/**
 * @file
 * lc_news.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function lc_news_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'news';
  $page->task = 'page';
  $page->admin_title = 'News';
  $page->admin_description = '';
  $page->path = 'news/%date/!search';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'date' => array(
      'id' => 1,
      'identifier' => 'Date',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'search' => array(
      'id' => 2,
      'identifier' => 'Search',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_news_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'news';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'lynchburg_12_threecol_3_6_3';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'main' => NULL,
      'right' => NULL,
      'top' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'News';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'News Archives',
      'body' => 'Archives date selection widget',
      'format' => 'plain_text',
      'substitute' => NULL,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['left'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Lynchburg College Magazine',
      'body' => '<p><a href="/spring2012">[[{"type":"media","view_mode":"media_original","fid":"49","attributes":{"alt":"","class":"media-image","height":"78","style":"float: left; margin-left: 5px; margin-right: 5px; border: 1px solid rgb(36, 36, 36);","typeof":"foaf:Image","width":"60"}}]]</a><a href="/spring2012">Current Issue</a></p><p><a href="/magazine">Archives</a></p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-2'] = $pane;
    $display->panels['left'][1] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'left';
    $pane->type = 'search_news';
    $pane->subtype = 'search_news';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Search the News',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-3'] = $pane;
    $display->panels['left'][2] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'main';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Title',
      'title' => '',
      'body' => '<h1 class="title">News</h1>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-4'] = $pane;
    $display->panels['main'][0] = 'new-4';
    $pane = new stdClass();
    $pane->pid = 'new-5';
    $pane->panel = 'main';
    $pane->type = 'views';
    $pane->subtype = 'news_stories_by_date';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '25',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 1,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'page',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-5'] = $pane;
    $display->panels['main'][1] = 'new-5';
    $pane = new stdClass();
    $pane->pid = 'new-6';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'lc_events-panel_pane_4';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-6'] = $pane;
    $display->panels['right'][0] = 'new-6';
    $pane = new stdClass();
    $pane->pid = 'new-7';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'LC in the News',
      'body' => '<p>Sunday\'s News &amp; Advance did a Lifestyle cover preview of our Healthy For Life events and an interview with Dr. Todd Olsen.<br /> <a href="http://www2.newsadvance.com/lifestyles/2012/mar/25/lynchburg-college-promotes-healthy-living-hunger-a-ar-1789614/" target="_blank">http://www2.newsadvance.com/<wbr>lifestyles/2012/mar/25/<wbr>lynchburg-college-promotes-<wbr>healthy-living-hunger-a-ar-<wbr>1789614/</wbr></wbr></wbr></wbr></a><br /> <br /> Students shave their heads for St. Baldrick\'s, which works to prevent cancer in children. Great photos in Saturday\'s paper as well as a piece on WSET Friday night.<br /> <a href="http://www.wset.com/story/17179907/head-shaving-event-for-cancer-research" target="_blank">http://www.wset.com/story/<wbr>17179907/head-shaving-event-<wbr>for-cancer-research</wbr></wbr></a><br /> <br /> Nice coverage of the Schewel lecture on bullying.<br /> <a href="http://www2.newsadvance.com/news/2012/mar/15/lynchburg-college-lecturer-talks-about-social-dyna-ar-1769889/" target="_blank">http://www2.newsadvance.com/<wbr>news/2012/mar/15/lynchburg-<wbr>college-lecturer-talks-about-<wbr>social-dyna-ar-1769889/</wbr></wbr></wbr></a><br /> <br /> Dr. Tom Shahady gets a few seconds of air time to rebut Congressman Goodlatte on protecting our waterways from storm water runoff.<br /> <a href="http://www.wdbj7.com/news/wdbj7-new-epa-rules-designed-to-protect-waterways-from-contamination-draw-concern-from-lynchburg-leaders-20120312,0,1608283.story" target="_blank">http://www.wdbj7.com/news/<wbr>wdbj7-new-epa-rules-designed-<wbr>to-protect-waterways-from-<wbr>contamination-draw-concern-<wbr>from-lynchburg-leaders-<wbr>20120312,0,1608283.story</wbr></wbr></wbr></wbr></wbr></a><br /> <br /> Darrell Laurant did a great column on Harry Lewis, our Turner lecturer, in today\'s paper.<br /> <a href="http://www2.newsadvance.com/news/2012/mar/12/changing-face-education-ar-1758990/" target="_blank">http://www2.newsadvance.com/<wbr>news/2012/mar/12/changing-<wbr>face-education-ar-1758990/</wbr></wbr></a></p><div class="yj6qo ajU"><div data-tooltip="Show trimmed content" id=":23h" class="ajR" role="button" tabindex="0"><img src="https://mail.google.com/mail/images/cleardot.gif" class="ajT" /></div></div>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-7'] = $pane;
    $display->panels['right'][1] = 'new-7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['news'] = $page;

  return $pages;

}
