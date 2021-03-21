gcc -c funciones.c -o funciones.o -Wall
gcc -c hijos.c -o hijos.o -Wall
gcc hijos.o funciones.o -o hijos -Wall
gcc -c hijosv1.c -o hijosv1.o -Wall
gcc hijosv1.o funciones.o -o hijosv1 -Wall
gcc -c grandote.c -o grandote.o -Wall
gcc grandote.o -o grandote -Wall
gcc -c unico.c -o unico.o -Wall
gcc unico.o funciones.o -o unico -Wall
gcc -c funcionesp.c -o funcionesp.o -Wall
gcc -c pipes.c -o pipes.o -Wall
gcc pipes.o funcionesp.o -o pipes -Wall
gcc -c pipesv2.c -o pipesv2.o -Wall
gcc pipesv2.o funcionesp.o -o pipesv2 -Wall
gcc -c pipesv1.c -o pipesv1.o -Wall
gcc pipesv1.o funcionesp.o -o pipesv1 -Wall
gcc -c funcionesf.c -o funcionesf.o -Wall
gcc -c nfifop.c -o nfifop.o -Wall
gcc nfifop.o funcionesf.o -o nfifop -Wall
gcc -c nfifoc.c -o nfifoc.o -Wall
gcc nfifoc.o  -o nfifoc -Wall

