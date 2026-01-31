#include "urls.h"
#include "esp_log.h"


static const char *TAG = "SERVER";
esp_err_t on_default_url(httpd_req_t *req)    
{                                                     //http home url page
    ESP_LOGI(TAG,"URL: %s",req->uri);

    char path[600];
    sprintf(path, "/store%s", req->uri);      //write a string inside a variable

    //******************    setup mimes    *******************************


    char* ext = strrchr(req -> uri, '.');
    if(ext)
    {
      if(strcmp(ext,".css") == 0) httpd_resp_set_type(req,"text/css");
      if(strcmp(ext,".js") == 0) httpd_resp_set_type(req,"text/javascript");
      if(strcmp(ext,".png") == 0) httpd_resp_set_type(req,"image/png");
      if(strcmp(ext,".jpg") == 0) httpd_resp_set_type(req,"image/jpg");
      if(strcmp(ext,".svg") == 0) httpd_resp_set_type(req,"image/svg+xml");
    };

    //******************************************************************** 
    FILE *file = fopen(path, "r"); 
    //if path does not exist                   
    if(file == NULL)
    {
      file = fopen("/store/index.html", "r");    //open index page
      if(file == NULL)
      {
        httpd_resp_send_404(req);   //send error 404
      }
      ESP_LOGI(TAG, "STORE/INDEX.HTML NOT FOUND");
    }
    char buffer[1024];
    int bytes_read = 0;
    while((bytes_read = fread(buffer, sizeof(char), sizeof(buffer),file)) > 0)   //read the file, end file
                                                                                 //when byres_read is 0
    {
      httpd_resp_send_chunk(req, buffer, bytes_read); //send response while buffer is filled with file data
    }
    fclose(file);   //close file
    httpd_resp_send_chunk(req, NULL, 0); //empty http data chunk

    
    return ESP_OK;
}