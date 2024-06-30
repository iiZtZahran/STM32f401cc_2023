#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


typedef struct{

    volatile u32 CR      ;
    volatile u32 PLLCFGR ;
    volatile u32 CFGR    ;
    volatile u32 CIR     ;
    volatile u32 AHB1RSTR;
    volatile u32 AHB2RSTR;
    volatile u32 Reserved1[2];
    volatile u32 APB1RSTR;
    volatile u32 APB2RSTR;
    volatile u32 Reserved2[2];
    volatile u32 AHB1ENR;
    volatile u32 AHB2ENR;
    volatile u32 Reserved3[2];
    volatile u32 APB2ENR;
    volatile u32 APB1ENR;
    volatile u32 Reserved4[2];
    volatile u32 AHB1LPENR;
    volatile u32 AHB2LPENR;
    volatile u32 Reserved5[2];
    volatile u32 APB1LPENR;
    volatile u32 APB2LPENR;
    volatile u32 Reserved6[2];
    volatile u32 BDCR;
    volatile u32 CSR;
    volatile u32 Reserved7[2];
    volatile u32 SSCGR;
    volatile u32 PLLI2SCFGR;
    volatile u32 Reserved8;
    volatile u32 DCKCFGR;
}RCC_REG;


/* base address of the RCC register */
#define RCC_BASE_ADDRESS 0x4002 3800

/* MAP the RCC to its address */
#define RCC ( ( volatile RCC_REG* ) RCC_BASE_ADDRESS)

#endif