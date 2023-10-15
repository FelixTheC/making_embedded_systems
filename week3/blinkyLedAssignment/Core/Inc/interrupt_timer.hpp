//
// Created by felix on 15.10.23.
//

#ifndef BLINKYLEDASSIGNMENT_INTERRUPT_TIMER_HPP
#define BLINKYLEDASSIGNMENT_INTERRUPT_TIMER_HPP

#include "stm32f303xc.h"


void enable_interrupt_timer2() noexcept
{
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    
    // Set prescaler value
    TIM2->PSC = 320 - 1;
    
    // Set auto-reload value
    TIM2->ARR = 10000 - 1;
    
    // Clear counter
    TIM2->CNT = 0;
    
    // Enable TIM interrupt for update event
    TIM2->DIER |= TIM_DIER_UIE;
    
    // Enable TIM interrupt in NVIC
    NVIC_EnableIRQ(TIM2_IRQn);
}

void enable_timer2()
{
    TIM2->CR1 = TIM_CR1_CEN;
}

void disable_timer2()
{
    TIM2->CR1 &= ~TIM_CR1_CEN;
}

#endif //BLINKYLEDASSIGNMENT_INTERRUPT_TIMER_HPP
