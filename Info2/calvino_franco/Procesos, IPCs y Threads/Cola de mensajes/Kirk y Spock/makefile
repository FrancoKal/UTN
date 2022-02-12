# $@ Contiene el target
# $< Contiene las dependencias del target


CC		=	gcc
LDFLAGS	=	-Wall
CFLAGS		=	-c -Wall
SOURCES	=	kirk.c kirk.c
OBJS		=	kirk.o spock.o
EJERCICIO	=	MsgQueue
COMMIT		=	MsgQueue

$(EJERCICIO): $(OBJS)
	$(CC) kirk.o -o kirk $(LDFLAGS)
	$(CC) spock.o -o spock $(LDFLAGS)
	
%.o: %.c makefile
	$(CC) $(CFLAGS) $< -o $@
git:
	git add *.c *.h *makefile
	git commit -m "$(COMMIT)"
	git push
