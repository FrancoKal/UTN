TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ipc.cpp \
        main.cpp \
        shmem.cpp

HEADERS += \
    ipc.h \
    shmem.h
