/*
 * display7seg.h
 *
 *  Created on: 22 nov. 2021
 *      Author: franco
 */

#ifndef DISPLAY7SEG_H_
#define DISPLAY7SEG_H_

#include "LPC845.h"

//Pines para habilitar un determinado display
#define DIGITO_TEMP_0		0
#define	DIGITO_TEMP_1		1
#define DIGITO_HUM_0		2
#define	DIGITO_HUM_1		3

#define DISPLAY_TEMP_0		0, 5
#define DISPLAY_TEMP_1		0, 6
#define DISPLAY_HUM_0		0, 7
#define DISPLAY_HUM_1		0, 8

#define SEG_a				0, 9
#define SEG_b				0, 10
#define SEG_c				0, 11
#define SEG_d				0, 12
#define SEG_e				0, 13
#define SEG_f				0, 14
#define SEG_g				0, 15

#define DISPLAY_TEMPERATURA	0
#define DISPLAY_HUMEDAD		1

#define CANT_DIGITOS		4

#define EVENTO_DISPLAY		1

void MostrarEnDisplay(uint8_t tecla);
void Display(uint32_t valor, uint8_t display);
void BarridoDisplay(void);
void display_handler(void);

#endif /* DISPLAY7SEG_H_ */
