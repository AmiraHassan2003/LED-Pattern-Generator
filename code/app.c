/*
 * File:   app.c
 * Author: ah427
 *
 * Created on 21 ?????, 2024, 08:41 ?
 */


#include <xc.h>
#include <builtins.h>
#include "app.h"
#define _XTAL_FREQ 80000000UL

led_t led0 = {
    .port_name = GPIO_PORTC,
    .pin = GPIO_PIN0,
    .led_status = LED_OFF,
};
led_t led1 = {
    .port_name = GPIO_PORTC,
    .pin = GPIO_PIN1,
    .led_status = LED_OFF,
};
led_t led2 = {
    .port_name = GPIO_PORTC,
    .pin = GPIO_PIN2,
    .led_status = LED_OFF,
};
led_t led3 = {
    .port_name = GPIO_PORTC,
    .pin = GPIO_PIN3,
    .led_status = LED_OFF,
};
led_t led4 = {
    .port_name = GPIO_PORTC,
    .pin = GPIO_PIN4,
    .led_status = LED_OFF,
};
led_t led5 = {
    .port_name = GPIO_PORTC,
    .pin = GPIO_PIN5,
    .led_status = LED_OFF,
};
led_t led6 = {
    .port_name = GPIO_PORTC,
    .pin = GPIO_PIN6,
    .led_status = LED_OFF,
};
led_t led7 = {
    .port_name = GPIO_PORTC,
    .pin = GPIO_PIN7,
    .led_status = LED_OFF,
};

void initialization(void);

void main(void) {
    initialization();
    while(1){
        led_turn_on(&led0);
        led_turn_on(&led7);
        __delay_ms(10);
        
        led_turn_on(&led1);
        led_turn_on(&led6);
        __delay_ms(10);
        
        led_turn_on(&led2);
        led_turn_on(&led5);
        __delay_ms(10);
        
        led_turn_on(&led3);
        led_turn_on(&led4);
        __delay_ms(10);
        
        led_toggle(&led0);
        led_toggle(&led7);
        __delay_ms(10);
        
        led_toggle(&led3);
        led_toggle(&led4);
        __delay_ms(10);    
        
        led_toggle(&led2);
        led_toggle(&led5);
        __delay_ms(10);    
        
        led_toggle(&led6);
        led_toggle(&led1);
        __delay_ms(10);
        

        
    }
    
    return;
}

void initialization(void){
    led_initialize(&led0);
    led_initialize(&led1);
    led_initialize(&led2);
    led_initialize(&led3);
    led_initialize(&led4);
    led_initialize(&led5);
    led_initialize(&led6);
    led_initialize(&led7);
}