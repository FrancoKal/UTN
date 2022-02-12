#include "teclado.h"

uint8_t teclaDetectada, tecla;

//Analoga a TecladoHW()
uint8_t BarridoTeclado(void)
{
    //Apago todas las columnas por las dudas
    SetPIN(COL1, 1);    SetPIN(COL2, 1);    SetPIN(COL3, 1);

    //Pruebo la columna 1 y hago un delay
    SetPIN(COL1, 0);    SetPIN(COL2, 1);    SetPIN(COL3, 1);
    DELAY

    if (GetPIN(FILA1))  return TECLA_A;
    if (GetPIN(FILA2))  return TECLA_D;

    //Pruebo la columna 2 y hago un delay
    SetPIN(COL1, 1);    SetPIN(COL2, 0);    SetPIN(COL3, 1);
    DELAY

    if (GetPIN(FILA1))  return TECLA_B;
    if (GetPIN(FILA2))  return TECLA_E;

    //Pruebo la columna 3 y hago un delay
    SetPIN(COL1, 1);    SetPIN(COL2, 1);    SetPIN(COL3, 0);
    DELAY

    if (GetPIN(FILA1))  return TECLA_C;
    if (GetPIN(FILA2))  return TECLA_RESET;

    return NO_KEY;
}

void DriverTeclado(void)
{
    teclaDetectada = BarridoTeclado();
    MDE_Teclado(teclaDetectada);
}

//Primitiva
uint8_t Teclado(void)
{
    uint8_t bufferTecla = NO_KEY;

    bufferTecla = tecla;
    tecla = NO_KEY;

    return bufferTecla;
}

//Analoga a TecladoSW()
void MDE_Teclado(uint8_t codigoTecla)
{
    static uint8_t estado = REPOSO, codigoAnterior = NO_KEY, rebotes;

    if (codigoTecla == NO_KEY)
        estado = REPOSO;

    switch (estado)
    {
        case REPOSO:

            //Se detecto una tecla, debo validarla
            if (codigoTecla != codigoAnterior)
            {
                rebotes = 0;
                codigoAnterior = codigoTecla;
                estado = DETECTANDO;
            }
            else rebotes = 0;

            break;

        case DETECTANDO:

            if (codigoTecla != codigoAnterior)
                rebotes++;

            if (rebotes == MAX_REBOTES)
            {
                tecla = codigoTecla;
                codigoAnterior = NO_KEY;
                rebotes = 0;
                estado = REPOSO;
            }

            break;

        default:
            estado = REPOSO;
            rebotes = 0;
    }

}