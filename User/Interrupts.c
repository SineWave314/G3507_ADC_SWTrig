#include "Interrupts.h"

// SysTick中断服务函数(1ms)
void SysTick_Handler(void) {
    Tick_SysTickCallback();
}

// ADC0中断服务函数
void ADC0_IRQHandler(void) {
    switch (DL_ADC12_getPendingInterrupt(ADC0_INST)) {
        case DL_ADC12_IIDX_MEM0_RESULT_LOADED:
            ADC0_mem0ResultLoadedCallback();
            break;
        default:
            break;
    }
}
