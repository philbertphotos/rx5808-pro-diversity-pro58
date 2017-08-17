#include "stm32f1xx_hal.h"
/**
1. Disable the I2C peripheral by clearing the PE bit in I2Cx_CR1 register.
2. Configure the SCL and SDA I/Os as General Purpose Output Open-Drain, High level
(Write 1 to GPIOx_ODR).
3. Check SCL and SDA High level in GPIOx_IDR.
4. Configure the SDA I/O as General Purpose Output Open-Drain, Low level (Write 0 to
GPIOx_ODR).
5. Check SDA Low level in GPIOx_IDR.
6. Configure the SCL I/O as General Purpose Output Open-Drain, Low level (Write 0 to
GPIOx_ODR).
7. Check SCL Low level in GPIOx_IDR.
8. Configure the SCL I/O as General Purpose Output Open-Drain, High level (Write 1 to
GPIOx_ODR).
9. Check SCL High level in GPIOx_IDR.
10. Configure the SDA I/O as General Purpose Output Open-Drain , High level (Write 1 to
GPIOx_ODR).
11. Check SDA High level in GPIOx_IDR.
12. Configure the SCL and SDA I/Os as Alternate function Open-Drain.
13. Set SWRST bit in I2Cx_CR1 register.
14. Clear SWRST bit in I2Cx_CR1 register.
15. Enable the I2C peripheral by setting the PE bit in I2Cx_CR1 register.


#define I2C_DISPLAY_SCL_Pin GPIO_PIN_6
#define I2C_DISPLAY_SCL_GPIO_Port GPIOB
#define I2C_DISPLAY_SDA_Pin GPIO_PIN_7
#define I2C_DISPLAY_SDA_GPIO_Port GPIOB
**/
//void HAL_GPIO_WRITE_ODR(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
//
//void HAL_I2C_ClearBusyFlagErrata_2_14_7(I2C_HandleTypeDef *hi2c) {
//
//    static uint8_t resetTried = 0;
//    if (resetTried == 1) {
//        return ;
//    }
//    uint32_t SDA_PIN = I2C_DISPLAY_SDA_Pin;//NUCLEO_I2C_EXPBD_SDA_PIN;
//    uint32_t SCL_PIN = I2C_DISPLAY_SCL_Pin;//NUCLEO_I2C_EXPBD_SCL_PIN;
//    GPIO_InitTypeDef GPIO_InitStruct;
//
//    // 1
//    __HAL_I2C_DISABLE(hi2c);
//
//    // 2
//    GPIO_InitStruct.Pin = SDA_PIN|SCL_PIN;
//    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;//GPIO_SPEED_FAST;
//    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//
//    HAL_GPIO_WRITE_ODR(GPIOB, SDA_PIN);
//    HAL_GPIO_WRITE_ODR(GPIOB, SCL_PIN);
//
//    // 3
//    GPIO_PinState pinState;
//    if (HAL_GPIO_ReadPin(GPIOB, SDA_PIN) == GPIO_PIN_RESET) {
//        for(;;){}
//    }
//    if (HAL_GPIO_ReadPin(GPIOB, SCL_PIN) == GPIO_PIN_RESET) {
//        for(;;){}
//    }
//
//    // 4
//    GPIO_InitStruct.Pin = SDA_PIN;
//    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//
//    HAL_GPIO_TogglePin(GPIOB, SDA_PIN);
//
//    // 5
//    if (HAL_GPIO_ReadPin(GPIOB, SDA_PIN) == GPIO_PIN_SET) {
//        for(;;){}
//    }
//
//    // 6
//    GPIO_InitStruct.Pin = SCL_PIN;
//    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//
//    HAL_GPIO_TogglePin(GPIOB, SCL_PIN);
//
//    // 7
//    if (HAL_GPIO_ReadPin(GPIOB, SCL_PIN) == GPIO_PIN_SET) {
//        for(;;){}
//    }
//
//    // 8
//    GPIO_InitStruct.Pin = SDA_PIN;
//    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//
//    HAL_GPIO_WRITE_ODR(GPIOB, SDA_PIN);
//
//    // 9
//    if (HAL_GPIO_ReadPin(GPIOB, SDA_PIN) == GPIO_PIN_RESET) {
//        for(;;){}
//    }
//
//    // 10
//    GPIO_InitStruct.Pin = SCL_PIN;
//    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//
//    HAL_GPIO_WRITE_ODR(GPIOB, SCL_PIN);
//
//    // 11
//    if (HAL_GPIO_ReadPin(GPIOB, SCL_PIN) == GPIO_PIN_RESET) {
//        for(;;){}
//    }
//
//    // 12
//    GPIO_InitStruct.Pin = SDA_PIN|SCL_PIN;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
//    //GPIO_InitStruct. //.Alternate = NUCLEO_I2C_EXPBD_SCL_SDA_AF;
//    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//
//   // 13
//   hi2c->Instance->CR1 |= I2C_CR1_SWRST;
//
//   // 14
//   hi2c->Instance->CR1 ^= I2C_CR1_SWRST;
//
//   // 15
//   __HAL_I2C_ENABLE(hi2c);
//
//   resetTried = 1;
//}
//
//void HAL_GPIO_WRITE_ODR(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
//{
//  /* Check the parameters */
//  assert_param(IS_GPIO_PIN(GPIO_Pin));
//
//  GPIOx->ODR |= GPIO_Pin;
//}


void I2C_Reset(I2C_HandleTypeDef hi2c, void(*initFunc)()){
    //Send 9 Stops
    for (int i = 0; i < 9; i++) {
    	//HAL_I2C
        //I2C_StopCondition();

    }
    //Software RST
    HAL_I2C_MspInit(&hi2c);
    SET_BIT(hi2c.Instance->CR1, I2C_CR1_SWRST);
    //WAIT_I2C;
    while (HAL_I2C_GetState(&hi2c) != HAL_I2C_STATE_READY) {}
    CLEAR_BIT(hi2c.Instance->CR1, I2C_CR1_SWRST);
    while (HAL_I2C_GetState(&hi2c) != HAL_I2C_STATE_READY) {}
    //MX_I2C3_Init();
    initFunc();
}
