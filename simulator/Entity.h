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

#ifndef ENTITY_H
#define ENTITY_H

#include "../lua/lunar.h"

#include <QGLViewer/vec.h>
#include <QStringList>

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
