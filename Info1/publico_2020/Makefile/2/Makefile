CC=gcc
ejec: mk-main.o mk-funciones.o
	$(CC) -o ejec mk-main.o mk-funciones.o -Wall
mk-main.o: mk-main.c
	$(CC) -c -o mk-main.o mk-main.c -Wall
mk-funciones.o:  mk-funciones.c
	$(CC) -c mk-funciones.c -o mk-funciones.o -Wall
clean:
	rm -f *.o
	rm -f ejec

new: clean ejec
