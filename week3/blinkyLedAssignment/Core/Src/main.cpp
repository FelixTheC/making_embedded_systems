#include <cstdlib>
#include "stm32f303xc.h"
#include "user_led.hpp"
#include "user_button.hpp"
#include "interrupt_timer.hpp"

void enable_ahb_clock() noexcept;

BlinkyLED blinkyLed(8, 15);

int main()
{
    enable_ahb_clock();
    enable_interrupt_timer2();
    enable_user_button();
	enable_user_led();
 
	while(1)
    {
    }
    
    return EXIT_SUCCESS;
}

/// @brief Enable the clock/bus on the AHB line
void enable_ahb_clock() noexcept
{
    // Enable clock for GPIO_A
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    
    // Enable clock for GPIO_E
    RCC->AHBENR |= RCC_AHBENR_GPIOEEN;
}

/// @brief Interrupt service routine
/// can be found in g_pfnVectors in file startup_stm32f303vctx.s
extern "C"
void EXTI0_IRQHandler(void)
{
    // check if interrupt was raised by PIN 0
    if ((EXTI->PR & 0x01) != 0)
    {
        // clear PR flag
        EXTI->PR |= 0x01;

        enable_timer2();
        blinkyLed.turn_on_led();
    }
}

extern "C"
void TIM2_IRQHandler(void)
{
    // clear update interrupt flag
    TIM2->SR &= ~TIM_DIER_UIE;
    
    if (!blinkyLed.tick())
    {
		// Disable timer
        disable_timer2();
        
        blinkyLed.turn_off_led();
        blinkyLed.switch_leds();
    }
}
