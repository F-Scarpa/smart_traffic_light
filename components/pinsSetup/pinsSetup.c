#include "pinsSetup.h"
#include "driver/gpio.h"  
#include <stdio.h>




void pinsInit(){
    gpio_set_direction(redLed, GPIO_MODE_OUTPUT );
    gpio_set_direction(greenLed, GPIO_MODE_OUTPUT );    
    gpio_set_direction(yellowLed, GPIO_MODE_OUTPUT );  
}

void red_led_on()
{
    gpio_set_level(redLed,1);
    gpio_set_level(yellowLed,0);
    gpio_set_level(greenLed,0);
}

void red_led_off()
{
    gpio_set_level(redLed,0);
}

void yellow_led_on()
{
    gpio_set_level(redLed,0);
    gpio_set_level(yellowLed,1);
    gpio_set_level(greenLed,0);
}


void green_led_on()
{
    gpio_set_level(redLed,0);
    gpio_set_level(yellowLed,0);
    gpio_set_level(greenLed,1);
}

void yellow_led_off()
{
    gpio_set_level(yellowLed,0);
}

void all_led_off()
{
    gpio_set_level(yellowLed,0);
    gpio_set_level(redLed,0);
    gpio_set_level(greenLed,0);
}