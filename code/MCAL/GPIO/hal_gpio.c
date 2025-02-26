/* 
 * File:   app.h
 * Author: ah427
 *
 * Created on 21 ?????, 2024, 08:41
 */

#include "hal_gpio.h"

volatile uint8 *tris_registers[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
volatile uint8 *port_registers[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};
volatile uint8 *lat_registers[] = {&LATA, &LATB, &LATC, &LATD, &LATE};


Std_ReturnType gpio_pin_direction_initialize(const Pin_config_t *_pin_config)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL == _pin_config) || (MAX_PIN < _pin_config->Pin) || (MAX_PORT < _pin_config->Port)){
        ret = E_NOT_OK;
    }
    else{
        switch(_pin_config->Direction){
            case GPIO_INPUT:
                SET_BIT(*tris_registers[_pin_config->Port], _pin_config->Pin);
                ret = E_OK;
                break;
            case GPIO_OUTPUT:
                CLEAR_BIT(*tris_registers[_pin_config->Port], _pin_config->Pin);
                ret = E_OK;
                break;
            default:
                ret = E_NOT_OK;
        }
    }
    return ret;
}


Std_ReturnType gpio_pin_get_direction_status(const Pin_config_t *_pin_config, Direction_t *direction_status)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL == _pin_config)||(NULL == direction_status) || (MAX_PIN < _pin_config->Pin)||(MAX_PORT < _pin_config->Port)){
        ret = E_NOT_OK;
    }
    else{
        *direction_status = READ_BIT(*tris_registers[_pin_config->Port], _pin_config->Pin);
    }
    return ret;
}


Std_ReturnType gpio_pin_write_logic(const Pin_config_t *_pin_config, Logic_t logic)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL == _pin_config) || (MAX_PIN < _pin_config->Pin) || (MAX_PORT < _pin_config->Port)){
        ret = E_NOT_OK;
    }
    else{
        switch(logic){
            case GPIO_LOW:
                CLEAR_BIT(*lat_registers[_pin_config->Port], _pin_config->Pin);
                ret = E_OK;
                break;
            case GPIO_HIGH:
                SET_BIT(*lat_registers[_pin_config->Port], _pin_config->Pin);
                ret = E_OK;
                break;
            default:
                ret = E_NOT_OK;     
        }
    }
    return ret;
}


Std_ReturnType gpio_pin_read_logic(const Pin_config_t *_pin_config, Logic_t *logic)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL == _pin_config)||(NULL == logic) || (MAX_PIN < _pin_config->Pin)||(MAX_PORT < _pin_config->Port)){
        ret = E_NOT_OK;
    }
    else{
        *logic = READ_BIT(*port_registers[_pin_config->Port], _pin_config->Pin);
    }
    return ret;
}


Std_ReturnType gpio_pin_toggle_logic(const Pin_config_t *_pin_config)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL == _pin_config) || (MAX_PIN < _pin_config->Pin) || (MAX_PORT < _pin_config->Port)){
        ret = E_NOT_OK;
    }
    else{
        TOGGLE_BIT(*lat_registers[_pin_config->Port], _pin_config->Pin);
    }
    return ret;
}


Std_ReturnType gpio_pin_initialize(const Pin_config_t *_pin_config)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL == _pin_config) || (MAX_PIN < _pin_config->Pin) || (MAX_PORT < _pin_config->Port)){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_direction_initialize(_pin_config);
        ret &= gpio_pin_write_logic(_pin_config, _pin_config->Logic);
    }
    return ret;
}




Std_ReturnType gpio_port_direction_initialize(Port_index_t port, uint8 direction)
{
    Std_ReturnType ret = E_NOT_OK;
    switch(direction){
        case GPIO_INPUT:
            *tris_registers[port] = 0xFF;
            ret = E_OK;
            break;
        case GPIO_OUTPUT:
            *tris_registers[port] = 0x00;
            ret = E_OK;
            break;
        default:
            ret = E_NOT_OK;
    }
    return ret;
}


Std_ReturnType gpio_port_get_direction_status(Port_index_t port, uint8 *direction_status)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == direction_status){
        ret = E_NOT_OK;
    }
    else{
        *direction_status = *tris_registers[port];
    }
    return ret;
}


Std_ReturnType gpio_port_read_logic(Port_index_t port, Logic_t *logic)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == logic){
        ret = E_NOT_OK;
    }
    else{
        *logic = *port_registers[port];
    }
    return ret;
}


Std_ReturnType gpio_port_toggle_logic(Port_index_t port)
{
    Std_ReturnType ret = E_NOT_OK;
    *lat_registers[port] ^= 0xFF;
    return ret;
}



#include "hal_gpio.h"
