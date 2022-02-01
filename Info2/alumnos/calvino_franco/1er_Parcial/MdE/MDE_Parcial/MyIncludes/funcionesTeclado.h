#ifndef FUNCIONES_TECLADO_H
#define FUNCIONES_TECLADO_H

#include "funcionesBiblioteca.h"

enum potencias {MINIMA = 1, MEDIA = 2, MAXIMA = 3};

#define NO_KEY 0xFF
#define CODIGO_TECLA_MINIMA 10
#define CODIGO_TECLA_MEDIA 11
#define CODIGO_TECLA_MAXIMA 12
#define CODIGO_TECLA_CANCELAR 13
#define CODIGO_TECLA_ENCENDIDO 14

uint8_t TECLADO_Leer (void);

#endif