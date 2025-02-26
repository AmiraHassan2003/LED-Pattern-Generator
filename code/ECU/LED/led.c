#include "led.h"

static void configure_pin(Pin_config_t *_pin_config, led_t *led);

Std_ReturnType led_initialize(led_t *led)
{
    Std_ReturnType ret = E_OK;
    if(NULL == led){
        ret = E_NOT_OK;
    }
    else{
        Pin_config_t _pin_config;
        configure_pin(&_pin_config, led);
        ret = gpio_pin_initialize(&_pin_config);
    }
    return ret;
}

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_on(led_t *led)
{
    Std_ReturnType ret = E_OK;
    if(NULL == led){
        ret = E_NOT_OK;
    }
    else{
        Pin_config_t _pin_config;
        configure_pin(&_pin_config, led);
        ret = gpio_pin_write_logic(&_pin_config, GPIO_HIGH);
    }
    return ret;
}

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_off(led_t *led)
{
    Std_ReturnType ret = E_OK;
    if(NULL == led){
        ret = E_NOT_OK;
    }
    else{
        Pin_config_t _pin_config;
        configure_pin(&_pin_config, led);
        ret = gpio_pin_write_logic(&_pin_config, GPIO_LOW);
    }
    return ret;
}

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_toggle(led_t *led)
{
    Std_ReturnType ret = E_OK;
    if(NULL == led){
        ret = E_NOT_OK;
    }
    else{
        Pin_config_t _pin_config;
        configure_pin(&_pin_config, led);
        ret = gpio_pin_toggle_logic(&_pin_config);
    }
    return ret;
}

static void configure_pin(Pin_config_t *_pin_config, led_t *led)
{
   _pin_config->Port = led->port_name;
   _pin_config->Pin = led->pin;
   _pin_config->Direction = GPIO_OUTPUT;   
   _pin_config->Logic = led->led_status;
  
}


