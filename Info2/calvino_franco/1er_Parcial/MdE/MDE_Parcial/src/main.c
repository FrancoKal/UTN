/*
===============================================================================
 Name        : MDE_Parcial.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

//#include <cr_section_macros.h>
#include "../MyIncludes/funcionesBiblioteca.h"
#include "../MyIncludes/MDE_Microondas.h"
#include "../MyIncludes/MDE_Alarma.h"
#include "../MyIncludes/MDE_Teclado.h"
#include "../MyIncludes/MDE_Termostato.h"

uint8_t alarma, microondas, termostato, potencia, tiempoIngresado;

int main(void)
{
	InicializarHW();

    while(1)
    {
        TimerEvent();
        MDE_Microondas();
        MDE_Alarma();
        MDE_Teclado();
        MDE_Termostato();
    }

    return 0;
}
