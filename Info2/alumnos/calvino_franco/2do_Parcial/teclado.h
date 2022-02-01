#include <stdint.h>
#include "defines.h"

enum estadoTeclado {REPOSO = 0, DETECTANDO = 1};

#define FILA1   0, 3
#define FILA2   0, 4

#define COL1    0, 5
#define COL2    0, 6
#define COL3    0, 7

#define DELAY   (0==0; 0==0; 0==0; 0==0; 0==0;)

#define MAX_REBOTES     10

uint8_t BarridoTeclado(void);
void DriverTeclado(void);
uint8_t Teclado(void);
void MDE_Teclado(uint8_t);