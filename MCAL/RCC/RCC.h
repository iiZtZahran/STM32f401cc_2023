/********************************************************/
/* Author   : Mohamed Zahran  */
/* Version  : V01             */
/********************************************************/
#ifndef RCC_H_
#define RCC_H_

#define RCC_AHB1 0
#define RCC_AHB2 1
#define RCC_APB1 2
#define RCC_APB2 3

/* CLOCK TYPES*/
#define RCC_HSE_CRYSTAL 0 
#define RCC_HSE_RC      1 
#define RCC_HSI         2
#define RCC_PLL         3
#define RCC_HSE         4

/*******************   PLL INPUT Options   ****************************/
#define RCC_PLL_IN_HSI_DIV_2  0
#define RCC_PLL_IN_HSE_DIV_2  1
#define RCC_PLL_IN_HSE        2

/*******************   PLL MUL factor Options   ****************************/

#define NO_CLOCK_FACTOR                                0b0000
#define PLL_CLOCK_MULTIPLE_BY_2                        0b0000
#define PLL_CLOCK_MULTIPLE_BY_3				 	       0b0001
#define PLL_CLOCK_MULTIPLE_BY_4                        0b0010
#define PLL_CLOCK_MULTIPLE_BY_5                        0b0011
#define PLL_CLOCK_MULTIPLE_BY_6                        0b0100
#define PLL_CLOCK_MULTIPLE_BY_7                        0b0101
#define PLL_CLOCK_MULTIPLE_BY_8                        0b0110
#define PLL_CLOCK_MULTIPLE_BY_9                        0b0111
#define PLL_CLOCK_MULTIPLE_BY_10                       0b1000
#define PLL_CLOCK_MULTIPLE_BY_11                       0b1001
#define PLL_CLOCK_MULTIPLE_BY_12                       0b1010
#define PLL_CLOCK_MULTIPLE_BY_13                       0b1011
#define PLL_CLOCK_MULTIPLE_BY_14                       0b1100
#define PLL_CLOCK_MULTIPLE_BY_15                       0b1101
#define PLL_CLOCK_MULTIPLE_BY_16          

/*******************   Various definitions    ****************************/
#define NUM_OF_PERIPHERALS 31 

#define RCC_CLK_RDY      1 
#define RCC_CLK_NOT_RDY  0

/*******************   MASKS    ****************************/
#define HSI_ON_MSK  ((u32)0x00000001)
#define HSI_RDY_MSK ((u32)0x00000002)

#define HSE_ON_MSK  ((u32)0x00010000)
#define HSE_RDY_MSK ((u32)0x00020000)

#define PLL_ON_MSK  ((u32)0x01000000)
#define PLL_RDY_MSK ((u32)0x02000000)

#define SW_MSK			0x00000003
#define SWS_MSK			0x0000000C

#define PLLM			4
#define PLLN			6
#define PLLP			16
#define PLLSRC			22
#define PLLSRC_MSK		0x00400000
#define PLLQ			24
#define SW  			0
#define SWS				2

#define PLLM_Msk   ((u32)0x003F0000)
#define PLLN_Msk   ((u32)0x7FC00000)
#define PLLP_Msk   ((u32)0x30000)
#define PLLQ_Msk   ((u32)0xF0000000)

/*******************   clock status ****************************/

#define RCC_CLK_OFF 0 
#define RCC_CLK_ON  1

#define 

void RCC_VidSelectSysCLK(u8 Copy_u8SysClk);
void RCC_ControlClk(u8 copy_u8SysClk);
void RCC_cnfgrClk(u8 copy_u8M,u8 copy_u16N,u8 copy_u8P, u8 copy_u8SrcPll,u8 copy_u8Q);
void RCC_VidEnablePeriphral(u8 Copy_u8PeriphralBus, u8 Copy_u8Peripheral);
void RCC_CheckClk(u8 copy_u8Clk,pu8 ADD_pu8RDYStatus);
void RCC_VidDisablePeriphral(u8 Copy_u8PeriphralBus, u8 Copy_u8Peripheral);