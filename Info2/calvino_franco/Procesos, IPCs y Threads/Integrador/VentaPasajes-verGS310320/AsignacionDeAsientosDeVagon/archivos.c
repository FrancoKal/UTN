#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include <stdio.h>

int LecturaVagon(char **Vagon )
{
    int m = 0 , n = 0;
    FILE* fp;
    char aux[30];
    *Vagon[ 0 ] = '\x0';

    fp = fopen ( "Vagon.txt" , "r");

    if ( fp == NULL )
        return 1 ;

    /*Lee el archivo*/
    /*Si llega al final fgets() devuelve NULL y sale del  ciclo while()*/
    /*Si encuentra \r devuelve los bytes que leyó*/
    /*En n cuenta los caracteres leído y le agrega null al final de cada linea*/
    /* Concatena el array de caracteres aux con lashared memory*/
    /* Con m cuenta cuantas lineas leyo*/
    while ( fgets ( aux , 25 , fp ) )
    {
        n = (int) strlen ( aux );
        aux[ n - 1 ] = '\x0';
        strcat(*Vagon , aux );
        m++;
    }

    n--;

    fclose( fp );

    return 0;
}
