#include "Board/Board.h"

#include <stm32f1xx_hal.h>
void Error_Handler(void)
{
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1)
    {
    }
    /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
    /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line
   number, ex: printf("Wrong parameters value: file %s on line %d\r\n", file,
   line) */
    /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

void SystemClock_Config(void)
{
    HAL_StatusTypeDef ret = HAL_OK;
    RCC_OscInitTypeDef RCC_OscInitStructure;
    RCC_ClkInitTypeDef RCC_ClkInitStructure;

    RCC_OscInitStructure.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStructure.HSEState       = RCC_HSE_ON;
    RCC_OscInitStructure.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
    RCC_OscInitStructure.PLL.PLLState   = RCC_PLL_ON;
    RCC_OscInitStructure.PLL.PLLSource  = RCC_PLLSOURCE_HSE;
    RCC_OscInitStructure.PLL.PLLMUL     = RCC_PLL_MUL9;
    ret                                 = HAL_RCC_OscConfig(&RCC_OscInitStructure);

    if (ret != HAL_OK)
        while (1);

    RCC_ClkInitStructure.ClockType      = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
    RCC_ClkInitStructure.SYSCLKSource   = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStructure.AHBCLKDivider  = RCC_SYSCLK_DIV1;
    RCC_ClkInitStructure.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStructure.APB2CLKDivider = RCC_HCLK_DIV1;
    ret                                 = HAL_RCC_ClockConfig(&RCC_ClkInitStructure, FLASH_LATENCY_2);

    if (ret != HAL_OK)
        while (1);
}

void Board_Init(void)
{
    HAL_Init();
    SystemClock_Config();
}