TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    cola.cpp \
    pila.cpp

SUBDIRS += \
    Pila.pro

HEADERS += \
    cola.h \
    datos.h \
    Pila.h
