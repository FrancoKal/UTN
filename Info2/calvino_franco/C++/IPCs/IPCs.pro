TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        IPCs.cpp \
        MessageQueue.cpp \
        Semaphore.cpp \
        SharedMemory.cpp \
        main.cpp \
        thread.cpp

HEADERS += \
    IPCs.h \
    MessageQueue.h \
    Semaphore.h \
    SharedMemory.h \
    thread.h
