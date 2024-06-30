#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "RCC_prv.h"
#include "RCC.h"


void RCC_VidSelectSysCLK(u8 Copy_u8SysClk){
    u16 LOC_u16TimeOut = 500;
    /*HSI As system clock */
    switch (Copy_u8SysClk)
    {
    case RCC_HSI:
        /*select HSI as clock*/
        CLR_BIT(RCC->CFGR,0);
        CLR_BIT(RCC->CFGR,1);
        /*enable HSI */
        SET_BIT(RCC->CR);
        break;
    case RCC_HSE_CRYSTAL:
        /*select HSE as clock*/
        CLR_BIT(RCC->CFGR,0);
        CLR_BIT(RCC->CFGR,1);
        /*enable HSE */
        CLR_BIT(RCC->CR, 18);	  
    	SET_BIT(RCC->CR, 16); 
        break;
     case RCC_HSE_RC:
        /*select HSE as clock*/
        SET_BIT(RCC->CFGR,0);	  
        CLR_BIT(RCC->CFGR,1);
        /* Enable HSE BYPASS == 1 FOR RC */
        SET_BIT(RCC->CR, 18);    
        SET_BIT(RCC->CR, 16);
        break;
    case RCC_PLL:
        /*select PLL as clock*/
        CLR_BIT(RCC->CFGR,0);	  
		SET_BIT(RCC->CFGR,1); 
        
        RCC->CFGR &= ~((0b1111)<<18);
		RCC->CFGR |= (PLL_CLOCK_MULTIPLE_BY_9) << 18;
        while(LOC_u16TimeOut-- && !(RCC->CR & PLL_RDY_MSK)){
					/*IF THE CLK RDY BREAK THE LOOP*/
				if ((RCC->CR & PLLRDY_MSK)) {
						break;
					}
				}
		
        

        break;
    
    default:
        break;
    }
}
void RCC_ControlClk(u8 copy_u8SysClk,u8 copy_u8SysClKState){
    u16 LOC_u16TimeOut = 500; 
    switch (copy_u8SysClk)
    {
    case RCC_HSI:
        switch (copy_u8SysClKState)
        {
        case RCC_CLK_ON:
            //set HSI ON 
            RCC->CR |= HSI_ON_MSK;
            //Wait till HSI is ready 
            while(LOC_u16TimeOut-- && !(RCC->CR & HSI_RDY_MSK)){
					/*IF THE CLK RDY BREAK THE LOOP*/
				if ((RCC->CR & HSI_ON_MSK)) {
						break;
					}
				}
        
            break;
        case RCC_CLK_OFF:
            RCC->CR &= ~(HSI_ON_MSK);
       
        }
        break;
    case RCC_HSE:
        switch (copy_u8SysClKState)
        {
        case RCC_CLK_ON:
            //SET HSE on 
            RCC->CR |= HSE_ON_MSK;
            //Wait till HSE is ready 
            while(LOC_u16TimeOut-- && !(RCC->CR & HSE_RDY_MSK)){
					/*IF THE CLK RDY BREAK THE LOOP*/
				if ((RCC->CR & HSE_ON_MSK)) {
						break;
					}
				}
            
            break;
        case RCC_CLK_OFF:
             RCC->CR &= ~(HSE_ON_MSK);
        
        }
    case RCC_PLL:
        switch (copy_u8SysClKState)
        {
        case RCC_CLK_ON:
             RCC->CR |= PLL_ON_MSK;
            //Wait till PLL is ready 
            while(LOC_u16TimeOut-- && !(RCC->CR & PLL_RDY_MSK)){
					/*IF THE CLK RDY BREAK THE LOOP*/
				if ((RCC->CR & PLL_ON_MSK)) {
						break;
					}
				}
        
            break;
        case RCC_CLK_OFF:
            RCC->CR &= ~(PLL_ON_MSK);
            break;
        
        default:
            break;
        }
    default:
        break;
    }
}
void RCC_CheckClk(u8 copy_u8Clk,pu8 ADD_pu8RDYStatus){
    switch (copy_u8Clk)
    {
    case RCC_HSI:
        if( RCC->CR & HSI_RDY_MSK){
            *ADD_pu8RDYStatus = RCC_CLK_RDY;
        }
        else{
            *ADD_pu8RDYStatus = RCC_CLK_NOT_RDY
        }
        /* code */
        break;
    
    case RCC_HSE:
        if(RCC->CR & HSE_RDY_MSK){
            *ADD_pu8RDYStatus = RCC_CLK_RDY;
        }
        else{
            *ADD_pu8RDYStatus = RCC_CLK_NOT_RDY;
        }
        break;
    case RCC_PLL:
        if (RCC->CR & PLL_RDY_MSK)
        {
            *ADD_pu8RDYStatus = RCC_CLK_RDY;
        }
        else{
            *ADD_pu8RDYStatus = RCC_CLK_NOT_RDY;
        }
        
    }
}
void RCC_cnfgrClk(u8 copy_u8M,u8 copy_u16N,u8 copy_u8P, u8 copy_u8SrcPll,u8 copy_u8Q){
    RCC->CR &= ~PLL_ON_MSK;

    // Wait until PLL is unlocked
    while ((RCC->CR & PLL_RDY_MSK) != 0);

    // Configure PLL source
    RCC->PLLCFGR = (RCC->PLLCFGR & ~PLLSRC_MSK) | (copy_u8SrcPll << PLLSRC);

    // Configure PLL parameters
    RCC->PLLCFGR = (RCC->PLLCFGR & ~PLLM_Msk) | (copy_u8M << PLLM);
    RCC->PLLCFGR = (RCC->PLLCFGR & ~PLLN_Msk) | ((u32)copy_u16N << PLLN);
    RCC->PLLCFGR = (RCC->PLLCFGR & ~PLLP_Msk) | ((copy_u8P >> 1) << PLLP);
    RCC->PLLCFGR = (RCC->PLLCFGR & ~PLLQ_Msk) | (copy_u8Q << PLLQ);

    // Enable PLL
    RCC->CR |= PLL_ON_MSK;

    // Wait until PLL is ready
    while ((RCC->CR & PLL_RDY_MSK) == 0);
    
    // Set PLL as system clock source
    RCC->CFGR = (RCC->CFGR & ~SW_MSK) | SW;

    // Wait until PLL is used as system clock source
    while ((RCC->CFGR & SWS_MSK) != SWS);
}


