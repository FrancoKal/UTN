#include "../MyIncludes/MDE_Teclado.h"
#include "../MyIncludes/funcionesTeclado.h"

uint8_t dato = 0, digitos = 0;
extern uint8_t tiempoIngresado, microondas, potencia;

static int TECLADO_REPOSO (int);
static int TECLADO_RECIBIENDO (int);

static int (*TECLADO[]) (int) = {

    TECLADO_REPOSO,
    TECLADO_RECIBIENDO   
};

static int TECLADO_REPOSO (int status)
{
    switch (dato)
    {
        case CODIGO_TECLA_MINIMA:
            potencia = MINIMA;
            status = RECIBIENDO;
            break;

        case CODIGO_TECLA_MEDIA:
            potencia = MEDIA;
            status = RECIBIENDO;
            break;
        
        case CODIGO_TECLA_MAXIMA:
            potencia = MAXIMA;
            status = RECIBIENDO;
            break;

        case CODIGO_TECLA_ENCENDIDO:
            potencia = MAXIMA;
            tiempoIngresado = 30;
            microondas = ON;
            break;
    }

    return status;
}

static int TECLADO_RECIBIENDO (int status)
{
    if (dato >= 0 && dato <= 9)
    {
        digitos++;
    }

    if (dato == CODIGO_TECLA_CANCELAR)
    {
        tiempoIngresado = 0;
        microondas = OFF;
        status = REPOSO;
    }

    if (dato == CODIGO_TECLA_ENCENDIDO && tiempoIngresado >= 5 && tiempoIngresado <= 8000)
    {
        microondas = ON;
        status = REPOSO;
    }

    return status;
}

void MDE_Teclado (void)
{
    static uint8_t estado = REPOSO;

    if (estado < REPOSO || estado > RECIBIENDO)
        ResetTeclado();

    dato = TECLADO_Leer();

    if (dato != NO_KEY)
        estado = (*TECLADO[estado])(estado);
}
