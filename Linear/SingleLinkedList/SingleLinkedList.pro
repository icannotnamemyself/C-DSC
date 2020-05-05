TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        SingleLinkedList.cpp \
        cityList.cpp \
        cmenu.cpp \
        helper.cpp \
        main.cpp \
        menu.cpp \
        node.cpp

HEADERS += \
    SingleLinkedList.h \
    Type.h \
    cityList.h \
    cmenu.h \
    error.h \
    helper.h \
    menu.h \
    node.h
LIBS += -static