void RCC_VidEnablePeriphral(u8 Copy_u8PeriphralBus, u8 Copy_u8Peripheral){
    if(Copy_u8Peripheral < NUM_OF_PERIPHERALS){
        switch (Copy_u8PeriphralBus)
        {
        case RCC_AHB1:
            SET_BIT(RCC->AHB1ENR,Copy_u8Peripheral);
            break;
        case RCC_AHB2:
            SET_BIT(RCC->AHB2ENR,Copy_u8Peripheral);
            break;
        case RCC_APB1:
            SET_BIT(RCC->APB1ENR,Copy_u8Peripheral);
            break;
        case RCC_AHB2:
            SET_BIT(RCC->AHB2ENR,Copy_u8Peripheral);
            break;
        default:
            break;
        }
    }
    else{
        
    }
}

void RCC_VidDisablePeriphral(u8 Copy_u8PeriphralBus, u8 Copy_u8Peripheral){
    if(Copy_u8Peripheral < NUM_OF_PERIPHERALS){
        switch (Copy_u8PeriphralBus)
        {
        case RCC_AHB1:
            CLR_BIT(RCC->AHB1ENR,Copy_u8Peripheral);
            break;
        case RCC_AHB2:
            CLR_BIT(RCC->AHB2ENR,Copy_u8Peripheral);
            break;
        case RCC_APB1:
            CLR_BIT(RCC->APB1ENR,Copy_u8Peripheral);
            break;
        case RCC_AHB2:
            CLR_BIT(RCC->AHB2ENR,Copy_u8Peripheral);
            break;
        default:
            break;
        }
    }
    else{
        
    }
}