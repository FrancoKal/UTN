#include "../MyIncludes/MDE_Alarma.h"
#include "../MyIncludes/funcionesAlarma.h"

uint8_t e_AlarmaOFF, e_AlternarAlarma;
extern uint8_t alarma, microondas;

static int ALARMA_REPOSO (int);
static int ALARMA_ENCENDIDA (int);
static int ALARMA_APAGADA (int);

static int (*ALARMA[]) (int) = {

    ALARMA_REPOSO,
    ALARMA_ENCENDIDA,
    ALARMA_APAGADA
};

static int ALARMA_REPOSO (int status)
{
    if (alarma == ON)
    {
        t_AlarmaOFF();
        t_AlternarAlarma();
        m_AlarmaON();
        status = ENCENDIDA;
    }

    return status;
}

static int ALARMA_ENCENDIDA (int status)
{
    if (e_AlarmaOFF)
    {
        m_AlarmaOFF();
        t_AlternarAlarma_stop();
        alarma = microondas = OFF;
        status = REPOSO;
    }
    else if (e_AlternarAlarma)
    {
        m_AlarmaOFF();
        t_AlternarAlarma();
        status = APAGADA;
    }

    return status;
}

static int ALARMA_APAGADA (int status)
{
    if (e_AlarmaOFF)
    {
        t_AlternarAlarma_stop();
        alarma = microondas = OFF;
        status = REPOSO;
    }
    else if (e_AlternarAlarma)
    {
        m_AlarmaON();
        t_AlternarAlarma();
        status = ENCENDIDA;
    }

    return status;
}

void MDE_Alarma (void)
{
    static uint8_t estado = REPOSO;

    if (estado < REPOSO || estado > APAGADA)
        ResetAlarma();

    estado = (*ALARMA[estado])(estado);
}