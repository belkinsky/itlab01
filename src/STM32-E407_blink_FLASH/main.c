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
#include "inc/mx_gpio.h"

/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define MESSAGE1   "     STM32F4xx      " 
#define MESSAGE2   " Device running on  " 
#define MESSAGE3   " STM3240_41_G-EVAL  "

// Will declare constant with name like GPIOA_ to easy use in debugger
#define MAKE_IO_CONST(ioPointerName) const typeof(ioPointerName) ioPointerName##_ = ioPointerName;

// Declare IO constants to use in debugger instead of macro
MAKE_IO_CONST(GPIOA);
MAKE_IO_CONST(GPIOB);
MAKE_IO_CONST(GPIOC);
MAKE_IO_CONST(GPIOG);
MAKE_IO_CONST(TIM3);

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** Pin config notice:
 * | Name | type |Arduino| MCU pin
 * |------|------|-------|--------
 * |gerkon|    In| D13   | PA5 41
 * |servo |outPWM| D11   | PB5 135 (Manual says '43' incorrectly)
 * |motion|    In| D7    | PG8 93
 * |Tx BT |   Out| D1    | PB6 136
 * |Rx BT |    In| D0    | PB7 137
 * |led   |   Out|       | PC13 7
 */

static void init()
{
  mx_pinout_config();
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

  TIM_TimeBaseInitTypeDef tim3Init;
  TIM_TimeBaseStructInit(&tim3Init);  // ������������� ��������� TIM_TimeBaseInitTypeDef
  tim3Init.TIM_Prescaler = 8;       // freq = 2 000 000 Hz / Prescaler
  tim3Init.TIM_Period=20000 - 1;  // 50 Hz (��� �����)
  tim3Init.TIM_ClockDivision = TIM_CKD_DIV1;
  tim3Init.TIM_CounterMode=TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM3_,&tim3Init);

  TIM_OCInitTypeDef tim3Chan2Init;
  TIM_OCStructInit(&tim3Chan2Init);  // ������������� ��������� TIM_OCInitTypeDef
  tim3Chan2Init.TIM_OCMode = TIM_OCMode_PWM1;   // �������� � ������ ��� (PWM)
  tim3Chan2Init.TIM_OutputState = TIM_OutputState_Enable;
  tim3Chan2Init.TIM_Pulse = 5000; //1500;  // ����. ����������?
  tim3Chan2Init.TIM_OCPolarity = TIM_OCPolarity_High;  // ������������� ����������
  TIM_OC2Init(TIM3_,&tim3Chan2Init);  /// ������� ������ � 2� �����
  TIM_OC2PreloadConfig(TIM3_,TIM_OCPreload_Enable);

  /*TIM3->CCER |= TIM_CCER_CC2E;
  TIM3->CCMR2|= (TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2);
  TIM3->CCMR2 &= ~TIM_CCMR2_OC3M_0;
  //����������� ������������ ���� ������� ���� ���� � ������ 50 ��
  TIM3->PSC = 6;*/
  //��������� ������
  //TIM3->CR2 |= TIM_CR1_CEN;
  TIM_Cmd(TIM3_, ENABLE);

}

#define MAX(expr1, expr2) \
({\
		typeof(expr1) a = (expr1);\
		typeof(expr2) b = (expr2);\
		(a > b)? a : b;\
})

#define MIN(expr1, expr2) \
({\
		typeof(expr1) a = (expr1);\
		typeof(expr2) b = (expr2);\
		(a < b)? a : b;\
})

#define CLIP_BETWEEN(value, min, max) \
({\
	typeof(value) min_ = MIN(min, max);\
	typeof(value) max_ = MAX(max, min);\
	(value > max_)? max_ : ((value < min_) ? min_: (value));\
})

#define SERVO_180 12500
#define SERVO_0 2500
void servoSetPos(int pos)
{
	const uint32_t tmp = (SERVO_180 - SERVO_0) / 180;
	uint32_t regVal = SERVO_0 + tmp * pos;
	regVal = CLIP_BETWEEN(regVal, SERVO_0, SERVO_180);
	TIM_SetCompare2(TIM3_, regVal);
}


int main(void)
{

	init();

	int servoPos = 0;
	int increment = 1;
	while (1)
	{

		//gerkon
		if (GPIO_ReadInputDataBit(GPIOA_, GPIO_IDR_IDR_5) != Bit_SET)
		{
			if((servoPos > 180) || (servoPos < 0))
				increment = -increment;

			servoPos+= increment;
			servoSetPos(servoPos);
		}

		//motion
		if(GPIO_ReadInputDataBit(GPIOG_, GPIO_IDR_IDR_8) == Bit_SET)
		{
			GPIO_SetBits(GPIOC_, GPIO_Pin_13);
		}
		else
		{
			GPIO_ResetBits(GPIOC_, GPIO_Pin_13);
		}

		Delay(100000);
	}

}


/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in 10 ms.
  * @retval None
  */
void Delay(volatile uint32_t nTime)
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
