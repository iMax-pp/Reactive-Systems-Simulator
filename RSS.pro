######################################################################
# Automatically generated by qmake (2.01a) Thu Jun 5 14:59:50 2008
######################################################################

TEMPLATE = app
TARGET = RSS
CONFIG  += qt opengl warn_on release thread
QT += xml opengl
DESTDIR = release

DEPENDPATH += . \
              interface \
              simulator \
              lua \

INCLUDEPATH += . \
               interface \
               simulator \
               lua \

# Input
HEADERS += interface/cameracontrolswidget.h \
           interface/configdialog.h \
           interface/consolewidget.h \
           interface/controlswidget.h \
           interface/globwidget.h \
           interface/glwidget.h \
           interface/informationsbox.h \
           interface/mainwindow.h \
           interface/pages.h \
		   interface/programsettings.h \
		   interface/speedcontrolswidget.h \
           simulator/GLViewer.h \
           lua/luaEngines.h \
		   lua/lunar.h
           
SOURCES += main.cpp \
           interface/cameracontrolswidget.cpp \
           interface/configdialog.cpp \
           interface/consolewidget.cpp \
           interface/controlswidget.cpp \
           interface/globwidget.cpp \
           interface/glwidget.cpp \
           interface/informationsbox.cpp \
           interface/mainwindow.cpp \
           interface/pages.cpp \
		   interface/programsettings.cpp \
           interface/speedcontrolswidget.cpp \
           simulator/GLViewer.cpp \
           lua/luaEngines.cpp
           
RESOURCES += application.qrc

linux-g++:LIBS *= -Llib/linux -lQGLViewer -llua
macx:LIBS *= -Llib/macx -lQGLViewer -llua
win32:LIBS *= -Llib/windows -lQGLViewer2 -llua
