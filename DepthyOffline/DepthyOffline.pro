#-------------------------------------------------
#
# Project created by QtCreator 2016-09-03T09:01:44
#
#-------------------------------------------------

QT += core gui widgets webenginewidgets

TARGET = DepthyOffline
TEMPLATE = app

# /O2              - Creates fast code.
# /Ot              - Favors fast code.
# /GA              - Optimizes code for Windows application.
# /arch:[SSE|SSE2] - /arch:SSE allows the compiler to use the SSE instructions, and /arch:SSE2 allows the compiler to use the SSE2 instructions.
#QMAKE_CXXFLAGS_RELEASE += "/O2 /Ot /GA /arch:SSE2"
QMAKE_CXXFLAGS_RELEASE += -O2 -Ot -GA

SOURCES += main.cpp\
        mainwindow.cpp \
    dwebpage.cpp

HEADERS  += mainwindow.h \
    dwebpage.h

RESOURCES += \
    resources.qrc
