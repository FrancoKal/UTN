# $@ Contiene el target
# $< Contiene las dependencias del target


CC		=	gcc
CFLAGS		=	-c -Wall
LDFLAGS	=	-Wall
OBJS		=	main2.o funciones2.o
EJERCICIO	=	ejercicio2

$(EJERCICIO): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@
%.o: %.c makefile
	$(CC) $(CFLAGS) $< -o $@
git:
	git add *.c *.h *.sh *makefile
	git commit -m "$(EJERCICIO)"
	git push
