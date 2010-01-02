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

#ifndef STATICENTITY_H
#define STATICENTITY_H

#include "Entity.h"

using namespace qglviewer;

class StaticEntity : public Entity {
    public:
        StaticEntity();
        StaticEntity(Vec position, Vec angle);
        StaticEntity(lua_State*) { } // Surdéfinition du constructeur obligatoire pour Lunar
        ~StaticEntity() { }

        void setDisplayList(uint id);

        int setPosition(lua_State* L);
        int setAngle(lua_State* L);

    private:
        uint displayListId;

        friend class Lunar<StaticEntity>;
        static const char className[];
        static Lunar<StaticEntity>::RegType methods[];
};

#endif
