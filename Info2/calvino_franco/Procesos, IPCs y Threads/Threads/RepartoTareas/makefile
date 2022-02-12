# $@ Contiene el target
# $< Contiene las dependencias del target


CC		=	gcc
LDFLAGS	=	-lm -lpthread -Wall
SOURCES	=	main.c funciones.c
EJERCICIO	=	tareas
COMMIT		=	RepartoTareas

$(EJERCICIO): makefile
	$(CC) -o $@ $(SOURCES) $(LDFLAGS) 
git:
	git add *.c *.h *makefile
	git commit -m "$(COMMIT)"
	git push
