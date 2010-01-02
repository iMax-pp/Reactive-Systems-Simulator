/*
 *    Copyright 2010 Humhpries & Simon
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 *
 */

#ifndef GLVIEWER_H
#define GLVIEWER_H

#include <QGLViewer/qglviewer.h>
#include <QList>
#include <QStringList>

// #include "GLControler.h"
// #include "../interface/logwidget.h"
// #include "../interface/informationsbox.h"

class Viewer : public QGLViewer {
        Q_OBJECT

    public:
        // void setInfos(InformationsBox* infoPointer);
        QStringList camData();
        bool isStarted();

    protected:
        virtual void animate();
        virtual void draw();
        virtual void init();
        virtual void drawWithNames();
        virtual void postSelection(const QPoint& point);
        // virtual QString helpString() const;

    signals:
        void sigMsg(QString msg);

    public slots:
        void start();
        void stop();
        void reset();
        void restart();

    private:
        GLfloat m_rot;
        GLfloat m_step;
        GLfloat m_amp;
        GLuint  m_cube;
        GLuint  m_world;
        int     m_framenum;
        bool    m_started;

        // Controler* m_controler;
        // LogWidget* m_console;
        // InformationsBox* m_infos;

        qglviewer::Vec m_orig;
        qglviewer::Vec m_dir;
        qglviewer::Vec m_selectedPoint;
};

#endif
