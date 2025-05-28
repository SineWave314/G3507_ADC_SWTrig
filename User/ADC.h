#ifndef __ADC_H__
#define __ADC_H__

#include <stdint.h>
#include "ti_msp_dl_config.h"
#include "Tick.h"

#define ADC_VREF 3.3F // ADC基准电压
// ADC值转为电压(V)
#define ADC_VAL_TO_VOLTAGE(x) ((float)(x) * ADC_VREF / 4096)

void ADC_init(void);
void ADC0_start(void);
uint16_t ADC0_getData(uint32_t timeout);
float ADC0_getVoltage(uint32_t timeout);

void ADC0_mem0ResultLoadedCallback(void);

#endif /* #ifndef __USER_ADC_H__ */
