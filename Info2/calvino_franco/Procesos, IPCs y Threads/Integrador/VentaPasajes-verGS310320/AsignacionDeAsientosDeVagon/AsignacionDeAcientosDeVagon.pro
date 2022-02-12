TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Hijos.c \
        SharedMemory.c \
        archivos.c \
        inicializaciones.c \
        main.c \
        pantallas.c \
        semaforos.c \
        señales.c \
        socket.c

HEADERS += \
    Hijos.h \
    SharedMemory.h \
    archivos.h \
    inicializaciones.h \
    pantallas.h \
    semaforos.h \
    señales.h \
    socket.h
