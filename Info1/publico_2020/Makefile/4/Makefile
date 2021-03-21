# Comentarios comienzan con #
# Introducimos macros.
#    < Contiene la dependencia del target
#    @ Contiene el target

CC=gcc
CFLAGS=-c -g -Wall
LDFLAGS= -Wall -g
OBJS=mk-main.o mk-funciones.o

ejec: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)
mk-main.o: mk-main.c
	$(CC) $(CFLAGS) $< -o $@ 
mk-funciones.o:  mk-funciones.c
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -f *.o
	rm -f ejec

new: clean ejec
