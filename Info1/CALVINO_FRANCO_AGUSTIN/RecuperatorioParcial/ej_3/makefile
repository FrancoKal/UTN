# $@ Contiene el target
# $< Contiene las dependencias del target


CC		=	gcc
CFLAGS		=	-c -Wall
LDFLAGS	=	-Wall
OBJS		=	main3.o funciones3.o
EJERCICIO	=	ejercicio3

$(EJERCICIO): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@ -lm
%.o: %.c makefile
	$(CC) $(CFLAGS) $< -o $@
git:
	git add *.c *.h *.sh *makefile
	git commit -m "$(EJERCICIO)"
	git push
