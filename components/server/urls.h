#pragma once
#include "esp_http_server.h" 
#include "pinsSetup.h"

esp_err_t on_default_url(httpd_req_t *req);

extern int mode;
esp_err_t on_disable_mode_url(httpd_req_t *req);
esp_err_t on_auto_mode_url(httpd_req_t *req);
esp_err_t on_error_mode_url(httpd_req_t *req);
esp_err_t on_pedestrian_call_mode_url(httpd_req_t *req);
esp_err_t on_text_url(httpd_req_t *req);

