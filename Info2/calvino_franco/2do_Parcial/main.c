#include <stdint.h>
#include "defines.h"
#include "MaquinaExpendedora.h"
#include "teclado.h"
#include "rtc.h"

uint8_t ID = 0, credito = 0, tecladoActivo = 0, tecla = 0;

int main (void)
{
    InicializoRTC();
    InicializoUART2();

    while (1)
    {
        tecla = Teclado();

        switch (tecla)
        {
            case NO_KEY:
                break;

            case TECLA_RESET:
                //Reseteo
                break;

            default:
                despacharBebida(tecla);
                break;
        }

        MaquinaExpendedora();
    }
    return 0;
}