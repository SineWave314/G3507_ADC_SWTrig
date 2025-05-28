#ifndef __TICK_H__
#define __TICK_H__

#include <stdint.h>
#include "ti_msp_dl_config.h"
#include "UserTask.h"

extern volatile uint32_t Tick;

void Tick_delay(uint32_t t);
void Tick_SysTickCallback(void);

#endif /* #ifndef __TICK_H__ */
