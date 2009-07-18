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

#ifndef ENTITY_H
#define ENTITY_H

#include <QGLViewer/vec.h>
#include <QStringList>

#include "../lua/lunar.h"

using namespace qglviewer;

class Entity {
    public:
        Entity(void);
        Entity(Vec position, Vec angle);
        Entity(lua_State* L) { } // Surdéfinition du constructeur obligatoire pour Lunar
        ~Entity() { }

        Vec* position(void);
        Vec* angle(void);

        void setPosition(Vec position);
        void setPosition(float x, float y, float z);

        void setAngle(Vec angle);
        void setAngle(float x, float y, float z);

        // QStringList properties();

    protected:
        Vec* m_position;
        Vec* m_angle;

    private:
        friend class Lunar<Entity>;
        static const char className[];
        static Lunar<Entity>::RegType methods[];
};

#endif
