#ifndef _VARIANT_NICENANO_
#define _VARIANT_NICENANO_

/** Led state needed **/
#define LED_STATE_ON 1
#define LED_STATE_OFF 0

/** Master clock frequency */
#define VARIANT_MCK       (64000000ul)
  
#define USE_LFXO      // Board uses 32khz crystal for LF (on the nicenano/supermini)
//#define USE_LFRC    // Board uses RC for LF

#include "WVariant.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#define PINS_COUNT 48
#define PIN_SERIAL1_TX  0   // P0.00 (GPIO 0)
#define PIN_SERIAL1_RX  1   // P0.01 (GPIO 1)
#define PIN_002  2   // P0.02 (GPIO 2)
#define PIN_003  3   // P0.03 (GPIO 3)
#define PIN_004  4   // P0.04 (GPIO 4)
#define PIN_005  5   // P0.05 (GPIO 5)
#define PIN_006  6   // P0.06 (GPIO 6)
#define PIN_007  7   // P0.07 (GPIO 7)
#define PIN_008  8   // P0.08 (GPIO 8)
#define PIN_009  9   // P0.09 (GPIO 9)
#define PIN_010  10  // P0.10 (GPIO 10)
#define PIN_011  11  // P0.11 (GPIO 11)
#define PIN_012  12  // P0.12 (GPIO 12)
#define PIN_013  13  // P0.13 (GPIO 13)
#define PIN_014  14  // P0.14 (GPIO 14)
#define PIN_015  15  // P0.15 (GPIO 15)
#define PIN_016  16  // P0.16 (GPIO 16)
#define PIN_017  17  // P0.17 (GPIO 17)
#define PIN_018  18  // P0.18 (GPIO 18)
#define PIN_019  19  // P0.19 (GPIO 19)
#define PIN_020  20  // P0.20 (GPIO 20)
#define PIN_021  21  // P0.21 (GPIO 21)
#define PIN_022  22  // P0.22 (GPIO 22)
#define PIN_023  23  // P0.23 (GPIO 23)
#define PIN_024  24  // P0.24 (GPIO 24)
#define PIN_025  25  // P0.25 (GPIO 25)
#define PIN_026  26  // P0.26 (GPIO 26)
#define PIN_027  27  // P0.27 (GPIO 27)
#define PIN_028  28  // P0.28 (GPIO 28)
#define PIN_029  29  // P0.29 (GPIO 29)
#define PIN_030  30  // P0.30 (GPIO 30)
#define PIN_031  31  // P0.31 (GPIO 31)
#define PIN_100  32  // P1.00 (GPIO 100)
#define PIN_101  33  // P1.01 (GPIO 101)
#define PIN_102  34  // P1.02 (GPIO 102)
#define PIN_103  35  // P1.03 (GPIO 103)
#define PIN_104  36  // P1.04 (GPIO 104)
#define PIN_105  37  // P1.05 (GPIO 105)
#define PIN_106  38  // P1.06 (GPIO 106)
#define PIN_107  39  // P1.07 (GPIO 107)
#define PIN_108  40  // P1.08 (GPIO 108)
#define PIN_109  41  // P1.09 (GPIO 109)
#define PIN_110  42  // P1.10 (GPIO 110)
#define PIN_111  43  // P1.11 (GPIO 111)
#define PIN_112  44  // P1.12 (GPIO 112)
#define PIN_113  45  // P1.13 (GPIO 113)
#define PIN_114  46  // P1.14 (GPIO 114)
#define PIN_115  47  // P1.15 (GPIO 115)

#ifndef LED_BUILTIN
#define LED_BUILTIN PIN_015
#endif

#ifndef LED_BLUE
#define LED_BLUE PIN_114 //added so bluefruit compiles. not in use, 
#endif                  //if you do wanna use it, change the PIN_114 to whatever you want

// I2C Pins
/*
#define PIN_SDA   PIN_022  // add whichever pin you want, any pin works
#define PIN_SCL   PIN_023  // add whichever pin you want, any pin works
*/

// SPI Pins
/*
#define PIN_SPI_MISO  PIN_24
#define PIN_SPI_MOSI  PIN_25
#define PIN_SPI_SCK   PIN_26
#define PIN_SPI_CS    PIN_27
*/


#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#endif
