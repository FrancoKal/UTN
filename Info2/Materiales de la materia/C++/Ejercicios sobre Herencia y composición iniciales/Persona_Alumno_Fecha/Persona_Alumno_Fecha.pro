TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    alumno.cpp \
    fecha.cpp \
    persona.cpp

OTHER_FILES += \
    Persona_Alumno_Fecha.pro.user

HEADERS += \
    persona.h \
    alumno.h \
    fecha.h
