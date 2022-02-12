#include "../MyIncludes/funcionesTermostato.h"

extern uint8_t e_AlarmaTermostato;

uint8_t Termostato (void)
{
    uint8_t resultado;

    return resultado;
}

uint8_t s_TemperaturOK(void)
{
    return Termostato() >= TEMPERATURA_OK ? TRUE : FALSE;
}

void AlarmaTermostato_handler(void)
{
    e_AlarmaTermostato = TRUE;
}

void t_AlarmaTermostato(void)
{
    e_AlarmaTermostato = FALSE;
    TimerStart(EVENTO_ALARMA_TERMOSTATO, 30, AlarmaTermostato_handler, SEG);
}

void t_AlarmaTermostato_stop(void)
{
    TimerStop(EVENTO_ALARMA_TERMOSTATO);
    e_AlarmaTermostato = FALSE;
}