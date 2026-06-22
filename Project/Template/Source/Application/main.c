#include "Application/main.h"

#include <Board/Board.h>
#include <stm32f1xx_hal.h>

int main(void)
{
    Board_Init();
    while (1)
    {
        HAL_Delay(1000);
    }
}