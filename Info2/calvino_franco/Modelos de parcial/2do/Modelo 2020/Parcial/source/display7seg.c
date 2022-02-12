/*
 * display7seg.c
 *
 *  Created on: 22 nov. 2021
 *      Author: franco
 */

#include "display7seg.h"
#include "timer.h"
#include "adc.h"
#include "dr_gpio.h"
#include "teclado.h"

uint8_t Tabla_Conversion_display7seg[10] = {
		//Asumo que ya esta hecha
};

uint8_t bufferConversion[2];			//Para guardar los 2 digitos de la conversion
uint8_t bufferDisplay[CANT_DIGITOS];	//Para guardar los digitos correspondientes a cada display
extern datos_adc_t datosADC;

void MostrarEnDisplay(uint8_t tecla)
{
	switch (tecla)
	{
		case TECLA_T_MAX:
			Display((uint32_t) datosADC.TT, DISPLAY_TEMPERATURA);
			break;

		case TECLA_T_MIN:
			Display((uint32_t) datosADC.tt, DISPLAY_TEMPERATURA);
			break;

		case TECLA_H_MAX:
			Display((uint32_t) datosADC.HH, DISPLAY_HUMEDAD);
			break;

		case TECLA_H_MIN:
			Display((uint32_t) datosADC.hh, DISPLAY_HUMEDAD);
			break;
	}

	//Deshabilito el modo BURST del ADC
	DeshabilitarConversionADC();

	//Lanzo el timer para mostrar en el display por 2,5 segundos
	TimerStart(EVENTO_DISPLAY, 25, display_handler, DEC);
}

void Display(uint32_t valor, uint8_t display)
{
	int i;

	/*
	 * Descompongo el valor en sus unidades y guardo el numero en BCD
	 * correspondiente en bufferConversion. Los numeros a mostrar son de 2 digitos.
	 */
	for (i = 0; i < CANT_DIGITOS/2; i++)
	{
		bufferConversion[i] = Tabla_Conversion_display7seg[valor % 10];
		valor /= 10;
	}

	//Guardo las 2 conversiones en los 2 buffers correspondientes a los 2 displays a mostrar
	switch (display)
	{
		case DISPLAY_TEMPERATURA:
			bufferDisplay[1] = bufferConversion[1];
			bufferDisplay[0] = bufferConversion[0];
			break;

		case DISPLAY_HUMEDAD:
			bufferDisplay[3] = bufferConversion[1];
			bufferDisplay[2] = bufferConversion[0];
			break;

		default: break;	//No hago nada
	}
}

void BarridoDisplay(void)
{
	static uint8_t digito = 0;

	//Por las dudas, apago todos los digitos con un 0
	SetPIN(DISPLAY_TEMP_0, 0);	SetPIN(DISPLAY_TEMP_1, 0);
	SetPIN(DISPLAY_HUM_0, 0);	SetPIN(DISPLAY_HUM_1, 0);

	//Si (bufferDisplay[digito] >> n) & 1 es igual a 1, se enciende el segmento correspondiente.
	SetPIN(SEG_a, (bufferDisplay[digito] >> 0) & 1);
	SetPIN(SEG_b, (bufferDisplay[digito] >> 1) & 1);
	SetPIN(SEG_c, (bufferDisplay[digito] >> 2) & 1);
	SetPIN(SEG_d, (bufferDisplay[digito] >> 3) & 1);
	SetPIN(SEG_e, (bufferDisplay[digito] >> 4) & 1);
	SetPIN(SEG_f, (bufferDisplay[digito] >> 5) & 1);
	SetPIN(SEG_g, (bufferDisplay[digito] >> 6) & 1);

	//Enciendo el digito que corresponde en esta ronda
	switch (digito)
	{
		case DIGITO_TEMP_0:
			SetPIN(DISPLAY_TEMP_0, 1);
			break;

		case DIGITO_TEMP_1:
			SetPIN(DISPLAY_TEMP_1, 1);
			break;

		case DIGITO_HUM_0:
			SetPIN(DISPLAY_HUM_0, 1);
			break;

		case DIGITO_HUM_1:
			SetPIN(DISPLAY_HUM_1, 1);
			break;

		default: break;
	}

	digito++;
	digito %= CANT_DIGITOS;
}

void display_handler (void)
{
	//Habilito nuevamente el modo BURST del ADC
	HabilitarConversionADC();
}
