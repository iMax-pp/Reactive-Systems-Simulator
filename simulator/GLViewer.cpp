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
#include "../interface/consolewidget.h"
#include <QList>
#include <QStringList>

using namespace std;

void Viewer::setConsole(ConsoleWidget *consolePointer)
{
	console = consolePointer;
}

void Viewer::setInfos(InformationsBox* infoPointer)
{
	infos = infoPointer;
}

// Draws a spiral
void Viewer::draw()
{
	if(!listDone)
	{
		spiral = glGenLists(1);

		const float nbSteps = 200.0;
		
		glNewList(spiral, GL_COMPILE);
			glBegin(GL_QUAD_STRIP);
			for (int i=0; i<nbSteps; ++i)
			{
				const float ratio = i/nbSteps;
				const float angle = 21.0f*ratio;
				const float c = cos(angle);
				const float s = sin(angle);
				const float r1 = 1.0f - 0.8f*ratio;
				const float r2 = 0.8f - 0.8f*ratio;
				const float alt = ratio - 0.5f;
				const float nor = 0.5f;
				const float up = sqrt(1.0f-nor*nor);
				glColor3f(1.0f-ratio, 0.2f , ratio);
				glNormal3f(nor*c, up, nor*s);
				glVertex3f(r1*c, alt, r1*s);
				glVertex3f(r2*c, alt+0.05f, r2*s);
			}
			glEnd();
		glEndList();
		listDone = true;
		framenum = 0;
		console->newMsg(QString("DisplayList id:%1").arg(spiral));
	}
	glCallList(spiral);
	framenum++;
	
	//console->newMsg(QString("Frame %1").arg(framenum));
	stringList.clear();
	stringList << QString("Viewer info") << QString("  Frame number: %1").arg(framenum) << QString("  Other wonderful info");
	infos->listSet(stringList);
}

void Viewer::init()
{
	listDone = false;
	
	console->newMsg(QString("Viewer initiated"));

	// Restore previous viewer state.
	//restoreStateFromFile();
	
}
