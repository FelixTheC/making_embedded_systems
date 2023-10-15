# 3. Inputs, Outputs and Timers

## What are the hardware registers that cause the LED to turn on and off?

- we can either use the GPIOx_BSRR (GPIO port bit set/reset register) or the GPIOx_ODR (GPIO port output data register)

## What are the registers that you read in order to find out the state of the button?

- the GPIOx_IDR (GPIO port input data register)

## Can you read the register directly and see the button change in a debugger or by printing out these value of the memory at the register’s address?

- with the STM32CubeIDE it is possible to directly change the value in a specific register when running the debugger but 
you need to plug in the two jumpers on CN4, if not already plugged in, to enable debugging on-board