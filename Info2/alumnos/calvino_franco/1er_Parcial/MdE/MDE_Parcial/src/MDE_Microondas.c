/*
 * MDE_Microondas.c
 *
 *  Created on: 24 jul. 2021
 *      Author: franco
 */

#include "../MyIncludes/MDE_Microondas.h"
#include "../MyIncludes/funcionesMicroondas.h"

extern uint8_t termostato, microondas, alarma;

static int MICROONDAS_REPOSO (int);
static int MICROONDAS_ENCENDIDO (int);

static int (*MICROONDAS[]) (int) = {

    MICROONDAS_REPOSO,
    MICROONDAS_ENCENDIDO
};

static int MICROONDAS_REPOSO (int status)
{
    if (microondas = ON)
    {
        m_MicroondasON();
        termostato = ON;
        status = ENCENDIDO;
    }

    return status;
}

static int MICROONDAS_ENCENDIDO (int status)
{
    if (microondas == OFF)
    {
        m_MicroondasOFF();
        termostato = OFF;
        status = REPOSO;
    }

    return status;
}

void MDE_Microondas (void)
{
    static uint8_t estado = REPOSO;

    if (estado < REPOSO || estado > ENCENDIDO)
        ResetMicroondas();

    estado = (*MICROONDAS[estado])(estado);
}
