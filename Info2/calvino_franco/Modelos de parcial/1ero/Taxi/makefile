# $@ Contiene el target
# $< Contiene las dependencias del target


CC		=	g++
LDFLAGS	=	-Wall
CFLAGS		=	-c -Wall
SOURCES	=	main.cpp Lista.cpp Pila.cpp Taxi.cpp Viajes.cpp
EJERCICIO	=	Taxi
COMMIT		=	Taxi

$(EJERCICIO):
	$(CC) $(SOURCES) $< -o $@ $(LDFLAGS)

git:
	git add *.c *.h *makefile
	git commit -m "$(COMMIT)"
	git push
