idf_component_register(SRCS  
                        "main.c" 
                    INCLUDE_DIRS 
                        "."
                    REQUIRES pinsSetup tasks pedestrian_call wifi_connect nvs_flash esp_http_server fatfs wear_levelling server
 
           
                 )

fatfs_create_rawflash_image(storage ../site/dist FLASH_IN_PROJECT)