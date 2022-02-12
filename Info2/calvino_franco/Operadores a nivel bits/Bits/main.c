#include <stdio.h>

#define LIMITE1 65536

typedef struct
{
    unsigned char b0:1;
    unsigned char b1:1;
    unsigned char b2:1;
    unsigned char b3:1;
    unsigned char b4:1;
    unsigned char b5:1;
    unsigned char b6:1;
    unsigned char b7:1;
} byte_t;

typedef union
{
    unsigned int x;
    byte_t bits;
} MyUnion;


int main (void)
{
    MyUnion u;
    unsigned int prueba = LIMITE1-1, i;
    unsigned char *c = (unsigned char*) &prueba;

    for (i = 0; i < sizeof(int); i++)
        printf("c[%i] = %i\n", i, *(c+i));

    printf("&u.x = %p\n", &u.x);
    printf("&u.bits = %p\n", &u.bits);

    u.x = 2938493;
    printf("b0 = %i\n", u.bits.b0);
    printf("b1 = %i\n", u.bits.b1);
    printf("b2 = %i\n", u.bits.b2);
    printf("b3 = %i\n", u.bits.b3);
    printf("b4 = %i\n", u.bits.b4);
    printf("b5 = %i\n", u.bits.b5);
    printf("b6 = %i\n", u.bits.b6);
    printf("b7 = %i\n", u.bits.b7);

    return 0;
}