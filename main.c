#include <stdint.h>
#include <stm32f10x.h>

volatile uint32_t delay_time = 180000000;

void delay(uint32_t ticks) {
	for (int i=0; i<ticks; i++) {
		__NOP();
	}
}

int main(void) {
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPCEN;
    
    GPIOC->CRH &= ~(GPIO_CRH_CNF13 | GPIO_CRH_MODE13);
    GPIOC->CRH |= GPIO_CRH_MODE13_1;
    
    GPIOA->CRL &= ~(GPIO_CRL_CNF0 | GPIO_CRL_MODE0);
    GPIOA->CRL |= GPIO_CRL_CNF0_1;
    GPIOA->ODR |= GPIO_ODR_ODR0;
    
    uint32_t speeds[] = {180000000, 90000000, 45000000, 22500000, 11250000};
    uint8_t speed_index = 0;
    uint8_t button_was_pressed = 0;
    
    while(1) {
        if((GPIOA->IDR & GPIO_IDR_IDR0) == 0) {
            if(!button_was_pressed) {
                speed_index = (speed_index + 1) % 5;
                delay_time = speeds[speed_index];
                button_was_pressed = 1;
            }
        } else {
            button_was_pressed = 0;
        }
        
        GPIOC->ODR ^= GPIO_ODR_ODR13;
        delay(delay_time);
    }
}