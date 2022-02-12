/*
 * stick.h
 *
 *  Created on: 6 ago. 2021
 *      Author: socco
 */

#ifndef STICK_H_
#define STICK_H_

#include "LPC845.h"
#include "dr_gpio.h"
#include "stick.h"

#define PIN_LED_VERDE	IOCON_INDEX_PIO1_0
#define PIN_LED_AZUL	IOCON_INDEX_PIO1_1
#define PIN_LED_ROJO	IOCON_INDEX_PIO1_2
#define PIN_TECLA_USR	IOCON_INDEX_PIO0_4
#define PIN_TECLA_ISP	IOCON_INDEX_PIO0_12

#define LED_VERDE	1,0
#define LED_AZUL	1,1
#define LED_ROJO	1,2
#define	TECLA_USR	0,4
#define	USWITCH		0,4
#define	REEDSW		0,26
#define	TECLA_ISP	0,12

#define FIL0		0,8
#define FIL1		0,31
#define FIL2		0,30
#define COL0		0,27
#define COL1		0,28

#define LCD_RS		0,15
#define LCD_E		0,14
#define LCD_D7		0,13
#define LCD_D6		0,11
#define LCD_D5		0,10
#define LCD_D4		0,9

#define LED_VERDE_NOT	NotPIN(LED_VERDE)
#define LED_VERDE_ON	SetPIN(LED_VERDE,0)
#define LED_VERDE_OFF	SetPIN(LED_VERDE,1)

#define LED_ROJO_NOT	NotPIN(LED_ROJO)
#define LED_ROJO_ON		SetPIN(LED_ROJO,0)
#define LED_ROJO_OFF	SetPIN(LED_ROJO,1)

#define USWITCH_ON		GetPIN(USWITCH)? 0:1
#define	REEDSW_ON		GetPIN(REEDSW)? 0:1

#define LCD_RS_ON	SetPIN(LCD_RS,1)
#define LCD_RS_OFF	SetPIN(LCD_RS,0)

#define LCD_E_ON	SetPIN(LCD_E,1)
#define LCD_E_OFF	SetPIN(LCD_E,0)

#define LCD_D7_ON	SetPIN(LCD_D7,1)
#define LCD_D7_OFF	SetPIN(LCD_D7,0)

#define LCD_D6_ON	SetPIN(LCD_D6,1)
#define LCD_D6_OFF	SetPIN(LCD_D6,0)

#define LCD_D5_ON	SetPIN(LCD_D5,1)
#define LCD_D5_OFF	SetPIN(LCD_D5,0)

#define LCD_D4_ON	SetPIN(LCD_D4,1)
#define LCD_D4_OFF	SetPIN(LCD_D4,0)

#endif /* STICK_H_ */
