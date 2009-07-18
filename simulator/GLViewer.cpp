/*******************************************************************************************
**
**    Copyright 2008 Simon & Humphries
**
**    This file is part of the Reactive Systems Simulator.
**
**    The Reactive Systems Simulator is free software: you can redistribute it and/or modify
**    it under the terms of the GNU General Public License as published by
**    the Free Software Foundation, either version 3 of the License, or
**    (at your option) any later version.
**
**    The Reactive Systems Simulator is distributed in the hope that it will be useful,
**    but WITHOUT ANY WARRANTY; without even the implied warranty of
**    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**    GNU General Public License for more details.
**
**    You should have received a copy of the GNU General Public License
**    along with the Reactive Systems Simulator .  If not, see <http://www.gnu.org/licenses/>.
**
********************************************************************************************/

#include "GLViewer.h"

using namespace std;
using namespace qglviewer;

/*
void Viewer::setInfos(InformationsBox* infoPointer)
    : m_infos(infoPointer)
{
}
*/


bool Viewer::isStarted()
{
    return m_started;
}


void Viewer::init()
{
    // m_controler = new Controler();
    FPSIsDisplayed();

    m_framenum = 0;
    m_rot = 0.0;
    m_step = 0.0;
    m_amp = 0.0;

    // Mise en liste de la spirale
    m_cube = glGenLists(1);

    glNewList(m_cube, GL_COMPILE);
    glScalef(0.05, 0.05, 0.05);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);			// Set The Color To Green
    glVertex3f(1.0f, 1.0f, -1.0f);			// Top Right Of The Quad (Top)
    glVertex3f(-1.0f, 1.0f, -1.0f);			// Top Left Of The Quad (Top)
    glVertex3f(-1.0f, 1.0f, 1.0f);			// Bottom Left Of The Quad (Top)
    glVertex3f(1.0f, 1.0f, 1.0f);			// Bottom Right Of The Quad (Top)
    glColor3f(1.0f, 0.5f, 0.0f);			// Set The Color To Orange
    glVertex3f(1.0f, -1.0f, 1.0f);			// Top Right Of The Quad (Bottom)
    glVertex3f(-1.0f, -1.0f, 1.0f);			// Top Left Of The Quad (Bottom)
    glVertex3f(-1.0f, -1.0f, -1.0f);		// Bottom Left Of The Quad (Bottom)
    glVertex3f(1.0f, -1.0f, -1.0f);			// Bottom Right Of The Quad (Bottom)
    glColor3f(1.0f, 0.0f, 0.0f);			// Set The Color To Red
    glVertex3f(1.0f, 1.0f, 1.0f);			// Top Right Of The Quad (Front)
    glVertex3f(-1.0f, 1.0f, 1.0f);			// Top Left Of The Quad (Front)
    glVertex3f(-1.0f, -1.0f, 1.0f);			// Bottom Left Of The Quad (Front)
    glVertex3f(1.0f, -1.0f, 1.0f);			// Bottom Right Of The Quad (Front)
    glColor3f(1.0f, 1.0f, 0.0f);			// Set The Color To Yellow
    glVertex3f(1.0f, -1.0f, -1.0f);			// Bottom Left Of The Quad (Back)
    glVertex3f(-1.0f, -1.0f, -1.0f);		// Bottom Right Of The Quad (Back)
    glVertex3f(-1.0f, 1.0f, -1.0f);			// Top Right Of The Quad (Back)
    glVertex3f(1.0f, 1.0f, -1.0f);			// Top Left Of The Quad (Back)
    glColor3f(0.0f, 0.0f, 1.0f);			// Set The Color To Blue
    glVertex3f(-1.0f, 1.0f, 1.0f);			// Top Right Of The Quad (Left)
    glVertex3f(-1.0f, 1.0f, -1.0f);			// Top Left Of The Quad (Left)
    glVertex3f(-1.0f, -1.0f, -1.0f);		// Bottom Left Of The Quad (Left)
    glVertex3f(-1.0f, -1.0f, 1.0f);			// Bottom Right Of The Quad (Left)
    glColor3f(1.0f, 0.0f, 1.0f);			// Set The Color To Violet
    glVertex3f(1.0f, 1.0f, -1.0f);			// Top Right Of The Quad (Right)
    glVertex3f(1.0f, 1.0f, 1.0f);			// Top Left Of The Quad (Right)
    glVertex3f(1.0f, -1.0f, 1.0f);			// Bottom Left Of The Quad (Right)
    glVertex3f(1.0f, -1.0f, -1.0f);			// Bottom Right Of The Quad (Right)
    glEnd();
    glEndList();

    // Mise en liste du monde
    m_world = glGenLists(1);
    glNewList(m_world, GL_COMPILE);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    for (float x = -1.0; x < 1.0; x += 0.1) {
        for (float z = -1.0; z < 1.0; z += 0.1) {
            glVertex3f(x, 0.0f, z + 0.1);
            glVertex3f(x + 0.1, 0.0f, z + 0.1);
            glVertex3f(x + 0.1, 0.0f, z);
            glVertex3f(x, 0.0f, z);
        }
    }

    glEnd();
    glEndList();

    setHandlerKeyboardModifiers(QGLViewer::CAMERA, Qt::NoModifier);
    setHandlerKeyboardModifiers(QGLViewer::FRAME, Qt::ControlModifier);
    setManipulatedFrame(new ManipulatedFrame());

    // setAxisIsDrawn();
    // setGridIsDrawn();
    // setTextIsEnabled();

    setFPSIsDisplayed();

    camera()->setPosition(Vec(0.0, 0.5, 2.0));
    camera()->lookAt(Vec(0.0, 0.0, 0.0));

    // glPolygonMode(GL_FRONT, GL_FILL);
    // glPolygonMode(GL_BACK, GL_LINE);

    emit(sigMsg(QString(tr("Simulation initiated"))));
}


