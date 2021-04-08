# $@ Contiene el target
# $< Contiene las dependencias del target


CC		=	gcc
CFLAGS		=	-c -Wall
LDFLAGS	=	-Wall
OBJS		=	main.o mystring.o
EJERCICIO	=	mystring
COMMIT		=	Strings

$(EJERCICIO): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@
%.o: %.c makefile
	$(CC) $(CFLAGS) $< -o $@
git:
	git add *.c *.h *makefile
	git commit -m "$(COMMIT)"
	git push
