CC		=	gcc
CFLAGS		=	-c -fPIC -Wall
LDFLAGS	=	-Wall
OBJS		=	main3.o funciones3.o
EJERCICIO	=	ej_3
STATICLIB	=	libej_3.a
SHAREDLIB	=	libej_3.so
SONAME		=	libej_3.so.1
VERSION	=	.0
RELEASE	=	.1
RPATH		=	.
#SHAREDFLAGS	=	-shared -Wl,-soname,$(SONAME) -Wl,-rpath,$(RPATH) -lc -Wall
SHAREDFLAGS	=	-shared -Wl,-soname,$(SONAME) 	
LIBEJECUTABLE	=	mi_lib3

$(EJERCICIO): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

%.o: %.c Makefile
	$(CC) $(CFLAGS) $< -o $@
	
all: $(STATICLIB) $(SHAREDLIB)

$(LIBEJECUTABLE):
	$(CC) -o $(OBJS) $(LIBEJECUTABLE) -l$(EJERCICIO) -L.

$(STATICLIB): $(OBJS)
	ar rcs $(STATICLIB) $(OBJS)

$(SHAREDLIB): $(OBJS)
	$(CC) $(SHAREDFLAGS) -o $(SONAME)$(VERSION)$(RELEASE) $(OBJS) -lc

install:
#	cp $(STATICLIB) $(RPATH)
#	cp $(SONAME)$(VERSION)$(RELEASE) $(RPATH)
	sudo ldconfig -n $(RPATH)
	ln -svnf $(RPATH)$(SONAME) $(RPATH)$(SHAREDLIB)

clean:
	rm -f ./*.o
	rm -f $(STATICLIB) $(SONAME)$(VERSION)$(RELEASE)

uninstall:
	rm $(RPATH)$(STATICLIB) $(RPATH)$(SHAREDLIB) $(RPATH)$(SONAME) $(RPATH)$(SONAME)$(VERSION)$(RELEASE)

new: clean all

git_lib:
	git add $(STATICLIB) $(SHAREDLIB)
	git commit -m "libs $(STATICLIB) $(SHAREDLIB)"
	git push


git:
	git add *.c *.h *makefile
	git commit -m "$(EJERCICIO)"
	git push

