/*
 * PuertoSerie.h
 *
 *  Created on: 20 nov. 2021
 *      Author: franco
 */

#ifndef PUERTOSERIE_H_
#define PUERTOSERIE_H_

#include "LPC845.h"

#define TAM_TRAMA		12
#define RX_READY		(1 << 0)
#define TX_READY		(1 << 2)
#define FALSE			0
#define TRUE			1

void USART0_IRQHandler(void);
uint8_t	UART0_popTx(void);
void UART0_pushTx(uint8_t dato);
uint8_t UART0_popRx(void);
void UART0_pushRx(uint8_t dato);

#endif /* PUERTOSERIE_H_ */
