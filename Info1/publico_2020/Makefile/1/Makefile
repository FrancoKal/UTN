ejec: mk-main.o mk-funciones.o
	gcc -o ejec mk-main.o mk-funciones.o -g -Wall
mk-main.o: mk-main.c
	gcc -c -o mk-main.o mk-main.c -g -Wall
mk-funciones.o:  mk-funciones.c
	gcc -c mk-funciones.c -o mk-funciones.o -g -Wall

clean:
	rm -f *.o
	rm -f ejec

new: clean ejec

