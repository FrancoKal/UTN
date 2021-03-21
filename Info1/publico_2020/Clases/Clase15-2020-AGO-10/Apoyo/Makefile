# Comentarios comienzan con #
# Introducimos macros.
#    < Contiene la dependencia del target
#    @ Contiene el target

CC=gcc
CFLAGS=-c -Wall
LDFLAGS= -Wall

OBJSV=mainvec.o funcvec.o
OBJSD=maindyn.o funcdyn.o

VEC=mvec
DYN=mdyn

all: $(VEC) $(DYN)


$(VEC): $(OBJSV)
	$(CC) -o $@ $(OBJSV) $(LDFLAGS)

$(DYN): $(OBJSD)
	$(CC) -o $@ $(OBJSD) $(LDFLAGS)

# Introducimos el comando % que actúa como wildcard. 
# Esto es: "Cualquier cosa" mas lo que sigue
%.o: %.c Makefile
	$(CC) $(CFLAGS) $< -o $@ 
# O sea, cualquier nombre que termine en ".o", se construye con
# la dependencia cuyo nombre comienza con la misma cadena de caracteres 
# pero que termina en ".c".
# Incluye una "obligación": Los fuentes y los objetos deben tener el mismo
# nombre excepto for la parte final que cambia ".o" por ".c" o visceversa.
#

clean:
	rm -f *.o
	rm -f $(VEC)
	rm -f $(DYN)

new: clean all

