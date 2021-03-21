gcc -c -o mk-main.o mk-main.c -g -Wall
gcc -c mk-funciones.c -o mk-funciones.o -g -Wall
gcc -o ejec mk-main.o mk-funciones.o -g -Wall
