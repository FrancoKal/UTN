gcc -c -Wall main.c -o main.o
gcc -c -Wall funciones.c -o funciones.o
gcc -Wall main.o funciones.o -o main
