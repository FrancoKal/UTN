TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        IPCs.cpp \
        SharedMemory.cpp \
        main.cpp

HEADERS += \
    IPCs.h \
    SharedMemory.h
