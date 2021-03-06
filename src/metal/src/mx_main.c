/**
  ******************************************************************************
  * File Name          : mx_main.c
  * Date               : 12/12/2013 23:36:11
  * Description        : Main program body
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

#if 0 //We don't want to use autogenerated main()
//Don't forget to call mx_pinout_config() from our real main()

/* USER CODE END 0 */

int main(void)
{
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/* MCU Configuration----------------------------------------------------------*/
mx_pinout_config();

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
 
  /* Infinite loop */
  while (1)
  {
  }
  
/* USER CODE BEGIN 3 */
#endif //#if 0
static void __attribute__((__unused__)) dummy() { //Use this to deal with trailing '}' after user code block
/* USER CODE END 3 */ 
}
