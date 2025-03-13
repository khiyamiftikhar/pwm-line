
#ifndef PWM_LINE_H

#define PWM_LINE_H

#include "pwm_line_interface.h"


typedef enum {
    RUNNING,
    IDLE
}pwm_line_state_t;


typedef struct {
    uint32_t frequency;   // Frequency in Hz, use 100Hz bcause it gives 10ms period
    uint8_t duty_cycle;   // Duty cycle percentage (0-100)
    uint8_t phase;    // Degrees e.g 90, 180
    uint8_t phase_cut_on_duty;   //%age (0-100) of duty, Reduction of duty at start so that to have gaptime when used with other phase
    uint8_t gpio;      // GPIO pin
    uint8_t channel_number;
    void* context;      //For any data structure created by the ESPIDF driver
} pwm_config_t;


typedef struct pwm_line{

    //pwm_config_t  config;
    uint8_t channel_number;
    uint8_t gpio_number;
    int duty;
    int hpoint;
    pwm_line_interface_t interface;

}pwm_line_t;


int pwmCreate(pwm_line_t* self,pwm_config_t*  config);


#endif