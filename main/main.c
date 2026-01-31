#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"  

#include "nvs_flash.h"
//#include "esp_http_server.h"    
#include "secrets.h"
#include "esp_vfs.h"
#include "esp_vfs_fat.h"
#include "esp_err.h"

#include "traffic_light.h"
#include "pedestrian_call.h"   
#include "pinsSetup.h"
#include "mymdns.h"
#include "server_init.h"
#include "wifi_connect.h"



void app_main(void)
{   
    int mode = 0;
    pinsInit();
    int_init();

    ESP_ERROR_CHECK(nvs_flash_init());
    wifi_connect_init();
    ESP_ERROR_CHECK(wifi_connect_sta(WIFI_SSID, WIFI_PASSWORD, 10000));

    start_mdns_service();
    mount_fs();   
    init_server();

    
                                                                          
    switch(mode)
    {
    case 0:
        while(1)
        {
            all_led_off();
            vTaskDelay(pdMS_TO_TICKS(100));
        }
        break;
    case 1:
        static LedTaskParams timeParams = {.delayTime = 2000};  //we can use struct to create an object, static if to be used in a task
        xTaskCreate(&traffic_light_cycle,"traffic_light_cycle",2048, &timeParams, 2, NULL);     //this will call the defined task using &object as arguments
                                                                                            //how arguments are handled is defined in the task function
        break;
    case 2:
        xTaskCreate(&traffic_light_error,"traffic_light_error",2048, NULL, 2, NULL);    //params can also be selected from inside the task but
                                                                                        //use NULL as 4 parameter in xtaskCreate
        break;
    case 3:
        green_led_on();
        xTaskCreate(&buttonPushedTask,"button_pushed_task",2048, NULL, 2, NULL);
        break;
    }                                                                             
    

}

