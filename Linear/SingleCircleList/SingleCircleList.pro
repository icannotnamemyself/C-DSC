TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Person.cpp \
        SingleCircleList.cpp \
        main.cpp \
        menu.cpp \
        node.cpp

HEADERS += \
    SingleCircleList.h \
    menu.h \
    node.h \
    type.h
LIBS += -static
