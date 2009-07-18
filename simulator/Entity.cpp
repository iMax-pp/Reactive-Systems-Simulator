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
    {0, 0}
};


Entity::Entity()
    : m_position(new Vec())
    , m_angle(new Vec())
{
}


Entity::Entity(Vec position, Vec angle)
    : m_position(&position)
    , m_angle(&angle)
{
}


void Entity::setPosition(Vec position)
{
    m_position = &position;
}


void Entity::setPosition(float x, float y, float z)
{
    m_position->setValue(x, y, z);
}


void Entity::setAngle(Vec angle)
{
    m_angle = &angle;
}


void Entity::setAngle(float x, float y, float z)
{
    m_angle->setValue(x, y, z);
}


Vec* Entity::position()
{
    return m_position;
}


Vec* Entity::angle()
{
    return m_angle;
}
