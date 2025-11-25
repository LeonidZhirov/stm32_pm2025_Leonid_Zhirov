#ifndef DELAY_H
#define DELAY_H

#include <stdint.h>
#include <stm32f10x.h>

void delay(uint32_t ticks) {
    for (uint32_t i = 0; i < ticks; i++) {
        __NOP();
    }
}

#endif
