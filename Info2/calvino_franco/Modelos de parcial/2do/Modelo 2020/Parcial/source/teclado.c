/*
 * teclado.c
 *
 *  Created on: 22 nov. 2021
 *      Author: franco
 */

#include "teclado.h"
#include "dr_gpio.h"
#include "stick.h"

uint8_t teclaDetectada, bufkey;

void TecladoSW(uint8_t tecla)
{
	//Hecha por otro programador. Modifica la variable bufkey
}

uint8_t BarridoTeclado(void)
{
	/*
	 * Debo verificar fila por fila en cual columna detecto una tecla.
	 * Para comprobar si hay tecla en una fila, pongo en 0 esa fila.
	 * Al presionar una tecla, el pin de la columna correspondiente se pone en 0.
	 *
	 * Debo causar un delay a proposito para darle al micro tiempo para detectar una tecla
	 */

	//Verifico la fila 0 (2 veces para generar un delay)
	SetPIN(FIL0, 0);	SetPIN(FIL1, 1);	SetPIN(FIL2, 1);
	DELAY	DELAY	DELAY	DELAY	DELAY	DELAY	DELAY

	if (GetPIN(COL0) == 0)	return TECLA_T_MAX;
	if (GetPIN(COL1) == 0)	return TECLA_T_MIN;

	//Verifico la fila 1
	SetPIN(FIL0, 1);	SetPIN(FIL1, 0);	SetPIN(FIL2, 1);
	DELAY	DELAY	DELAY	DELAY	DELAY	DELAY	DELAY

	if (GetPIN(COL0) == 0)	return TECLA_H_MAX;
	if (GetPIN(COL1) == 0)	return TECLA_H_MIN;

	//Verifico la fila 2
	SetPIN(FIL0, 1);	SetPIN(FIL1, 1);	SetPIN(FIL2, 0);
	DELAY	DELAY	DELAY	DELAY	DELAY	DELAY	DELAY

	//En el teclado mostrado en la hoja, no hay tecla en la columna 0, fila 2.
	if (GetPIN(COL1) == 0)	return TECLA_RESET;

	SetPIN(FIL0, 1);	SetPIN(FIL1, 1);	SetPIN(FIL2, 1);

	return NO_KEY;
}

void DriverTeclado(void)
{
	teclaDetectada = BarridoTeclado();
	TecladoSW(teclaDetectada);

}

uint8_t Teclado(void)
{
	uint8_t tecla = bufkey;

	bufkey = NO_KEY;

	return tecla;
}

