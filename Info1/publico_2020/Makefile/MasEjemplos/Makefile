# Comentarios comienzan con #
# Introducimos macros.
#    < Contiene la dependencia del target
#    @ Contiene el target

CC=gcc
CFLAGS=-c -Wall -g
LDFLAGS= -Wall -g

OBJS=mk-main.o mk-funciones.o
SOURCES=mk-main.c mk-funciones.c
HEADERS=mk-funciones.h

TP=5
LEGAJO=123456
ENTREGA=entrega_tp_$(TP)_$(LEGAJO)
EJEC=ejec


$(EJEC): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

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
	rm -f ejec

new: clean ejec

git:
	git commit -m "Entrega $(TP)"
	git push 

$(ENTREGA).tar.gz: $(SOURCES) $(HEADERS) Makefile
	tar -zcvf $(ENTREGA).tar.gz $(SOURCES) $(HEADERS) Makefile
