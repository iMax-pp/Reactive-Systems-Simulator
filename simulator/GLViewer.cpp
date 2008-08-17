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

void Viewer::setConsole(ConsoleWidget *consolePointer)
{
	console = consolePointer;
}

void Viewer::setInfos(InformationsBox* infoPointer)
{
	infos = infoPointer;
}

void Viewer::drawWithNames()
{
	const int nb = 3;
	for (int i=0; i<nb; ++i)
    {
		glPushMatrix();
		glTranslatef(cos(2.0*i*M_PI/nb)/2.0, 0.2, sin(2.0*i*M_PI/nb)/2.0);

		glPushName(i);
		glScalef(0.3f, 0.3f, 0.3f);
		glCallList(spiral);
		glPopName();

		glPopMatrix();
    }
}

void Viewer::postSelection(const QPoint& point)
{
	//Apparently this is what happens after a selection...hmmm
	
	// Compute orig and dir, used to draw a representation of the intersecting line
	camera()->convertClickToLine(point, orig, dir);

	// Find the selectedPoint coordinates, using camera()->pointUnderPixel().
	bool found;
	selectedPoint = camera()->pointUnderPixel(point, found);
	selectedPoint -= 0.01f*dir; // Small offset to make point clearly visible.
	// Note that "found" is different from (selectedObjectId()>=0) because of the size of the select region.

	if (selectedName() == -1)
	console->newMsg(QString("No selection\n") +
				 QString("No object selected under pixel ") + QString::number(point.x()) + "," + QString::number(point.y()));
	else
	console->newMsg(QString("Selection\n") +
				 QString("Spiral number ") + QString::number(selectedName()) + QString(" selected under pixel ") +
				 QString::number(point.x()) + "," + QString::number(point.y()));
	
}

void Viewer::init()
{
	framenum = 0;
	
	//Mise en liste de la spirale
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

	
	//Mise en liste du monde
	world = glGenLists(1);

	glNewList(world, GL_COMPILE);
		glBegin(GL_QUADS);
			glColor3f(1.0f, 1.0f, 1.0f);
			for(float x=-1.0; x<1.0; x+=0.1)
			{
				for(float z=-1.0; z<1.0; z+=0.1)
				{
					glVertex3f(x, 0.0f, z+0.1);
					glVertex3f(x+0.1, 0.0f, z+0.1);
					glVertex3f(x+0.1, 0.0f, z);
					glVertex3f(x, 0.0f, z);
				}
			}
		glEnd();
	glEndList();



	setHandlerKeyboardModifiers(QGLViewer::CAMERA, Qt::NoModifier);
	setHandlerKeyboardModifiers(QGLViewer::FRAME,  Qt::ControlModifier);

	setManipulatedFrame(new ManipulatedFrame());

	//setAxisIsDrawn();
	//setGridIsDrawn();
	//setTextIsEnabled();
	setFPSIsDisplayed();
	
	camera()->setPosition(Vec(0.0, 0.5, 2.0));
	camera()->lookAt(Vec(0.0, 0.0, 0.0));
	
	//glPolygonMode( GL_FRONT, GL_FILL );
	//glPolygonMode( GL_BACK, GL_LINE );
	
	console->newMsg(QString("Viewer initiated"));	
}

// Draws a spiral
void Viewer::draw()
{
	glPolygonMode( GL_FRONT, GL_FILL );
	glPolygonMode( GL_BACK, GL_FILL );

	const int nb = 3;
	for (int i=0; i<nb; ++i)
	{
		glPushMatrix();
		glTranslatef(cos(2.0*i*M_PI/nb)/2.0, 0.2, sin(2.0*i*M_PI/nb)/2.0);
		if(i == selectedName())
		{
			glScalef(0.4f, 0.4f, 0.4f);
			drawAxis();
		}
		else
		{
			glScalef(0.3f, 0.3f, 0.3f);
		}
		glCallList(spiral);
		glPopMatrix();
	}

	glPolygonMode( GL_FRONT, GL_LINE );
	glPolygonMode( GL_BACK, GL_LINE );
	glCallList(world);

	framenum++;
	
	//console->newMsg(QString("Frame %1").arg(framenum));
	stringList.clear();
	stringList << QString("Viewer info");
	stringList << QString("  Frame number: %1").arg(framenum);
	stringList << QString("  Camera Position:");
	stringList << QString("     X=%1").arg(camera()->position().x);
	stringList << QString("     Y=%1").arg(camera()->position().y);
	stringList << QString("     Z=%1").arg(camera()->position().z);
	infos->listSet(stringList);
}
