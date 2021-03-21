# $@ Contiene el target
# $< Contiene las dependencias del target


CC		=	gcc
CFLAGS		=	-c -Wall
LDFLAGS	=	-Wall
OBJS		=	main1.o funciones1.o
EJERCICIO	=	ejercicio1

$(EJERCICIO): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@
%.o: %.c makefile
	$(CC) $(CFLAGS) $< -o $@
git:
	git add *.c *.h *.sh *makefile
	git commit -m "$(EJERCICIO)"
	git push
