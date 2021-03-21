gcc -c mainV3.c -o mainV3.o -Wall
gcc -c funcV3.c -o funcV3.o -Wall
gcc funcV3.o mainV3.o -o mV3 -Wall
./mV3 <cargaV3-4.dat

