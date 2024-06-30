#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "SYS_TICK.h"
#include "SYS_TICK_prv.h"





void Systick_vid_init(u32 copy_u32TimeMs){
    u32 Loc_u32CLK;  //Ticks calculation 

    //calculation: (system clock / 8 ) / millisecond to get how many ticks for 1 ms
    Loc_u32CLK =  (STK_u32_SYSCLK / STK_AHB_DIV8) / STK_1MILLISEC;

    //load value into the register 
    STK->LOAD = copy_u32TimeMs * Loc_u32CLK;
    STK->VAL = syst 

}



void Systick_vidSetCallBack(STKisr Add_pfCallBackFun);



void Systick_vid_Start(void);




void Systick_vid_Stop(void);