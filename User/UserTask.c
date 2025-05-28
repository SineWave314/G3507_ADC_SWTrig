#include "UserTask.h"

uint16_t ADC0Data = 0;
float ADC0Voltage = 0;

void UserTask_init(void) {
    ADC_init();
}

void UserTask_loop(void) {
    ADC0_start();
    ADC0Data = ADC0_getData(10);
    ADC0Voltage = ADC0_getVoltage(10);

    DL_GPIO_togglePins(GPIO_LED_PORT, GPIO_LED_LED1_PIN);
    Tick_delay(500);
}

void UserTask_tick(void) {
    
}
