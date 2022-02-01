#include "display.h"

uint8_t bufferDSP[6];

void Display (uint8_t valor)
{
    int i;
    //Como ya cuento con conversor BCD, no necesito tabla de conversion

    for (i = 0; i < CANT_DISPLAYS; i++)
    {
        bufferDSP[i] = valor % 10;
        valor /= 10;
    }
}

void BarridoDisplay(void)
{
    //Ya hecha
}