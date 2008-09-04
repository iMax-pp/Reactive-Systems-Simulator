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

#ifndef GLTOOLBOX_H
#define GLTOOLBOX_H

#include <vector>

//La structure num3f parait un peu mal nommée, mais elle sert à la fois de coordonnées de positions et d'angles, à la fois absolues et relatives.
struct num3f
{
	float x;
	float y;
	float z;
};

//Class expérimentale dont le seul objectif est de facilement obtenir des primitives simples.
class shape
{
	public:
		vector<num3f> line(num3f p1, num3f p2);
		vector<num3f> square(float size);
		vector<num3f> circle(float radius);
		
		vector<num3f> cube(float size);
		vector<num3f> sphere(float radius);
		vector<num3f> cylinder(float radius, float height);
		
		//A compléter, on verra bien si ça sert à quelque chose ;)
};

#endif
