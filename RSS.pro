TEMPLATE = app
TARGET = RSS
CONFIG += debug

CONFIG(debug, debug|release) {
    DESTDIR = debug
} else { # Release
    DESTDIR = release
}

OBJECTS_DIR = $(DESTDIR)/obj
MOC_DIR = $(DESTDIR)/moc

CONFIG += qt opengl warn_on thread
QT += xml opengl

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
           interface/logwidget.h \
           interface/controlswidget.h \
           interface/informationsbox.h \
           interface/mainwindow.h \
           interface/programsettings.h \
           interface/datatrees.h \
           simulator/GLViewer.h \
           simulator/GLControler.h \
           simulator/Entities.h \
           simulator/Entity.h \
           simulator/World.h \
           simulator/staticEntity.h \
           simulator/dynamicEntity.h \
           simulator/voidEntity.h \
           simulator/Light.h \
           lua/lunar.h

SOURCES += main.cpp \
           interface/configdialog.cpp \
           interface/logwidget.cpp \
           interface/controlswidget.cpp \
           interface/informationsbox.cpp \
           interface/mainwindow.cpp \
           interface/programsettings.cpp \
           interface/datatrees.cpp \
           simulator/GLViewer.cpp \
           simulator/GLControler.cpp \
           simulator/Entity.cpp \
           simulator/staticEntity.cpp

RESOURCES += application.qrc

linux-g++:LIBS += -lQGLViewer -llua
macx:LIBS += -framework QGLViewer -llua
win32:LIBS *= -Llib/windows -lQGLViewer2 -llua
