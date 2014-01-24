/*
 * ChibiOS/Servo is a small library to easily interface RC servos with ChibiOS/RT.
 *
 * BSD licensed
 *
 * Author: Joel Bodenmann aka Tectu   <joel@unormal.org>
 */

#include "chconf.h"
#include "mcuconf.h"
#include "ffconf.h"


#include "servo.h"

static PWMConfig pwmcfg = {
	.frequency = 1000000,        // 1MHz PWM clock frequency
    .period = 20000,                // PWM period 20000 cycles -> freq/period = 50 Hz
    .callback = NULL,                // no callback
    .channels = // channel configuration will set dynamical in servoInit()
    {
    	{.mode = PWM_OUTPUT_DISABLED, .callback = NULL},
    	{.mode = PWM_OUTPUT_DISABLED, .callback = NULL},
    	{.mode = PWM_OUTPUT_DISABLED, .callback = NULL},
    	{.mode = PWM_OUTPUT_DISABLED, .callback = NULL},
    },
};

void servoInit(Servo *servo) {
        /* create the channel configuration */
        PWMChannelConfig chcfg = { PWM_OUTPUT_ACTIVE_HIGH, NULL };
        pwmcfg.channels[servo->pwm_channel] = chcfg;

        /* configure PAL */
        #if defined(STM32F4XX)
                palSetPadMode(servo->port, servo->pin, PAL_MODE_ALTERNATE(PAL_STM32_OTYPE_PUSHPULL));
        #else
                #error "PAL configuration for this device not implemented yet - Please modify servoInit()"
        #endif

        /* start the PWM unit */
        pwmStart(servo->pwm_driver, &pwmcfg);
}

void servoSetValue(Servo *servo, uint16_t value) {
        /* a bit of safty here */
        if(value > servo->max)
                value = servo->max;
        if(value < servo->min)
                value = servo->min;

        pwmEnableChannel(servo->pwm_driver, servo->pwm_channel, (pwmcnt_t)value);
}

void servoSetMax(Servo *servo, uint16_t value) {
        servo->max = value;
}

void servoSetMin(Servo *servo, uint16_t value) {
        servo->min = value;
}

uint16_t servoGetMax(Servo *servo) {
        return (servo->max);
}

uint16_t servoGetMin(Servo *servo) {
        return (servo->min);
}

/*
	void servo::init()
	{
	  mx_pinout_config();

	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	  TIM_TimeBaseInitTypeDef tim3Init;
	  TIM_TimeBaseStructInit(&tim3Init);  // Инициализация структуры TIM_TimeBaseInitTypeDef
	  tim3Init.TIM_Prescaler = 8;       // freq = 2 000 000 Hz / Prescaler
	  tim3Init.TIM_Period=20000 - 1;  // 50 Hz (для серво)
	  tim3Init.TIM_ClockDivision = TIM_CKD_DIV1;
	  tim3Init.TIM_CounterMode=TIM_CounterMode_Up;
	  TIM_TimeBaseInit(TIM3_,&tim3Init);

	  TIM_OCInitTypeDef tim3Chan2Init;
	  TIM_OCStructInit(&tim3Chan2Init);  // Инициализация структуры TIM_OCInitTypeDef
	  tim3Chan2Init.TIM_OCMode = TIM_OCMode_PWM1;   // работаем в режиме ШИМ (PWM)
	  tim3Chan2Init.TIM_OutputState = TIM_OutputState_Enable;
	  tim3Chan2Init.TIM_Pulse = 5000; //1500;  // Коэф. заполнения?
	  tim3Chan2Init.TIM_OCPolarity = TIM_OCPolarity_High;  // положительная полярность
	  TIM_OC2Init(TIM3_,&tim3Chan2Init);  /// заносим данные в 2й канал
	  TIM_OC2PreloadConfig(TIM3_,TIM_OCPreload_Enable);



	  //TIM_Cmd(TIM3_, ENABLE);



	  /* NVIC Configuration */
//	  NVIC_Configuration();

	  /* Configure the USART1 */
//	  USART_Configuration();

	  /* Enable the USART1 Receive interrupt: this interrupt is generated when the
	       USART1 receive data register is not empty */
//	  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
//	}
/*
	void servo::servo_1()
	{
		init();

		int servoPos = 0;
		int increment = 1;
		while (1)
		{

			/*
			//gerkon
			if (GPIO_ReadInputDataBit(GPIOA_, GPIO_IDR_IDR_5) != Bit_SET)
			{
				GPIO_SetBits(GPIOC_, GPIO_Pin_13);
				usartTest();
				GPIO_ResetBits(GPIOC_, GPIO_Pin_13);
				Delay(200000);
			}
			*/
			//motion and servo and led

/*			if(GPIO_ReadInputDataBit(GPIOG_, GPIO_IDR_IDR_8) == Bit_SET)
			{
				GPIO_SetBits(GPIOC_, GPIO_Pin_13);
				TIM_Cmd(TIM3_, ENABLE);
			/*	if((servoPos > 180) || (servoPos < 0))
					increment = -increment;*/
/*			servoSetPos(180);

				//Delay(200000);

			}
			else
			{
				GPIO_ResetBits(GPIOC_, GPIO_Pin_13);
				servoSetPos(0);
				Delay(20000000);

				TIM_Cmd(TIM3_, DISABLE);
			}

			//Delay(100000);
		}
	}*/

