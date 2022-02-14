/*
 * adc.h
 *
 *  Created on: 21 nov. 2021
 *      Author: franco
 */

#ifndef ADC_H_
#define ADC_H_

#include "LPC845.h"

#define EVENTO_CONVERSION	0
#define NUMERO_A_ASCII(x)	((x) + '0')

#define ADC_ON		((1 << 27) | (1 << 31))
#define ADC_OFF		~ADC_ON

typedef struct
{
	uint8_t ta;	//Temperatura actual
	uint8_t ha;	//Humedad actual
	uint8_t TT;	//Temperatura maxima
	uint8_t HH;	//Humedad maxima
	uint8_t tt;	//Temperatura minima
	uint8_t hh;	//Humedad minima
} datos_adc_t;

//Datos en caracteres ASCII
typedef struct
{
	uint8_t ta[2];	//Temperatura actual
	uint8_t ha[2];	//Humedad actual
	uint8_t TT[2];	//Temperatura maxima
	uint8_t HH[2];	//Humedad maxima
	uint8_t tt[2];	//Temperatura minima
	uint8_t hh[2];	//Humedad minima
} datos_ascii_adc_t;

void HabilitarConversionADC(void);
void DeshabilitarConversionADC(void);
void ConversionADC(void);
void ProcesarDatos(void);
void conversion_handler(void);
void ResetTemperatura(void);
void ResetHumedad(void);

#endif /* ADC_H_ */