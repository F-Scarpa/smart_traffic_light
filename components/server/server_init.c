#include "server_init.h"
#include "esp_log.h"
#include "urls.h"

static  httpd_handle_t server = NULL;   //server handle






void init_server()     // can be used to store paths
{
 
  httpd_config_t config = HTTPD_DEFAULT_CONFIG();   //working configuration of our server
  config.uri_match_fn = httpd_uri_match_wildcard;   //enables the use of wildcards in routes, (/*)
  ESP_ERROR_CHECK(httpd_start(&server, &config));   //start the server

//endpoints
  /*
  httpd_uri_t toggle_led_url = {
      .uri = "/api/toggle-led",         //dont use underscores in uri
      .method = HTTP_POST,
      .handler = on_toggle_led_url    //function called while uri is visited
    };
  httpd_register_uri_handler(server, &toggle_led_url);    //register the url in the server

  */

  httpd_uri_t default_url = {   //url = browser address
    .uri ="/*",                  //accept everything (/*)
    .method = HTTP_GET,
    .handler = on_default_url   
                                //with /* every url call this func, unless further in sequence
  };
  httpd_register_uri_handler(server,&default_url);    
}