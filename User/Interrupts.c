#include "Interrupts.h"

// SysTick中断服务函数(1ms)
void SysTick_Handler(void) {
    Tick_SysTickCallback();
}
