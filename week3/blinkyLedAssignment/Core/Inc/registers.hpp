#ifndef REGISTERS_HPP
#define REGISTERS_HPP

#include <cstdint>

namespace reg
{
    namespace GPIO_E
    {
        const uint32_t AHB2_GPIOE_MODER_15_OUT = 0x40000000;
        const uint32_t AHB2_GPIOE_MODER_14_OUT = 0x10000000;
        const uint32_t AHB2_GPIOE_MODER_13_OUT = 0x4000000;
        const uint32_t AHB2_GPIOE_MODER_12_OUT = 0x1000000;
        const uint32_t AHB2_GPIOE_MODER_11_OUT = 0x400000;
        const uint32_t AHB2_GPIOE_MODER_10_OUT = 0x100000;
        const uint32_t AHB2_GPIOE_MODER_09_OUT = 0x40000;
        const uint32_t AHB2_GPIOE_MODER_08_OUT = 0x10000;
    }
}

#endif
