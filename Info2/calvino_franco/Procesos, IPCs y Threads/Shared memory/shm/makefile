# $@ Contiene el target
# $< Contiene las dependencias del target


CC		=	gcc
LDFLAGS	=	-Wall
CFLAGS		=	-c -Wall
SOURCES	=	shm.c
OBJS		=	shm.o
EJERCICIO	=	shm
COMMIT		=	SharedMemory

$(EJERCICIO): $(OBJS)
	$(CC) $< -o $@
	
%.o: %.c makefile
	$(CC) $(CFLAGS) $< -o $@
git:
	git add *.c *.h *makefile
	git commit -m "$(COMMIT)"
	git push
