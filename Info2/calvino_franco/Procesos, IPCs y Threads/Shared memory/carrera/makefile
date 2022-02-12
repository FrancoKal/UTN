# $@ Contiene el target
# $< Contiene las dependencias del target


CC		=	gcc
LDFLAGS	=	-Wall
CFLAGS		=	-c -Wall
SOURCES	=	carrera.c
OBJS		=	carrera.o
EJERCICIO	=	carrera
COMMIT		=	CarreraConSemaforos

$(EJERCICIO): $(OBJS)
	$(CC) $(LDFLAGS) $< -o $@
	
%.o: %.c makefile
	$(CC) $(CFLAGS) $< -o $@
git:
	git add *.c *.h *makefile
	git commit -m "$(COMMIT)"
	git push
