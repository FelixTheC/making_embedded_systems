//
// Created by felix on 13.10.23.
//

#ifndef BLINKYLEDASSIGNMENT_USER_BUTTON_HPP
#define BLINKYLEDASSIGNMENT_USER_BUTTON_HPP

#include "stm32f303xc.h"


/// @brief User Button is in GPIO_A Pin 0
void enable_user_button() noexcept
{
    __disable_irq();
    
    // set `pin 0` to input mode
    GPIOA->MODER |= 0x00;
    
    // SYSCFG clock enable
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
    
    // Enable EXTI0 on SYSCFG
    SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PA;

    // Unmask EXTI0
    EXTI->IMR |= (1<<0);

    // Falling trigger enabled for EXTI0
    EXTI->FTSR |= (1<<0);

    // Enable EXTI0 in NVIC
    NVIC_EnableIRQ(EXTI0_IRQn);
    NVIC_SetPriority(EXTI0_IRQn, 0);
    
    __enable_irq();
}

#endif //BLINKYLEDASSIGNMENT_USER_BUTTON_HPP
