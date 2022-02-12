
#include <stdio.h>
#include "SharedMemory.h"
#include "pantallas.h"

void PrintVagon ( char* Vagon )
{
    int i , j , indice;
    char dato ;

    printf("\033[%d;25H\033[36m-------------------------\n",5);
    for ( i = 0 ; i < M   ; i ++ )
    {
            printf("\033[36m\033[%d;25H| ", i * 2 + 6 );

            for ( j = 0 ; j < N ; j ++ )
            {
                 indice = i * N + j ;
                 dato = Vagon [ indice ];
                 printf(" ");
                 PrintAsiento ( dato , i + 2 , j + 1 );
                 printf("\033[36m |");
            }

            printf("\n" );
            printf("\033[%d;25H\033[36m-------------------------",i*2+7);
            printf("\n" );
    }
}

void PrintAsiento ( char Asiento , int fila , int columna )
{
    int f = 4 + ( fila - 1 ) * 2 , c = 27 + ( columna - 1 ) * 4;

    switch ( Asiento )
    {
        case 'L':
            printf("\033[%d;%dH\033[32m%c", f , c , Asiento );
             break;
        case 'O':
            printf("\033[%d;%dH\033[31m%c", f , c , Asiento );
            break;
        case 'R':
            printf("\033[%d;%dH\033[33m%c", f , c , Asiento );
            break;
    }
    fflush(stdout);
}
