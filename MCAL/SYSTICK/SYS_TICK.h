#ifndef SYS_TICK_H_
#define SYS_TICK_H_

void Event_handler (void);

#define STK_AHB_DIV1    0x06
#define STK_AHB_DIV8    0x02

#define STK_ENABLE      ((u32) 0x01)
#define STK_DISABLE     ((u32) 0x00)
#define STK_RESET        0 


#define STK_1MILLISEC   ((u32)1000)
#define STK_u32_SYSCLK  32000000
#define STK_CLKSRC      STK_AHB_DIV8


void Systick_vid_init(u32 copy_u32TimeMs);
void Systick_vidSetCallBack(STKisr Add_pfCallBackFun);
void Systick_vid_Start(void);
void Systick_vid_Stop(void);


#endif