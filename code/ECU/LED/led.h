/* 
 * File:   ecu_led.h
 * Author: ah427
 *
 * Created on July 15, 2024, 2:08 PM
 */

#ifndef LED_H
#define	LED_H

        /* Section : Includes*/
#include "../../MCAL/GPIO/hal_gpio.h"

        /* Section : Macro Declarations */
        /* Section : Macro Function Declarations */
        /* Section : Data Type Declarations */
typedef enum{
    LED_OFF,
    LED_ON
}led_status_t;

typedef struct{
    uint8 port_name: 3;
    uint8 pin: 3;
    uint8 led_status: 1;
}led_t;

        /* Section : Function Declarations */
Std_ReturnType led_initialize(led_t *led);
Std_ReturnType led_turn_on(led_t *led);
Std_ReturnType led_turn_off(led_t *led);
Std_ReturnType led_toggle(led_t *led);
#endif	/* ECU_LED_H */

