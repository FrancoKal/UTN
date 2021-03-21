gcc -c mainV1.c -o mainV1.o -Wall
gcc -c funcV1.c -o funcV1.o -Wall
gcc funcV1.o mainV1.o -o mV1 -Wall
./mV1 <cargaV1-2.dat

