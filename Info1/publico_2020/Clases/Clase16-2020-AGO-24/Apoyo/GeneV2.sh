gcc -c mainV2.c -o mainV2.o -Wall
gcc -c funcV2.c -o funcV2.o -Wall
gcc funcV2.o mainV2.o -o mV2 -Wall
./mV2 <cargaV1-2.dat

