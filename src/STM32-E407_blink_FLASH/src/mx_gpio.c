/**
  ******************************************************************************
  * File Name          : mx_gpio.c
  * Date               : 12/12/2013 23:36:11
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
  ******************************************************************************
  *
  * COPYRIGHT 2013 STMicroelectronics
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

/* Includes ------------------------------------------------------------------*/
#include "inc/mx_gpio.h"
/* USER CODE BEGIN 0 */
//This file was generated from pinConfig_MicroXplorer.ioc by MicroXplorer Eclipse plugin
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

void mx_pinout_config(void) {
	/* Private typedef ---------------------------------------------------------*/
	GPIO_InitTypeDef GPIO_InitStruct;


	/** TIM3 GPIO Configuration	
		 PA6	 ------> TIM3_CH1
		 PB0	 ------> TIM3_CH3
		 PB1	 ------> TIM3_CH4
		 PB5	 ------> TIM3_CH2
	*/


	/*Enable or disable the AHB1 peripheral clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOB, ENABLE);


	//!!! GPIO_Init is commented because some parameters are missing
	//GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
	//GPIO_InitStruct.GPIO_Mode = ;
	//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	//GPIO_Init(GPIOA, &GPIO_InitStruct);


	//!!! GPIO_Init is commented because some parameters are missing
	//GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	//GPIO_InitStruct.GPIO_Mode = ;
	//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	//GPIO_Init(GPIOB, &GPIO_InitStruct);


	//!!! GPIO_Init is commented because some parameters are missing
	//GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
	//GPIO_InitStruct.GPIO_Mode = ;
	//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	//GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pin */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_TIM3);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource0, GPIO_AF_TIM3);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource1, GPIO_AF_TIM3);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_TIM3);


	/** USART1 GPIO Configuration	
		 PB6	 ------> USART1_TX
		 PB7	 ------> USART1_RX
	*/


	/*Enable or disable the AHB1 peripheral clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	/*Configure GPIO pin */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_USART1);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_USART1);


	/** Configure pins as GPIO
		 PC13	 ------> GPIO_Output
		 PA5	 ------> GPIO_Input
		 PG8	 ------> GPIO_Input
	*/


	/*Enable or disable the AHB1 peripheral clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC|RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOG, ENABLE);

	/*Configure GPIO pin */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);

	/*Configure GPIO pin */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pin */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOG, &GPIO_InitStruct);
}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
