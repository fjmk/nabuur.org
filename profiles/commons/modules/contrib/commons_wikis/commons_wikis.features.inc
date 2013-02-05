<?php
/**
 * @file
 * commons_wikis.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function commons_wikis_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function commons_wikis_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_message_type().
 */
function commons_wikis_default_message_type() {
  $items = array();
  $items['commons_wikis_wiki_updated'] = entity_import('message_type', '{
    "name" : "commons_wikis_wiki_updated",
    "description" : "commons_wikis_wiki_updated",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "[message:user:picture]",
          "format" : "filtered_html",
          "safe_value" : "[message:user:picture]"
        },
        {
          "value" : "\\u003Ca href=\\u0022[current-user:url]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E has updated the wiki page \\u003Ca href=\\u0022[message:field-target-nodes:0:url]\\u0022 class=\\u0022aloha-link-text\\u0022\\u003E[message:field-target-nodes:0]\\u003C\\/a\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Ca href=\\u0022[current-user:url]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E has updated the wiki page \\u003Ca href=\\u0022[message:field-target-nodes:0:url]\\u0022 class=\\u0022aloha-link-text\\u0022\\u003E[message:field-target-nodes:0]\\u003C\\/a\\u003E"
        },
        {
          "value" : "[commons-groups:in-groups-text]",
          "format" : "full_html",
          "safe_value" : "[commons-groups:in-groups-text]"
        }
      ]
    }
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function commons_wikis_node_info() {
  $items = array(
    'wiki' => array(
      'name' => t('Wiki'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}