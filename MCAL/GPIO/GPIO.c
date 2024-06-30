#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "GPIO.h"
#include "GPIO.h"

void Gpio_enuInit(GpioPinCfg_t * Add_strGpioCfg) {
   u32 Loc_TmpMdOdPr;
   u8 Loc_u8Iterator = GPIO_ZERO;
   GPIO_RegDef_t * Loc_AddPort = Add_strGpioCfg->GPIO_pvPort;

		for (Loc_u8Iterator = GPIO_ZERO; Loc_u8Iterator <= GPIO_u8_PINS;
				Loc_u8Iterator++) {
			if (Add_strGpioCfg->GPIO_u16Pin & (GPIO_PIN_MSK << Loc_u8Iterator)) {

				Loc_AddPort->GPIOx_MODER &= ~(GPIO_u32MODE_CLR_MSK<< (Loc_u8Iterator * GPIO_u8DOUBLE_BIT));

				Loc_AddPort->GPIOx_MODER |= Loc_TmpMdOdPr<< (Loc_u8Iterator * GPIO_u8DOUBLE_BIT);
				
				Loc_AddPort->GPIOx_OTYPER &= (u32) ~(GPIO_u8PP_OD<< Loc_u8Iterator);
				Loc_AddPort->GPIOx_OTYPER |= Loc_TmpMdOdPr << Loc_u8Iterator;
				
				Loc_AddPort->GPIOx_PUPDR &= (u32) ~(GPIO_u8PULL_CLR_MSK<< (Loc_u8Iterator * GPIO_u8DOUBLE_BIT));
				Loc_AddPort->GPIOx_PUPDR |= Loc_TmpMdOdPr<< (Loc_u8Iterator * GPIO_u8DOUBLE_BIT);
				Loc_AddPort->GPIOx_OSPEEDR &= (u32) ~(GPIO_u8SPEED_CLR_MSK<< (Loc_u8Iterator * GPIO_u8DOUBLE_BIT));
				Loc_AddPort->GPIOx_OSPEEDR |= (u32) (GPIO_u8SPEED_CLR_MSK<< (Loc_u8Iterator * GPIO_u8DOUBLE_BIT));
			}
		}

	
}

void Gpio_setPinValue(GpioPinCfg_t * Add_GpioCfg,u32 Copy_u8Value){

	GPIO_RegDef_t * Loc_AddPort = Add_GpioCfg->GPIO_pvPort;
	
		switch (Copy_u8Value) {
		case GPIO_u32LOW:
			
			Loc_AddPort->GPIOx_BSRR = (u32) (Add_GpioCfg->GPIO_u16Pin
					<< (GPIO_u8VALUE_RST_MSK));
			break;

		case GPIO_u32HIGH:
			
			Loc_AddPort->GPIOx_BSRR = Add_GpioCfg->GPIO_u16Pin;
			break;
			
		default:
			
			break;

	
}

void Gpio_setPinPortValue(void * GPIO_pvPort, u16 Copy_u16Pin,u32 Copy_u8Value){
    switch (Copy_u8Value) {
	case GPIO_u32LOW:
		Loc_AddPort->GPIOx_BSRR = (u32) (Copy_u16Pin << (GPIO_u8VALUE_RST_MSK));
		break;
	case GPIO_u32HIGH:
		Loc_AddPort->GPIOx_BSRR = (Copy_u16Pin);

		break;
	default:
		break;

	}
}
void Gpio_ReadPinValue(GpioPinCfg_t * Add_strGpioCfg,pu32 Add_pu32Value){
    GPIO_RegDef_t * Loc_AddPort = Add_strGpioCfg->GPIO_pvPort;
	
		if (Loc_AddPort->GPIOx_IDR & Add_strGpioCfg->GPIO_u16Pin) {
			
			*Add_pu32Value = GPIO_u32HIGH;
		} else {
			
			*Add_pu32Value = GPIO_u32LOW;
		}

}

void Gpio_ReadPinPortValue(void * GPIO_pvPort, u16 Copy_u16Pin,pu32 Add_pu32Value){
    GPIO_RegDef_t * Loc_AddPort = GPIO_pvPort;
    if (Loc_AddPort->GPIOx_IDR & Copy_u16Pin) {
			
			*Add_pu32Value = GPIO_u32HIGH;
		} else {
			
			*Add_pu32Value = GPIO_u32LOW;
		}
}
void Gpio_SetAlternateFunc(GpioPinCfg_t * Add_strGpioCfg,u8 Copy_u8Function){
    u8 Loc_u8Iterator;
	GPIO_RegDef_t * Loc_AddPort = Add_strGpioCfg->GPIO_pvPort;
    for (Loc_u8Iterator = GPIO_ZERO; Loc_u8Iterator <= GPIO_u8_PINS;Loc_u8Iterator++) {
			if (Add_strGpioCfg->GPIO_u16Pin & (GPIO_PIN_MSK << Loc_u8Iterator)) {
				
				if (Loc_u8Iterator <= GPIO_u8LPINS_MSK) {
					Loc_AddPort->GPIOx_AFRL &= (u32) ~(GPIO_u8ALTERNATE_CLR_MSK << (Loc_u8Iterator * GPIO_u8QUADRO_BIT));
					Loc_AddPort->GPIOx_AFRL |= (u32) (Copy_u8Function << (Loc_u8Iterator * GPIO_u8QUADRO_BIT));
				} else if (Loc_u8Iterator > GPIO_u8LPINS_MSK) {
					Loc_AddPort->GPIOx_AFRH &= (u32) ~(GPIO_u8ALTERNATE_CLR_MSK << ((Loc_u8Iterator - 8) * GPIO_u8QUADRO_BIT));
					Loc_AddPort->GPIOx_AFRH |= (u32) (Copy_u8Function << ((Loc_u8Iterator - 8) * GPIO_u8QUADRO_BIT));
				}

			}
		}
}

