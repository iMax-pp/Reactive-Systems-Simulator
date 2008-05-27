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

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL>

class GLWidget : public QGLWidget
{
	Q_OBJECT
	
public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void timerEvent(QTimerEvent *) { update(); }
    //void mousePressEvent(QMouseEvent *) { killTimer(timerId); }
    //void mouseReleaseEvent(QMouseEvent *) { timerId = startTimer(20); }

public slots:
    void setWorldSpeed(int speed);

private:
    int timerId;
    int worldSpeedFactor;
    
	double gRot;
	GLint step;
	GLfloat y1, y2, y3;
}; 
 
#endif