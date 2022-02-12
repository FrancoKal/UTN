# $@ Contiene el target
# $< Contiene las dependencias del target


CC		=	g++
LDFLAGS	=	-Wall
CFLAGS		=	-c -Wall
SOURCES	=	main.cpp Taller.cpp Reparacion.cpp Hora.cpp
EJERCICIO	=	Taller
COMMIT		=	Taller

$(EJERCICIO):
	$(CC) $(SOURCES) $< -o $@ $(LDFLAGS)

git:
	git add *.c *.h *makefile
	git commit -m "$(COMMIT)"
	git push
