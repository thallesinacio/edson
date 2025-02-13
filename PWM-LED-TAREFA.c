#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h" 
#include "hardware/irq.h" 
#include "hardware/pwm.h" 

#define engine_pin 12
const uint32_t WRAP = 24999;
const float PWM_DIVISER = 100.0f;

void pwm_setup(){ // 1
    gpio_set_function(engine_pin, GPIO_FUNC_PWM);

    uint slice = pwm_gpio_to_slice_num(engine_pin);

    pwm_set_clkdiv(slice, PWM_DIVISER);

    pwm_set_wrap(slice, WRAP);

    pwm_set_enabled(slice, true);
}

int main(){
    int incremento = 6;
    int estado_atual = 625;
    
    pwm_setup();

    // 2
    pwm_set_gpio_level(engine_pin, 3000);
    sleep_ms(5000);

    // 3
    pwm_set_gpio_level(engine_pin, 1838);
    sleep_ms(5000);
    
    // 4
    pwm_set_gpio_level(engine_pin, 625); // 0 graus
    sleep_ms(5000);

    // 5

    while(true) {
            // Move de 180 a 0 graus
        
            while (estado_atual <= 3000) {
                pwm_set_gpio_level(engine_pin, estado_atual);
                estado_atual += incremento;
                sleep_ms(10); // Atraso de 10ms
            }
    
            
            while (estado_atual >= 625) {
                pwm_set_gpio_level(engine_pin, estado_atual);
                estado_atual -= incremento;
                sleep_ms(10); // Atraso de 10ms
            }
    }





}






