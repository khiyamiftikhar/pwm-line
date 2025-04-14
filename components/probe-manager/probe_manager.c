
#include "pwm_line.h"
#include "probe_manager.h"


//static const uint8_t duty_one=100;
//static const uint8_t duty_two=100;



static int proberCheckDeadTime(uint32_t time_period,uint32_t dead_time){
    uint32_t percentage=(dead_time*100)/time_period;

    //Greater than 5%
    if(percentage>5)    
        return ERR_PROBE_MANAGER_DEAD_TIME_LARGE;
    //if(percentage<)
    return 0;
}


static int frequencyCheck(uint32_t frequency){

    if(frequency>100)   //100Hz because it gives  10ms. less than 10ms is less time for 4 input keypad
        return ERR_PROBE_MANAGER_FREQUENCY_LARGE;

    return 0;
}

static int phaseCalculate(uint8_t total_gpio){
    if(total_gpio<=0)
        return ERR_PROBE_MANAGER_WRONG_PARAMETERS; 
    return 360/total_gpio;
}

static int dutyCycleCheck(uint8_t* duty_cycles,uint8_t total_gpio){

    uint16_t sum=0;
    for(uint8_t i=0;i<total_gpio;i++)
        sum+=duty_cycles[i];

    if(sum>100)
        return ERR_PROBE_MANAGER_WRONG_PARAMETERS;
    return 0;
}

int proberCreate(struct prober_interface* self,prober_config_t* config){

    if(self==NULL || config==NULL)
        return ERR_PROBE_MANAGER_INVALID_MEM;

    uint8_t total_gpio=config->total_gpio;
    uint32_t time_period=config->time_period;        //Time period in microseconds
    int frequency=1000000/time_period;
    uint8_t* duty_cycles=config->duty_cycles;
    uint32_t dead_time=config->dead_time;

    int ret=proberCheckParameter(config);

    if(ret!=0)
        return ret;

    ret=frequencyCheck(frequency);
    
    if(ret!=0)
        return ret;

    ret=dutyCycleCheck(duty_cycles,total_gpio);

    if(ret!=0)
        return ret;
    
    int phase=phaseCalculate(total_gpio);
    

    
    pwm_config_t line_config;
    for(uint8_t i=0;i<total_gpio;i++){
        line_config.frequency=frequency;
        line_config.duty_cycle=duty_cycles[i];   // Duty cycle percentage (0-100)
        uint32_t duty_cycle_time=duty_cycles[i]*time_period/100;
        int phase_cut=(dead_time*100)/time_period;
        line_config.phase = phase;
    uint8_t phase_cut_on_duty;   //%age (0-100) of duty, Reduction of duty at start so that to have gaptime when used with other phase
    uint8_t gpio;      // GPIO pin
    uint8_t channel_number;
    void* context;      //For any data structure created by the ESPIDF driver
} pwm_config_t;




    


}