#ifndef SYS_TICK_PRV_H
#define SYS_TICK_PRV_H


typedef struct 
{
    volatile u32  CTRL;
    volatile u32  LOAD;
    volatile u32  VAL;
    volatile u32 CALIB;
}STK_t; 

#define STK_BASE_ADDRESS 0xE000E010

#define STK ( ( volatile STK_t* ) STK_BASE_ADDRESS)


#endif