/*
 * ejercicio3.c
 *
 *  Created on: 20 nov. 2021
 *      Author: franco
 */

/*
 * Para probar que todo funcione, hago un pequeño programa
 */

#include "ejercicio3.h"

#define MASCARA_INT		0
#define MASCARA_CTRL	1

void ejercicio3 (void);

void ejercicio3 (void)
{
		PWM->IR	= MASCARA_INT;
		PWM->TCR = MASCARA_CTRL;
		IR = MASCARA_INT;
		TCR = MASCARA_CTRL;

}


