/********************************************************/
/* Author   : Mohamed Zahran  */
/* Version  : V01             */
/********************************************************/
 
#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(REG,BITNO) (REG) |=  (1 << (BITNO))
#define CLR_BIT(REG,BITNO) (REG) &= ~(1 << (BITNO))
#define TOG_BIT(REG,BITNO) (REG) ^=  (1 << (BITNO))
#define GET_BIT(REG,BITNO) (((REG) >> (BITNO)) & 1) /* 0x01 or 1 */

                                      /* "           CLEAR         "   "    Write value   " */
#define WRT_BIT(REG, BITNO, VAL) ( (REG) = ( ( (REG) & (~( 1 << (BITNO) ) ) ) | ( (VAL) << (BITNO) ) ) )
#endif
