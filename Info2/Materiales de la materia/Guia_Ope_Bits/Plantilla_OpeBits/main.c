#include <stdio.h>
void printbits(char*);
int main()
{
//Definición de filas con posición inicial
    char filas[8] = {0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff};
//////Aca deberían realizar sus operaciones a nivel de bit////



/////Print Test/////
    printbits(filas);
    return 0;
}
void printbits(char *x)
{
    for(int j=7;j>=0;j--){
        for(int i=sizeof(char)<<3; i; i--)
        putchar('0'+((x[j]>>(i-1))&1));
        printf("\n");
    }
}
