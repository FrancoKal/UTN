gcc -c main.c -o main.o -Wall
gcc -c funciones.c -o funciones.o -Wall
gcc main.o funciones.o -o mostrar -Wall
