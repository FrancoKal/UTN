/*
 * teclado.h
 *
 *  Created on: 22 nov. 2021
 *      Author: franco
 */

#ifndef TECLADO_H_
#define TECLADO_H_

#include "LPC845.h"

#define TECLA_T_MAX	0
#define TECLA_T_MIN	1
#define TECLA_H_MAX	2
#define TECLA_H_MIN	3
#define TECLA_RESET	4
#define NO_KEY		0xFF

#define DELAY		0;

void TecladoSW(uint8_t);			//MDE del teclado
uint8_t BarridoTeclado(void);	//Detecta la tecla oprimida directamente del hardware
void DriverTeclado(void);		//Driver que va en el systick handler (debe estar siempre corriendo)
uint8_t Teclado(void);			//Funcion para detectar tecla a nivel de la aplicacion

#endif /* TECLADO_H_ */