/*
 * MDE_Serie.c
 *
 *  Created on: 20 nov. 2021
 *      Author: franco
 */
#include "MDE_ComunicacionSerie.h"
#include "PuertoSerie.h"
#include "adc.h"

#define Recibir() UART0_popRx()

extern uint8_t datoRecibido;
uint8_t datoAnterior;
extern datos_ascii_adc_t datosASCII_ADC;

static int MDE_COMUNICACIONSERIE_REPOSO(int);
static int MDE_COMUNICACIONSERIE_ESPERO_LETRA (int);
static int MDE_COMUNICACIONSERIE_RESET (int);
static int MDE_COMUNICACIONSERIE_FINALIZACION (int);

static int (*MDE_COMUNICACIONSERIE[]) (int) = {

		MDE_COMUNICACIONSERIE_REPOSO,
		MDE_COMUNICACIONSERIE_ESPERO_LETRA,
		MDE_COMUNICACIONSERIE_RESET,
		MDE_COMUNICACIONSERIE_FINALIZACION
};

static int MDE_COMUNICACIONSERIE_REPOSO (int status)
{
	if (datoRecibido == '$')
		status = ESPERO_LETRA;

	return status;
}

static int MDE_COMUNICACIONSERIE_ESPERO_LETRA (int status)
{
	switch (datoRecibido)
	{
		case 'D':
			datoAnterior = 'D';
			status = FINALIZACION;
			break;

		case 'R':
			status = RESET;
			break;

		default:
			status = REPOSO;
	}


	return status;
}

static int MDE_COMUNICACIONSERIE_RESET (int status)
{
	if (datoRecibido == 'H' || datoRecibido == 'T')
	{
		datoAnterior = datoRecibido;
		status = FINALIZACION;
	}
	else status = REPOSO;

	return status;
}

static int MDE_COMUNICACIONSERIE_FINALIZACION (int status)
{
	if (datoRecibido == '#')
	{
		switch (datoAnterior)
		{
			case 'H':
				ResetHumedad();
				UART0_pushTx('$');
				UART0_pushTx('H');
				UART0_pushTx('0');
				UART0_pushTx('0');
				UART0_pushTx('#');
				break;

			case 'T':
				ResetTemperatura();
				UART0_pusTx('$');
				UART0_pusTx('T');
				UART0_pusTx('0');
				UART0_pusTx('0');
				UART0_pusTx('#');
				break;

			case 'D':
				UART0_pusTx('$');
				UART0_pusTx('D');
				UART0_pusTx(datosASCII_ADC.ta[0]);
				UART0_pusTx(datosASCII_ADC.ta[1]);
				UART0_pusTx(datosASCII_ADC.ha[0]);
				UART0_pusTx(datosASCII_ADC.ha[1]);
				UART0_pusTx(datosASCII_ADC.TT[0]);
				UART0_pusTx(datosASCII_ADC.TT[1]);
				UART0_pusTx(datosASCII_ADC.HH[0]);
				UART0_pusTx(datosASCII_ADC.HH[1]);
				UART0_pusTx(datosASCII_ADC.tt[0]);
				UART0_pusTx(datosASCII_ADC.tt[1]);
				UART0_pusTx(datosASCII_ADC.hh[0]);
				UART0_pusTx(datosASCII_ADC.hh[1]);
				UART0_pusTx('#');
				break;
		}
	}

	return REPOSO;
}

void MDE_ComunicacionSerie (void)
{
	static uint8_t estado = REPOSO;

	if (datoRecibido != -1) //Debo verificar que no haya error al recibir los datos
	{
		estado = (*MDE_COMUNICACIONSERIE[estado])(estado);

		if (estado < REPOSO || estado > FINALIZACION)
				ResetComunicacionSerie();
	}
}
