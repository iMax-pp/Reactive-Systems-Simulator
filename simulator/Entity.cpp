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

#include "Entity.h"

// Pour que Lunar comprenne quelque chose à ma classe :
const char Entity::className[] = "Entity";

#define method(class, name) {#name, &class::name}
Lunar<Entity>::RegType Entity::methods[] = {
	{0,0}
};


Entity::Entity(void)
{
	position = new Vec();
	angle = new Vec();
}


Entity::Entity(Vec pos, Vec ang)
{
	position = &pos;
	angle = &ang;
}


void Entity::setPosition(Vec pos)
{
	position = &pos;
}


void Entity::setPosition(float x, float y, float z)
{
	position->setValue(x, y, z);
}


void Entity::setAngle(Vec ang)
{
	angle = &ang;
}


void Entity::setAngle(float x, float y, float z)
{
	angle->setValue(x, y, z);
}


Vec* Entity::getPosition(void)
{
	return position;
}


Vec* Entity::getAngle(void)
{
	return angle;
}
