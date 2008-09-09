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
HEADERS += interface/configdialog.h \
           interface/consolewidget.h \
           interface/controlswidget.h \
           interface/informationsbox.h \
           interface/mainwindow.h \
		   interface/programsettings.h \
		   interface/datatrees.h \
           simulator/GLViewer.h \
           simulator/GLControler.h \
		   simulator/staticEntity.h \
		   lua/lunar.h
           
SOURCES += main.cpp \
           interface/configdialog.cpp \
           interface/consolewidget.cpp \
           interface/controlswidget.cpp \
           interface/informationsbox.cpp \
           interface/mainwindow.cpp \
		   interface/programsettings.cpp \
		   interface/datatrees.cpp \
           simulator/GLViewer.cpp \
           simulator/GLControler.cpp \
		   simulator/staticEntity.cpp
           
RESOURCES += application.qrc

linux-g++:LIBS *= -Llib/linux -lQGLViewer -llua
macx:LIBS *= -Llib/macx -lQGLViewer -llua
win32:LIBS *= -Llib/windows -lQGLViewer2 -llua
