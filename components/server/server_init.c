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
  
  httpd_uri_t disable_mode_url = {
      .uri = "/api/disable",         
      .method = HTTP_GET,
      .handler = on_disable_mode_url    //function called while uri is visited
    };
  httpd_register_uri_handler(server, &disable_mode_url);    //register the url in the server

    httpd_uri_t auto_mode_url = {
      .uri = "/api/auto",         
      .method = HTTP_GET,
      .handler = on_auto_mode_url    
    };
  httpd_register_uri_handler(server, &auto_mode_url);   

      httpd_uri_t error_mode_url = {
      .uri = "/api/error",         
      .method = HTTP_GET,
      .handler = on_error_mode_url    
    };
  httpd_register_uri_handler(server, &error_mode_url);  

  

  httpd_uri_t default_url = {   //url = browser address
    .uri ="/*",                  //accept everything (/*)
    .method = HTTP_GET,
    .handler = on_default_url   
                                //with /* every url call this func, unless further in sequence
  };
  httpd_register_uri_handler(server,&default_url);    
}