/*
 * adc.c
 *
 *  Created on: 21 nov. 2021
 *      Author: franco
 */

#include "adc.h"
#include "timer.h"

void ADC0_SEQA_IRQHandler(void);

datos_adc_t datosADC;
datos_ascii_adc_t datosASCII_ADC;

uint8_t format (uint32_t dato)
{
	//Hecha por otro programador
}

void HabilitarConversionADC (void)
{
	/*
	 * Que use el modo BURST (hace conversiones automaticamente y ciclicamente) y habilito la secuencia
	 * NOTA: por obligacion del fabricante, esto se debe hacer en la misma linea de codigo
	 */
	ADC0->SEQ_CTRL[0] |= ADC_ON;
}

void DeshabilitarConversionADC (void)
{
	ADC0->SEQ_CTRL[0] &= ADC_OFF;
}

void ToggleADC (void)
{
	uint32_t ADC_On = ADC_ON;

	//Si el modo BURST y la secuencia estan habilitadas, se deshabilitan, y viceversa
	if (ADC0->SEQ_CTRL[0] & ADC_On)
		ADC0->SEQ_CTRL[0] &= ~ADC_On;
	else
		ADC0->SEQ_CTRL[0] |= ADC_On;
}

void ConversionADC ()
{
	ToggleADC();

	//Creo un timer para que vence en 1 segundo
	TimerStart(EVENTO_CONVERSION, 1, conversion_handler, SEG);
}

void conversion_handler(void)
{
	ConversionADC();
}

void ADC0_SEQA_IRQHandler(void)
{
	uint32_t datosValidos = (1 << 31);

	if (ADC0->DAT[1] & datosValidos)
	{
		/*
		 * El resultado esta entre los bits 4 y 15 del registro correspondiente, por lo que
		 * debo desplazar ese resultado 4 lugares.
		 * Hago un & con 0x0FFF para que los 1eros 12 bits de ADC->DAT[1] >> 4 permanezcan
		 * como estaban y que los bits posteriores queden en 0.
		 */
		datosADC.ta = (ADC0->DAT[1] >> 4) & 0x00000FFF;
	}

	if (ADC0->DAT[5] & datosValidos)
	{
		//Idem
		datosADC.ha = (ADC0->DAT[5] >> 4) & 0x00000FFF;
	}

	ProcesarDatos();
}

void ProcesarDatos(void)
{
	//Le paso a format la temperatura (entre 0º y 99º) en uint32_t y la devuelve en uint8_t
	uint8_t bufferTemp = format(datosADC.ta), bufferHum = format(datosADC.ha);
	static uint8_t tempMax = 0, humMax = 0, tempMin = 99, humMin = 99;

	//Ahora debo pasar bufferTemp y bufferHum a 2 caracteres ASCII cada uno

	if (bufferTemp < 100)
	{
		datosASCII_ADC.ta[0] = NUMERO_A_ASCII(bufferTemp % 10);
		datosASCII_ADC.ta[1] = NUMERO_A_ASCII((bufferTemp / 10) % 10);

		//Si la temperatura registrada es mayor a la maxima, actualizo la maxima
		if (bufferTemp > tempMax)
		{
			tempMax = bufferTemp;
			datosADC.TT = datosADC.ta;
			datosASCII_ADC.TT[0] = datosASCII_ADC.ta[0];
			datosASCII_ADC.TT[1] = datosASCII_ADC.ta[1];
		}

		//Si la temperatura registrada es menor a la minima, actualizo la minima
		if (bufferTemp < tempMin)
		{
			tempMin = bufferTemp;
			datosADC.tt = datosADC.ta;
			datosASCII_ADC.tt[0] = datosASCII_ADC.ta[0];
			datosASCII_ADC.tt[1] = datosASCII_ADC.ta[1];
		}
	}

	if (bufferHum < 100)
	{
		datosASCII_ADC.ha[0] = NUMERO_A_ASCII(bufferHum % 10);
		datosASCII_ADC.ha[1] = NUMERO_A_ASCII((bufferHum / 10) % 10);

		//Si la temperatura registrada es mayor a la maxima, actualizo la maxima
		if (bufferHum > humMax)
		{
			humMax = bufferHum;
			datosADC.HH = datosADC.ha;
			datosASCII_ADC.HH[0] = datosASCII_ADC.ha[0];
			datosASCII_ADC.HH[1] = datosASCII_ADC.ha[1];
		}

		//Si la temperatura registrada es menor a la minima, actualizo la minima
		if (bufferHum < humMin)
		{
			humMin = bufferHum;
			datosADC.hh = datosADC.ha;
			datosASCII_ADC.hh[0] = datosASCII_ADC.ha[0];
			datosASCII_ADC.hh[1] = datosASCII_ADC.ha[1];
		}
	}
}

void ResetTemperatura(void)
{
	datosADC.ta = 0;
	datosADC.TT = 0;
	datosADC.tt = 0;

	datosASCII_ADC.ta[0] = datosASCII_ADC.ta[1] = '0';
	datosASCII_ADC.TT[0] = datosASCII_ADC.TT[1] = '0';
	datosASCII_ADC.tt[0] = datosASCII_ADC.tt[1] = '0';
}

void ResetHumedad(void)
{
	datosADC.ha = 0;
	datosADC.HH = 0;
	datosADC.hh = 0;

	datosASCII_ADC.ha[0] = datosASCII_ADC.ha[1] = '0';
	datosASCII_ADC.HH[0] = datosASCII_ADC.HH[1] = '0';
	datosASCII_ADC.hh[0] = datosASCII_ADC.hh[1] = '0';
}
