#include "../MyIncludes/funcionesAlarma.h"

extern uint8_t e_AlarmaOFF, e_AlternarAlarma;

void AlarmaOFF_handler (void)
{
    e_AlarmaOFF = TRUE;
}

void AlternarAlamra_handler (void)
{
    e_AlternarAlarma = TRUE;
}

void t_AlarmaOFF(void)
{
    e_AlarmaOFF = FALSE;
    TimerStart(EVENTO_ALARMA_OFF, 5, AlarmaOFF_handler, SEG);
}

void t_AlternarAlarma(void)
{
    e_AlternarAlarma = FALSE;
    TimerStart(EVENTO_ALTERNAR_ALARMA, 1, AlternarAlarma_handler, SEG);
}

void t_AlarmaOFF_stop(void)
{
    TimerStop(EVENTO_ALARMA_OFF);
    e_AlarmaOFF = FALSE;
}

void t_AlternarAlarma_stop(void)
{
    TimerStop(EVENTO_ALTERNAR_ALARMA);
    e_AlternarAlarma = FALSE;
}

void ResetAlarma(void)
{

}
