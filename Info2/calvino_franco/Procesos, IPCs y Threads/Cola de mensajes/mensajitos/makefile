# $@ Contiene el target
# $< Contiene las dependencias del target


CC		=	gcc
LDFLAGS	=	-Wall
CFLAGS		=	-c -Wall
SOURCES	=	lector.c escritor.c
OBJS		=	lector.o escritor.o
EJERCICIO	=	mensajitos
COMMIT		=	MsgQueue

$(EJERCICIO): $(OBJS)
	$(CC) escritor.o -o escritor $(LDFLAGS)
	$(CC) lector.o -o lector $(LDFLAGS)
	
%.o: %.c makefile
	$(CC) $(CFLAGS) $< -o $@
git:
	git add *.c *.h *makefile
	git commit -m "$(COMMIT)"
	git push
