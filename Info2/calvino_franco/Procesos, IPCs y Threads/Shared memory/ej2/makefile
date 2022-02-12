# $@ Contiene el target
# $< Contiene las dependencias del target


CC		=	gcc
LDFLAGS	=	-Wall
CFLAGS		=	-c -Wall
SOURCES	=	shm_cliente.c shm_productor.c
OBJS		=	shm_cliente.o shm_productor.o
EJERCICIO	=	shm
COMMIT		=	MsgQueue

$(EJERCICIO): $(OBJS)
	$(CC) shm_cliente.o -o shm_cliente $(LDFLAGS)
	$(CC) shm_productor.o -o shm_productor $(LDFLAGS)
	
%.o: %.c makefile
	$(CC) $(CFLAGS) $< -o $@
git:
	git add *.c *.h *makefile
	git commit -m "$(COMMIT)"
	git push
