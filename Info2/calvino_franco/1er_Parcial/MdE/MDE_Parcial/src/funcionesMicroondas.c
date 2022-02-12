#include "../MyIncludes/funcionesMicroondas.h"

extern uint8_t potencia, microondas, termostato;

#define m_MicroondasON() UART_Enviar(potencia)
#define m_MicroondasOFF() UART_Enviar(0)

void UART_Enviar (uint8_t estado)
{

}

void ResetMicroondas (void)
{
    microondas = OFF;
    termostato = OFF;
}