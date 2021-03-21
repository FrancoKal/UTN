CC=gcc
CFLAGS=-c -Wall -g
LDFLAGS= -Wall -g
OBJS=mk-main.o mk-funciones.o

ejec: $(OBJS)
	$(CC) -o ejec $(OBJS) $(LDFLAGS)
mk-main.o: mk-main.c
	$(CC) $(CFLAGS) -o mk-main.o mk-main.c 
mk-funciones.o:  mk-funciones.c
	$(CC) $(CFLAGS) -o mk-funciones.o mk-funciones.c
clean:
	rm -f *.o
	rm -f ejec

new: clean ejec
