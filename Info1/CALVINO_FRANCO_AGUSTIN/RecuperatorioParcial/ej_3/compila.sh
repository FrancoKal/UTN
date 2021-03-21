gcc -c main3.c -o main3.o -Wall
gcc -c funciones3.c -o funciones3.o -Wall
gcc main3.o funciones3.o -o ejercicio3 -lm -Wall
./ejercicio3
