#include "../MyIncludes/funcionesBiblioteca.h"

void Inicializacion(void)
{
	//De la biblioteca
}

uint8_t Entradas(uint8_t nEntrada)
{
	//Codigo de la biblioteca
	return nEntrada;
}

void Relays(uint8_t nRelay, uint8_t status)
{
	//Codigo de la biblioteca
}

void TimerStart(uint8_t event, timer_t time, void (*handler)(void), uint8_t base)
{
	//De la biblioteca
}

void TimerStop (uint8_t event)
{
	//De la biblioteca
}

void TimerEvent (void)
{
	//De la biblioteca
}
void LedsRGB(uint8_t led, uint8_t status)
{
	//De la biblioteca
}

void Buzzer(uint8_t estado)
{
	//De la biblioteca
}

int16_t UART_PopRX(uint8_t uart)
{
	int16_t resultado = 0;

	//De la biblioteca

	return resultado;
}

int16_t Transmitir (const void *datos, uint8_t cantidad)
{
	int16_t resultado = 0;

	//De la biblioteca

	return resultado;
}

int16_t Potenciometro (void)
{
	int16_t resultado;
	
	//De la biblioteca

	return resultado;
}

int16_t Temperatura (void)
{
	int16_t resultado;

	//De la biblioteca

	return resultado;
}

int16_t ADC_Externa (void)
{
	int16_t resultado;
	
	//De la biblioteca

	return resultado;
}
