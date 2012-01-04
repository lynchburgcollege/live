api = 2

;**************** CORE ****************

core = 7.x

; Drupal core
projects[] = drupal


;**************** CONTRIB ****************

; Base theme.
projects[] = "omega"

; Entities
;projects[entity][subdir] = "contrib"

; Fields
projects[addressfield][subdir] = "contrib"
projects[addanother][subdir] = "contrib"
projects[cck_phone][subdir] = "contrib"
projects[cnr][subdir] = "contrib"
projects[date][subdir] = "contrib"
projects[field_group][subdir] = "contrib"
projects[field_redirection][subdir] = "contrib"
projects[link][subdir] = "contrib"
projects[references][subdir] = "contrib"
;projects[field_collection][subdir] = "contrib"

; Media handling.
projects[file_entity][subdir] = "contrib"
projects[file_entity][version] = "2.x-dev"
projects[media][subdir] = "contrib"
projects[media][version] = "2.x-dev"
projects[media_flickr][subdir] = "contrib"
projects[media_youtube][subdir] = "contrib"

; SEO & related
projects[globalredirect][subdir] = "contrib"
projects[google301][subdir] = "contrib"
projects[google_analytics][subdir] = "contrib"
projects[page_title][subdir] = "contrib"
projects[pathauto][subdir] = "contrib"
projects[redirect][subdir] = "contrib"
projects[seo_checklist][subdir] = "contrib"
projects[site_map][subdir] = "contrib"
projects[site_verify][subdir] = "contrib"
projects[subpathauto][subdir] = "contrib"
projects[xmlsitemap][subdir] = "contrib"

; Views
projects[views][subdir] = "contrib"

; Architecture
projects[auto_nodetitle][subdir] = "contrib"
projects[context][subdir] = "contrib"
projects[cpn][subdir] = "contrib"
projects[ctools][subdir] = "contrib"
projects[diff][subdir] = "contrib"
projects[features][subdir] = "contrib"
projects[jcarousel][subdir] = "contrib"
projects[menu_minipanels][subdir] = "contrib"
projects[panels][subdir] = "contrib"
projects[rules][subdir] = "contrib"
projects[strongarm][subdir] = "contrib"
projects[token][subdir] = "contrib"
;projects[panelizer][subdir] = "contrib"

; Development tools.
projects[admin_menu][subdir] = "contrib"
projects[devel][subdir] = "contrib"
projects[devel_themer][subdir] = "contrib"
projects[diff][subdir] = "contrib"
projects[maillog][subdir] = "contrib"
projects[security_review][subdir] = "contrib"

; Performance.
projects[cdn][subdir] = "contrib"
projects[entitycache][subdir] = "contrib"
projects[memcache][subdir] = "contrib"
projects[varnish][subdir] = "contrib"

; When using SSL:
projects[securepages][subdir] = "contrib"

; If search is needed
projects[facetapi][subdir] = "contrib"
projects[porterstemmer][subdir] = "contrib"
projects[search_api][subdir] = "contrib"
projects[search_api_db][subdir] = "contrib"
projects[search_api_page][subdir] = "contrib"

; Admin.
projects[fasttoggle][subdir] = "contrib"

; Users
projects[profile2][subdir] = "contrib"
projects[realname][subdir] = "contrib"

; Misc
projects[backup_migrate][subdir] = "contrib"
projects[backup_migrate_files][subdir] = "contrib"
projects[comment_notify][subdir] = "contrib"
projects[email_registration][subdir] = "contrib"
projects[email_registration][version] = "1.x-dev"
projects[forward][subdir] = "contrib"
projects[logintoboggan][subdir] = "contrib"
projects[mailchimp][subdir] = "contrib"
projects[navigation404][subdir] = "contrib"
projects[transliteration][subdir] = "contrib"
projects[webform][subdir] = "contrib"
projects[wysiwyg][subdir] = "contrib"
;projects[community_tags][subdir] = "contrib"
;projects[revisioning][subdir] = "contrib"
;projects[twitter_block][subdir] = "contrib"


;**************** LIBRARIES ****************

; qTip
;libraries[qtip][download][type] = "get"
;libraries[qtip][download][url] = "http://craigsworks.com/projects/qtip/download/package/production/development/"
;libraries[qtip][destination] = "libraries"
;libraries[qtip][directory_name] = "qtip"

; TinyMCE
;libraries[tinymce][download][type] = "get"
;libraries[tinymce][download][url] = "https://github.com/downloads/tinymce/tinymce/tinymce_3.4.4_jquery.zip"
;libraries[tinymce][destination] = "libraries"
;libraries[tinymce][directory_name] = "tinymce"
