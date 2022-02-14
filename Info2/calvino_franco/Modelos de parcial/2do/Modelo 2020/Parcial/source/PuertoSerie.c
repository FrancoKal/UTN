/*
 * PuertoSerie.c
 *
 *  Created on: 21 nov. 2021
 *      Author: franco
 */
#include "PuertoSerie.h"

uint8_t transmitiendo, datoRecibido;

uint8_t	UART0_popTx(void)
{
	//Hecha por otro programador
}

void UART0_pushTx(uint8_t dato)
{
	//Hecha por otro programador
}

uint8_t UART0_popRx(void)
{
	//Hecha por otro programador
}

void UART0_pushRx(uint8_t dato)
{
	//Hecha por otro programador
}

/*
 * El handler se llamara cada vez que haya una interrupcion al llegear un dato y
 * que ese listo para leer (RX_READY) o cada vez que el la UART0 este lista para
 * enviar un dato (TX_READY)
 */
void USART0_IRQHandler(void)
{
	uint8_t dato;
	uint32_t estado = USART0->STAT;

	//Caso recepcion
	if (estado & RX_READY)
	{
		//Recibo dato
		dato = USART0->RXDAT;

		//Mando el dato al buffer
		UART0_pushRx(dato);

		//Guardo el dato en DatoRecibido para que lo vea la MDE
		datoRecibido = dato;
	}

	//Caso transmision
	if (estado & TX_READY)
	{
		//Debo enviar los datos que estan en el buffer de transmision
		dato = UART0_popTx();

		//Si hay datos para enviar (dato != -1), entonces los escribo en el registro de transmision
		if (dato >= 0)
			USART0->TXDAT = dato;
		else
		{
			//Si no hay datos para enviar, finalizo la transmision
			transmitiendo = FALSE;

			/*
			 * Como no hay datos para mandar, no necesito que me interrumpa para la transmision.
			 * Deshabilito interrupcion para cuando el transmisor este listo para enviar.
			 */
			USART0->INTENCLR |= TX_READY;
		}
	}
}
