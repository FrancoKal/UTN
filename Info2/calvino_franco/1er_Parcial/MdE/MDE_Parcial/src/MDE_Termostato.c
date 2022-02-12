#include "../MyIncludes/MDE_Termostato.h"
#include "../MyIncludes/funcionesTermostato.h"

uint8_t e_AlarmaTermostato;
extern uint8_t termostato, tiempoIngresado, alarma;

static int TERMOSTATO_REPOSO (int);
static int TERMOSTATO_ESPERANDO_ENCENDIDO (int);
static int TERMOSTATO_ENCENDIDO (int);

static int (*TERMOSTATO[]) (int) = {

    TERMOSTATO_REPOSO,
    TERMOSTATO_ESPERANDO_ENCENDIDO,
    TERMOSTATO_ENCENDIDO
};

static int TERMOSTATO_REPOSO (int status)
{
    if (termostato == ON)
    {
        if (tiempoIngresado >= 30)
        {
            t_AlarmaTermostato();
            status = ESPERANDO_ENCENDIDO;
        }
        else if (tiempoIngresado <= 30 && s_TemperaturOK() == FALSE)
        {
            m_TermostatoON();
            status = ENCENDIDO;
        }

    }

    return status;
}

static int TERMOSTATO_ESPERANDO_ENCENDIDO (int status)
{
    if (e_AlarmaTermostato)
    {
        alarma = ON;
        status = REPOSO;
    }
    else if (s_TemperaturaOK() == FALSE)
    {
        m_TermostatoON();
        status = ENCENDIDO;
    }
    else if (termostato == OFF)
    {
        m_TermostatoOFF();
        status = REPOSO;
    }

    return status;
}

static int TERMOSTATO_ENCENDIDO (int status)
{
    if (s_TemperaturOK() || termostato == OFF)
    {
        m_TermostatoOFF();
        status = REPOSO;
    }

    return status;
}

void MDE_Termostato (void)
{
    static uint8_t estado = REPOSO;

    if (estado < REPOSO || estado > ENCENDIDO)
        ResetTermostato();

    estado = (*TERMOSTATO[estado])(estado);
}