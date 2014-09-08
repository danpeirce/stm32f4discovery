/**
*****************************************************************************
**
**  File        : main.c
**
**  Abstract    : main function.
**
**  Functions   : main
**
**  Distribution: The file is distributed “as is,” without any warranty
**                of any kind.
**
**  altered from example at http://www.emblocks.org/forum/viewtopic.php?f=26&t=171
*****************************************************************************
*/

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "uc.h"

#include <string.h>
#include <stdio.h>
#include "usbd_cdc_vcp.h"

__ALIGN_BEGIN USB_OTG_CORE_HANDLE  USB_OTG_dev __ALIGN_END;

const uint16_t LEDS = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
const uint16_t LED[4] = {GPIO_Pin_12, GPIO_Pin_13, GPIO_Pin_14, GPIO_Pin_15};

#define OUT_STR " is pressed\r\n"
int main() {

    char c, buffer_out[32];

    uc_init();


    GPIO_InitTypeDef gpio;
    GPIO_StructInit(&gpio);
    gpio.GPIO_Mode = GPIO_Mode_OUT;
    gpio.GPIO_Pin = LEDS;
    GPIO_Init(GPIOD, &gpio);
    GPIO_SetBits(GPIOD, LEDS);


	while(1)
	{
		if(usb_cdc_kbhit()){
			c = usb_cdc_getc();
         //sprintf(buffer_out,"%c is pressed\r\n",c);
			buffer_out[0] = c;
			memcpy(buffer_out + 1, OUT_STR, sizeof(OUT_STR));
			usb_cdc_printf(buffer_out);

			switch(c){
				case '3':
					STM_EVAL_LEDToggle(LED3);
					sprintf(buffer_out,"LED%c = %u\r\n",c,GPIO_ReadInputDataBit(GPIOD,LED3_PIN));
					usb_cdc_printf(buffer_out);
					break;
				case '4':
					STM_EVAL_LEDToggle(LED4);
					sprintf(buffer_out,"LED%c = %u\r\n",c,GPIO_ReadInputDataBit(GPIOD,LED4_PIN));
					usb_cdc_printf(buffer_out);
					break;
				case '5':
					STM_EVAL_LEDToggle(LED5);
					sprintf(buffer_out,"LED%c = %u\r\n",c,GPIO_ReadInputDataBit(GPIOD,LED5_PIN));
					usb_cdc_printf(buffer_out);
					break;
				case '6':
					STM_EVAL_LEDToggle(LED6);
					sprintf(buffer_out,"LED%c = %u\r\n",c,GPIO_ReadInputDataBit(GPIOD,LED6_PIN));
					usb_cdc_printf(buffer_out);
					break;
			}

		}
	}

    return 0;
}
