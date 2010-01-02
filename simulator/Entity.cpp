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
