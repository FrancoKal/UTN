rm mV4
gcc -c mainV4.c -o mainV4.o -Wall
gcc -c funcV4.c -o funcV4.o -Wall
gcc funcV4.o mainV4.o -o mV4 -Wall
./mV4 <cargaV3-4.dat

