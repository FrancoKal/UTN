#ifndef FUNCIONES_ALARMA_H
#define FUNCIONES_ALARMA_H

#include "funcionesBiblioteca.h"

#define m_AlarmaON() Buzzer(ON)
#define m_AlarmaOFF() Buzzer(OFF)
#define EVENTO_ALARMA_OFF 0
#define EVENTO_ALTERNAR_ALARMA 1

void t_AlarmaOFF(void);
void t_AlternarAlarma(void);
void t_AlarmaOFF_stop(void);
void t_AlternarAlarma_stop(void);

void AlarmaOFF_handler (void);
void AlternarAlarma_handler (void);

void ResetAlarma(void);

#endif