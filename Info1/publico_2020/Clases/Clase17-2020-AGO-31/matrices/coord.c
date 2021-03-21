#include <stdio.h>
#include <string.h>

//#pragma pack(1)
//gcc -Wall -c -fpack-struct coord.c -o coord.o
//gcc -Wall -c -fpack-struct=2 coord.c -o coord.o

typedef struct {
    char nombre[9];
    int x;
    int y;
} punto_st;
//} __attribute__ ((packed)) punto_st;


int main(void) {
//    punto_st dato = {"vertice",5,6};
//    punto_st dato = {.nombre = "vertice", .x=5,.y=6} ;
    // punto_st dato[2] = {[0].nombre = "vertice", [0].x=5,[0].y=6,
    //                     [1].nombre = "plano",   [1].x=5,[1].y=6} ;

    punto_st dato[2] = {{"vertice",5,6},
                        {"plano"  ,7,8}};

    // strcpy(dato.nombre,"Vertice");
    // dato.x = 5;
    // dato.y = 6;

    printf("Nombre = %-12s   |   dato.x = %i   |  dato.y = %i\n", dato[0].nombre, dato[0].x,dato[0].y );
    printf("Nombre = %-12s   |   dato.x = %i   |  dato.y = %i\n", dato[1].nombre, dato[1].x,dato[1].y );

    printf("sizeof(punto_st)  = %i\n", (int) sizeof(punto_st));

    return 0;

}



