#ifndef GPIO_H_
#define GPIO_H_

typedef struct{
	u32 GPIO_u32Mode;
	u32	GPIO_u32Speed;
	void *	GPIO_pvPort;
	u16	GPIO_u16Pin;
}GpioPinCfg_t;

#define	GPIO_u16PIN_00				((u16) 0x0001)
#define	GPIO_u16PIN_01				((u16) 0x0002)
#define	GPIO_u16PIN_02				((u16) 0x0004)
#define	GPIO_u16PIN_03				((u16) 0x0008)
#define	GPIO_u16PIN_04				((u16) 0x0010)
#define	GPIO_u16PIN_05				((u16) 0x0020)
#define	GPIO_u16PIN_06				((u16) 0x0040)
#define	GPIO_u16PIN_07				((u16) 0x0080)
#define	GPIO_u16PIN_08				((u16) 0x0100)
#define	GPIO_u16PIN_09				((u16) 0x0200)
#define	GPIO_u16PIN_10				((u16) 0x0400)
#define	GPIO_u16PIN_11				((u16) 0x0800)
#define	GPIO_u16PIN_12				((u16) 0x1000)
#define	GPIO_u16PIN_13				((u16) 0x2000)
#define	GPIO_u16PIN_14				((u16) 0x4000)
#define	GPIO_u16PIN_15				((u16) 0x8000)

#define GPIO_pvPORTA				((void *) 0x40020000)
#define GPIO_pvPORTB				((void *) 0x40020400)
#define GPIO_pvPORTC				((void *) 0x40020800)
#define GPIO_pvPORTD				((void *) 0x40020C00)
#define GPIO_pvPORTE				((void *) 0x40021000)
#define GPIO_pvPORTH				((void *) 0x40021C00)


#define GPIO_u32MODE_OUTPUT_PP		((u32) 0x00000001)
#define GPIO_u32MODE_OUTPUT_PP_PU	((u32) 0x00000101)
#define GPIO_u32MODE_OUTPUT_PP_PD	((u32) 0x00000201)
#define GPIO_u32MODE_OUTPUT_OD		((u32) 0x00000011)
#define GPIO_u32MODE_OUTPUT_OD_PU	((u32) 0x00000111)
#define GPIO_u32MODE_OUTPUT_OD_PD	((u32) 0x00000211)

#define GPIO_u32MODE_INPUT			((u32) 0x00000000)
#define GPIO_u32MODE_INPUT_PU		((u32) 0x00000100)
#define GPIO_u32MODE_INPUT_PD		((u32) 0x00000200)

#define GPIO_u32MODE_AF_PP			((u32) 0x00000002)
#define GPIO_u32MODE_AF_PP_PU		((u32) 0x00000102)
#define GPIO_u32MODE_AF_PP_PD		((u32) 0x00000202)
#define GPIO_u32MODE_AF_OD			((u32) 0x00000012)
#define GPIO_u32MODE_AF_OD_PU		((u32) 0x00000112)
#define GPIO_u32MODE_AF_OD_PD		((u32) 0x00000212)

#define GPIO_u32MODE_ANALOG			((u32) 0x00000003)

#define GPIO_u8PULL_OFF				((u8) 0x00)
#define GPIO_u8PULL_UP				((u8) 0x01)
#define GPIO_u8PULL_DOWN			((u8) 0x02)

#define GPIO_u8SPEED_LOW			((u8) 0x00)
#define GPIO_u8SPEED_MID			((u8) 0x01)
#define GPIO_u8SPEED_HIGH			((u8) 0x02)
#define GPIO_u8SPEED_VERY_HIGH		((u8) 0x03)

#define GPIO_u32LOW					((u8) 0x00)
#define GPIO_u32HIGH				((u8) 0x01)

#define GPIO_u8ALTERNATE_FUNC_00		((u8) 0x00)
#define GPIO_u8ALTERNATE_FUNC_01		((u8) 0x01)
#define GPIO_u8ALTERNATE_FUNC_02		((u8) 0x02)
#define GPIO_u8ALTERNATE_FUNC_03		((u8) 0x03)
#define GPIO_u8ALTERNATE_FUNC_04		((u8) 0x04)
#define GPIO_u8ALTERNATE_FUNC_05		((u8) 0x05)
#define GPIO_u8ALTERNATE_FUNC_06		((u8) 0x06)
#define GPIO_u8ALTERNATE_FUNC_07		((u8) 0x07)
#define GPIO_u8ALTERNATE_FUNC_08		((u8) 0x08)
#define GPIO_u8ALTERNATE_FUNC_09		((u8) 0x09)
#define GPIO_u8ALTERNATE_FUNC_10		((u8) 0x0A)
#define GPIO_u8ALTERNATE_FUNC_11		((u8) 0x0B)
#define GPIO_u8ALTERNATE_FUNC_12		((u8) 0x0C)
#define GPIO_u8ALTERNATE_FUNC_13		((u8) 0x0D)
#define GPIO_u8ALTERNATE_FUNC_14		((u8) 0x0E)
#define GPIO_u8ALTERNATE_FUNC_15		((u8) 0x0F)

void Gpio_enuInit(GpioPinCfg_t * Add_strGpioCfg) ;
void Gpio_setPinValue(GpioPinCfg_t * Add_strGpioCfg,u32 Copy_u8Value);
void Gpio_setPinPortValue(void * GPIO_pvPort, u16 Copy_u16Pin,u32 Copy_u8Value);
void Gpio_ReadPinValue(GpioPinCfg_t * Add_strGpioCfg,pu32 Add_pu32Value);
void Gpio_ReadPinPortValue(void * GPIO_pvPort, u16 Copy_u16Pin,pu32 Add_pu32Value);
void Gpio_SetAlternateFunc(GpioPinCfg_t * Add_strGpioCfg,u8 Copy_u8Function);
#endif