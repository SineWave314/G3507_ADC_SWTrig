#include "ADC.h"

volatile uint16_t ADC0_Data = 0;
volatile uint8_t ADC0_DataValid = 0;

void ADC_init(void) {
    NVIC_EnableIRQ(ADC0_INST_INT_IRQN);
}

void ADC0_start(void) {
    ADC0_DataValid = 0;
    DL_ADC12_startConversion(ADC0_INST);
}

uint16_t ADC0_getData(uint32_t timeout) {
    uint32_t startTime = Tick;
    while (!ADC0_DataValid) {
        if (Tick - startTime >= timeout) return 0;
    }
    return ADC0_Data;
}

float ADC0_getVoltage(uint32_t timeout) {
    uint32_t startTime = Tick;
    while (!ADC0_DataValid) {
        if (Tick - startTime >= timeout) return 0;
    }
    return ADC_VAL_TO_VOLTAGE(ADC0_Data);
}

// ADC0中断回调
void ADC0_mem0ResultLoadedCallback(void) {
    ADC0_Data = DL_ADC12_getMemResult(ADC0_INST, ADC0_ADCMEM_0);
    ADC0_DataValid = 1;
    DL_ADC12_enableConversions(ADC0_INST);
}