void Viewer::drawWithNames()
{
    const int nb = 40;

    for (int i = 0; i < nb; ++i) {
        glPushMatrix();
        glScalef(i / 30.0, i / 30.0, i / 30.0);
        glTranslatef(cos((i + m_step) / 2.0) / 1.5, sin(0.8*i + m_step) * (sin(m_amp) / 4.0), sin((i + m_step) / 2.0) / 1.5);
        glRotatef(m_rot, 1.0f, 1.0f, 1.0f);
        glPushName(i);
        glCallList(m_cube);
        glPopName();
        glPopMatrix();
    }
}


void Viewer::postSelection(const QPoint& point)
{
    // Apparently this is what happens after a selection...hmmm
    // Compute orig and dir, used to draw a representation of the intersecting line
    camera()->convertClickToLine(point, m_orig, m_dir);

    // Find the selectedPoint coordinates, using camera()->pointUnderPixel().
    bool found;
    m_selectedPoint = camera()->pointUnderPixel(point, found);
    m_selectedPoint -= 0.01f * m_dir; // Small offset to make point clearly visible.
    // Note that "found" is different from (selectedObjectId()>=0) because of the size of the select region.

    if (selectedName() == -1)
        emit(sigMsg(
                 tr("No selection\n")
                 + tr("No object at ")
                 + QString::number(point.x())
                 + tr(",")
                 + QString::number(point.y())));
    else
        emit(sigMsg(
                 tr("Selection\n")
                 + tr("Cube ")
                 + QString::number(selectedName())
                 + tr(" at ")
                 + QString::number(point.x())
                 + tr(",")
                 + QString::number(point.y())
             ));
}


// Draws a spiral
void Viewer::draw()
{
    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_FILL);
    const int nb = 40;

    for (int i = 0; i < nb; ++i) {
        glPushMatrix();
        glScalef(i / 30.0, i / 30.0, i / 30.0);
        // glTranslatef(cos(2.0 * i * M_PI / 10.0 + m_step) / 1.5, sin(2.0 * i + m_step) * (sin(m_amp) / 4.0),
        //              sin(2.0 * i * M_PI / 10.0 + m_step) / 1.5);
        glTranslatef(cos((i + m_step) / 2.0) / 1.5, sin(0.8*i + m_step) * (sin(m_amp) / 4.0), sin((i + m_step) / 2.0) / 1.5);
        glRotatef(m_rot, 1.0f, 1.0f, 1.0f);

        if (i == selectedName()) {
            glScalef(0.2f, 0.2f, 0.2f);
            drawAxis();
            glScalef(8.0f, 8.0f, 8.0f);
        }

        glCallList(m_cube);
        glPopMatrix();
    }

    glPolygonMode(GL_FRONT, GL_LINE);
    glPolygonMode(GL_BACK, GL_LINE);
    glCallList(m_world);
    // m_framenum++;
}


void Viewer::animate()
{
    m_rot += 0.5f;
    m_step += 0.2f;
    m_amp += 0.05f;
}


void Viewer::start()
{
    startAnimation();
    m_started = true;
}


void Viewer::stop()
{
    stopAnimation();
    m_started = false;
}


void Viewer::reset()
{
    init();
    stopAnimation();
}


void Viewer::restart()
{
    reset();
    startAnimation();
}


QStringList Viewer::camData()
{
    QStringList stringList;
    stringList.clear();
    stringList << QString(tr("Camera data"));
    // stringList << QString("  Frame number: %1").arg(m_framenum);
    stringList << QString(tr("  Position:"));
    stringList << QString("     X=%1").arg(camera()->position().x);
    stringList << QString("     Y=%1").arg(camera()->position().y);
    stringList << QString("     Z=%1").arg(camera()->position().z);
    // stringList << QString("     Rot=%1").arg(m_rot);
    // stringList << QString("     Step=%1").arg(m_step);
    // stringList << QString("     Amp=%1").arg(m_amp);
    return stringList;
}
