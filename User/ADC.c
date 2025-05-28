#include "ADC.h"

volatile uint16_t ADC0Data = 0;
volatile uint8_t ADC0DataValid = 0;

void ADC_init(void) {
    NVIC_EnableIRQ(ADC0_INST_INT_IRQN);
}

void ADC0_start(void) {
    ADC0DataValid = 0;
    DL_ADC12_startConversion(ADC0_INST);
}

uint16_t ADC0_getData(uint32_t timeout) {
    uint32_t startTime = Tick;
    while (!ADC0DataValid) {
        if (Tick - startTime >= timeout) return 0;
    }
    return ADC0Data;
}

float ADC0_getVoltage(uint32_t timeout) {
    uint32_t startTime = Tick;
    while (!ADC0DataValid) {
        if (Tick - startTime >= timeout) return 0;
    }
    return ADC_VAL_TO_VOLTAGE(ADC0Data);
}

// ADC0中断回调
void ADC0_mem0ResultLoadedCallback(void) {
    ADC0Data = DL_ADC12_getMemResult(ADC0_INST, ADC0_ADCMEM_0);
    ADC0DataValid = 1;
    DL_ADC12_enableConversions(ADC0_INST);
}
