#include "funcionesMaquina.h"

void t_procesoOK(void)
{
    TimerStart(EVENTO_TITILAR_LED, 50, titilar_LV_handler, DEC);
    TimerStart(EVENTO_LED_ENCENDIDO, 10, bebida_despachada_handler, SEG);
}

void titilar_LV_handler (void)
{
    NotPIN(LV);

    //Vuelvo a disparar el handler para que titile constantemente
    t_procesoOK();
}

void bebida_despachada_handler(void)
{
    TimerStop(EVENTO_TITILAR_LED);
    m_LV_ON();
    m_Exp_Tjta_ON();
}