TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    animal.cpp \
    perro.cpp \
    gato.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    animal.h \
    perro.h \
    gato.h

