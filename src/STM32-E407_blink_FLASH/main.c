/**
  ******************************************************************************
  * @file    Project/STM32F4xx_StdPeriph_Templates/main.c 
  * @author  MCD Application Team
  * @version V1.0.1
  * @date    13-April-2012
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/*
 * Olimex + Eclipse Helios + OpenOCD project
 *
 *    board: STM32-H407
 *  project: Blinking LED (FLASH)
 *
 *
 */

/* Includes ------------------------------------------------------------------*/

#define USE_STDPERIPH_DRIVER


#include "main.h"

/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
GPIO_InitTypeDef  GPIO_InitStructure;

/* Private define ------------------------------------------------------------*/
#define MESSAGE1   "     STM32F4xx      " 
#define MESSAGE2   " Device running on  " 
#define MESSAGE3   " STM3240_41_G-EVAL  "
#define SERVO_180 8200
#define SERVO_0 1800

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{

  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f4xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f4xx.c file
     */
	 
	/* GPIOG Periph clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

  GPIO_Init(GPIOA, &GPIO_InitStructure);


  /* Configure PG6 and PG8 in output pushpull mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOC, &GPIO_InitStructure);



  while(1){

	  if(GPIOA->IDR & GPIO_IDR_IDR_5)
		  GPIOC->BSRRH = GPIO_Pin_13;
	  else
		  GPIOC->BSRRL = GPIO_Pin_13;

	  Delay(10000);

  
  }

}

void set_pos(uint8_t pos) {
uint32_t tmp=(SERVO_180 - SERVO_0) /180 ;
TIM2->CCR2 = SERVO_0 + tmp * pos;
}
// Функция задержки
void delay(void)
{
volatile uint32_t i;
for (i=1; i != 0xFFFF; i++)
;
}

int Servo(void)
{
//Включем порт B
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
//Включаем Таймер 2
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
GPIO_InitTypeDef PORT;
// Настроим ногу (PA1) к которой подключен сервопривод
PORT.GPIO_Pin = (GPIO_Pin_1);
//Будем использовать альтернативный режим а не обычный GPIO
PORT.GPIO_Mode = GPIO_Mode_AF_PP;
PORT.GPIO_Speed = GPIO_Speed_2MHz;
GPIO_Init(GPIOB, &PORT);
//Разрешаем таймеру использовать ногу PA1 для ШИМа
TIM2->CCER |= (TIM_CCER_CC2E);
TIM2->CCMR1|= (TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2);
//Настраиваем предделитель чтоб частота ШИМа была в районе 50 Гц
TIM2->PSC = 6;
//Запускаем таймер
TIM2->CR1 |= TIM_CR1_CEN;
uint8_t i;
//Начинаем крутить сервой от 0 до 180 градусов.
while(1)
{
for (i=0;i<=180;i++) {
delay();
set_pos(i);
}
}
}

/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in 10 ms.
  * @retval None
  */
void Delay(uint32_t nTime)
{
  while(nTime--);
}

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void TimingDelay_Decrement(void)
{

}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
