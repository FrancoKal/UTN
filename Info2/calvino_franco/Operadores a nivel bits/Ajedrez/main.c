#include <stdio.h>

#define LIMPIO_DyE(x)  (x &= 0b11100111) //x &= 0xe7

void printbits(unsigned char*);
void DeterminarPieza (unsigned char filas, int posicion);

/*  El tablero de ajedrez se representa con 8 filas, cada una con 8 columnas, dando en total 64 casilleros.
    Aquel casillero con una pieza se marca con un 1, y en donde no hay nada, con un 0. Entonces el tablero inicial de ajedrez queda como:

    1   1   1   1   1   1   1   1
    1   1   1   1   1   1   1   1
    0   0   0   0   0   0   0   0
    0   0   0   0   0   0   0   0
    0   0   0   0   0   0   0   0
    0   0   0   0   0   0   0   0
    1   1   1   1   1   1   1   1
    1   1   1   1   1   1   1   1

    Por cada fila tengo 2^8 = 256 combinaciones de piezas, por lo que necesito un unsigned char para representar cada fila. Ej:
    Como la 1era fila esta completa con piezas, su representacion seria 1111 1111 (binario) = 255 (decimal) = 0xff (hexadecimal)
*/

int main(void)
{
    unsigned char filas[8] = {0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff};

    /*  Deseo lograr el siguiente tablero:

        0   0   1   1   1   1   1   1
        1   0   1   1   1   1   1   1
        0   0   1   0   0   0   0   0
        0   0   0   1   0   0   0   0
        0   0   0   0   0   0   0   0
        0   0   0   0   0   0   0   0
        1   1   1   0   1   1   1   1
        1   1   1   1   0   1   0   1
    */

    // 1) Usando cualquier operador
    /*filas[0] >>= 2;
    filas[1] ^= 0b01000000; //0x40
    filas[2] |= 0b00100000; //0x20
    filas[3] |= 0b00010000; //0x10
    filas[6] ^= 0b00010000; //0x10
    filas[7] &= 0b11110101;*/ //0xf5

    /* 2) Modificar las columnas D y E para que quedan asi, sin importar sus valores iniciales

        A   B   C   D   E   F   G   H
        0   0   0   0   0   1   1   0
        1   0   1   1   0   1   1   1
        0   1   0   0   0   0   0   0
        0   0   0   0   1   0   0   0
        0   0   0   0   0   0   1   0
        0   0   1   0   0   0   0   0
        1   1   1   0   1   0   1   1
        0   0   0   1   1   1   0   1

        Usando el operador AND (&), mantengo con 1 las columnas que ya tienen 1 y mantengo con 0 las que ya tienen 0, pongo con 0 en donde deseo.
        Pero no puedo insertar 1 donde antes habia un 0
        Ej:

        Para la fila 1, deseo poner un 0 en las columnas E y D

        fila1   =   0   0   0   0   0   1   1   0
        mascara =   1   1   1   0   0   1   1   1
        ------------------------------------------
                =   0   0   0   0   0   1   1   0

        Para agregar 0 donde antes habia un 1, uso el operador OR (|) o el XOR(^)

        
    */

    LIMPIO_DyE(filas[0]);
    LIMPIO_DyE(filas[1]); filas[1] |= 0b00010000; //0x10
    LIMPIO_DyE(filas[2]);
    LIMPIO_DyE(filas[3]); filas[3] |= 0b00001000; //0x08
    LIMPIO_DyE(filas[4]);
    LIMPIO_DyE(filas[5]);
    LIMPIO_DyE(filas[6]); filas[6] |= 0b00001000; //0x08
    LIMPIO_DyE(filas[7]); filas[7] |= 0b00011000; //0x18

    // 3) Usando solo el XOR (^)
    /*filas[0] ^= 0b11000000; //0xc0
    filas[1] ^= 0b01000000; //0x40
    filas[2] ^= 0b00100000; //0x20
    filas[3] ^= 0b00010000; //0x10
    filas[6] ^= 0b00010000; //0x10
    filas[7] ^= 0b00001010;*/ //0x0a

    /////Print Test/////
    printbits(filas);
    DeterminarPieza(filas[0], 0);
    DeterminarPieza(filas[0], 1);
    DeterminarPieza(filas[0], 2);
    DeterminarPieza(filas[1], 2);
    DeterminarPieza(filas[2], 7);

    return 0;
}


void printbits(unsigned char *x)
{
    int i, j;

    //for(j = 7; j >= 0; j--)   De esta manera se imprime el tablero al reves
    for (j = 0; j <= 7; j++)
    {
        for(i = sizeof(char) << 3; i != 0; i--)
            putchar('0' + ((x[j] >> (i-1)) & 1));

        printf("\n");   
    }
}

void DeterminarPieza (unsigned char filas, int posicion)
{
    /*unsigned char mascara = 0b00000001 << (8 - posicion);

      Ej: supongamos que recibo la fila:  0   1   1   0   0   1   0   0

        Deseo comparar si en la posicion 2 (leyendo de izquierda a derecha, y empezando del 0) hay una pieza (en este caso hay un 1 en la posicion 2, por lo que si hay).
        Desplazo entonces 0b00000001 (8-2) = 6 posiciones ---> 0b00000001 << 6 = 0b01000000

        fila        =   0   1   1   0   0   1   0   0
        & mascara   =   0   1   0   0   0   0   0   0
        ----------------------------------------------
                    =   0   1   0   0   0   0   0   0 = mascara

        Si (fila & mascara) = mascara, es porque en la posicion buscada habia un 1, osea que hay una pieza.
        Caso contrario, obtengo 0b00000000 = 0, osea que no hay pieza
    

    if ((filas & mascara) == mascara)
        printf("Hay pieza\n");
    else printf("No hay pieza\n");

    */

    //Otra forma
    
    if (((filas >> (7 - posicion)) & 0b000000001 /*0x01*/) == 0b00000001 /*0x01*/)
        printf("Hay pieza\n");
    else printf("No hay pieza\n");
}
