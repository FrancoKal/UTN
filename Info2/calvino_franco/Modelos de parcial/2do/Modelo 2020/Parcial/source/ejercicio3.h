/*
 * ejercicio3.h
 *
 *  Created on: 20 nov. 2021
 *      Author: franco
 */

#ifndef EJERCICIO3_H_
#define EJERCICIO3_H_

#include <stdint.h>

#define     __RW    volatile             /*!< Defines 'read / write' permissions */

typedef struct
{
	__RW uint32_t IR;
	__RW uint32_t TCR;
	__RW uint32_t TC;
	__RW uint32_t PR;
	__RW uint32_t PC;
} PWM_Type;

#define PWM_BASE	0x40018000
#define PWM			((PWM_Type*) PWM_BASE)

#define IR			PWM->IR
#define TCR			PWM->TCR

#endif /* EJERCICIO3_H_ */
