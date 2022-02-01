#ifndef FUNCIONES_TERMOSTATO_H
#define FUNCIONES_TERMOSTATO_H

#include "funcionesBiblioteca.h"

#define TEMPERATURA_OK 24
#define EVENTO_ALARMA_TERMOSTATO 2

uint8_t Termostato (void);
uint8_t s_TemperaturOK(void);

void t_AlarmaTermostato(void);
void t_AlarmaTermostato_stop(void);
void AlarmaTermostato_handler(void);

#endif