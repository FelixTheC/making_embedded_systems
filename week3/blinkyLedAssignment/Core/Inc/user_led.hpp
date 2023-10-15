//
// Created by felix on 13.10.23.
//

#ifndef BLINKYLEDASSIGNMENT_USER_LED_HPP
#define BLINKYLEDASSIGNMENT_USER_LED_HPP

#include <cassert>
#include "registers.hpp"
#include "stm32f303xc.h"

const uint8_t BSRR_RESET_OFFSET = 16;

/// @brief set User LED's (LD3-LD10)[PIN's 8-15] to output mode
void enable_user_led() noexcept
{
    GPIOE->MODER |= reg::GPIO_E::AHB2_GPIOE_MODER_15_OUT;
    GPIOE->MODER |= reg::GPIO_E::AHB2_GPIOE_MODER_14_OUT;
    GPIOE->MODER |= reg::GPIO_E::AHB2_GPIOE_MODER_13_OUT;
    GPIOE->MODER |= reg::GPIO_E::AHB2_GPIOE_MODER_12_OUT;
    GPIOE->MODER |= reg::GPIO_E::AHB2_GPIOE_MODER_11_OUT;
    GPIOE->MODER |= reg::GPIO_E::AHB2_GPIOE_MODER_10_OUT;
    GPIOE->MODER |= reg::GPIO_E::AHB2_GPIOE_MODER_09_OUT;
    GPIOE->MODER |= reg::GPIO_E::AHB2_GPIOE_MODER_08_OUT;
    
}

/// @brief Sets the corresponding ODRx bit
/// @param pin can be a value between 0 - 15
void set_gpio_pin(uint8_t pin) noexcept
{
    assert((0U <= pin && pin <= 15U) && "pin can be a value between 0 - 15");
    GPIOE->BSRR |= (1U << pin);
}

/// @brief Resets the corresponding ODRx bit
/// @param pin can be a value between 0 - 15
void reset_gpio_pin(uint8_t pin) noexcept
{
    assert((0U <= pin && pin <= 15U) && "pin can be a value between 0 - 15");
    GPIOE->BSRR |= (1U << (pin + BSRR_RESET_OFFSET));
}

void switch_led(uint8_t pin, bool on) noexcept
{
    if (on)
    {
        set_gpio_pin(pin);
    }
    else
    {
        reset_gpio_pin(pin);
    }
}

struct BlinkyLED
{
    uint8_t _min_pin = 0;
    uint8_t _max_pin = 0;
    uint8_t _current_pin = 0;
    bool _turn_on = false;
    
    BlinkyLED(uint8_t min_pin, uint8_t max_pin) : _min_pin(min_pin), _max_pin(max_pin), _current_pin(min_pin) {}
    ~BlinkyLED() = default;
    
    /// @brief switch on the current pin (LED)
    /// @return true if the current pin <= max_pin
    [[nodiscard ]] bool tick() noexcept
    {
        if (_current_pin <= _max_pin)
        {
            switch_led(_current_pin, _turn_on);
            ++_current_pin;
            return true;
        }
        else
        {
            return false;
        }
    }
    
    /// @brief loops from min_pin to max_pin
    void switch_leds() noexcept
    {
        _current_pin = _min_pin;
        
        for(uint32_t pin_no = _min_pin; pin_no <= _max_pin; ++pin_no)
        {
            switch_led(pin_no, _turn_on);
        }
    }
    
    void turn_on_led() noexcept
    {
        _turn_on = true;
    }
    
    void turn_off_led() noexcept
    {
        _turn_on = false;
    }
};

#endif //BLINKYLEDASSIGNMENT_USER_LED_HPP
