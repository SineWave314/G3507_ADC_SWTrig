#include "UserTask.h"

uint16_t ADC0Data = 0;
float ADC0Voltage = 0;
uint16_t ADC1Data[4] = {0};
float ADC1Voltage[4] = {0};
int i;

void UserTask_init(void) {
    ADC_init();
}

void UserTask_loop(void) {
    DL_GPIO_setPins(GPIO_LED_PORT, GPIO_LED_LED1_PIN);
    ADC0_start();
    ADC0Data = ADC0_getData(10);
    ADC0Voltage = ADC0_getVoltage(10);
    DL_GPIO_clearPins(GPIO_LED_PORT, GPIO_LED_LED1_PIN);

    Tick_delay(50);

    DL_GPIO_setPins(GPIO_LED_PORT, GPIO_LED_LED1_PIN);
    ADC1_start();
    for (i = 0; i < 4; i++) {
        ADC1Data[i] = ADC1_getData(i, 10);
        ADC1Voltage[i] = ADC1_getVoltage(i, 10);
    }
    DL_GPIO_clearPins(GPIO_LED_PORT, GPIO_LED_LED1_PIN);

    Tick_delay(50);
}

void UserTask_tick(void) {
    
}
