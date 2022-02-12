/*
 * ejercicio2.c
 *
 *  Created on: 20 nov. 2021
 *      Author: franco
 */

/*
 * Realice todas las acciones necesarias para configurar como GPIO el P0.22 y  P0.24 como salida
 * y escriba un uno a sus pines asociados. Asimismo, configure P1.3 como entrada.

 * Nota: Absténgase de usar funciones utilitarias ya resueltas de acceso a HW.
 * Haga uso de las hojas de datos. Procure optimizar el uso de líneas de código.
 * COMENTE QUE HIZO EN CADA LINEA BREVEMENTE PERO QUE SE ENTIENDA.
 */
#include "LPC845.h"

void ejercicio2(void);

void ejercicio2 (void)
{
	/*
	 * Como para todo periferico, para utilizarlo hay que primero habilitar sus clocks.
	 * Habilito los clocks para el GPIO0 (para los pines 22 y 24), GPIO1(para el pin 3).
	 *
	 * GPIO0: bit 6
	 * GPIO1: bit 20
	 */
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 6) | (1 << 20);

	/*
	 * Para configurar un pin GPIO como entrada o salida, debo escribir en el
	 * registro DIR (o DIR0 Y DIR1) en el bit correspondiente.
	 *
	 * 0: entrada
	 * 1: salida
	 */

	//Pongo como salida los pines 22 y 24 del puerto 0
	GPIO->DIR[0] |= (1 << 22) | (1 << 24);

	//Pongo como entrada el pin 3 del puerto 1
	GPIO->DIR[1] &= ~(1 << 3);

	//Escribo un 1 en PIO0_22 y PIO0_24
	GPIO->SET[0] = (1 << 22) | (1 << 24);
	//GPIO->PIN[0] |= (1 << 22) | (1 << 24);

}


