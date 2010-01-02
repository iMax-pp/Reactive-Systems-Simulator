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

#ifndef LIGHT_H
#define LIGHT_H

#include "Entity.h"

using namespace qglviewer;

class Light : public Entity {
    public:
        Light();
        Light(Vec position, Vec angle);
        Light(lua_State* L) { } // Surdéfinition du constructeur obligatoire pour Lunar
        ~Light() { }

        void setPosition(lua_State* L);
        int setAngle(lua_State* L);

    private:
        friend class Lunar<Light>;
        static const char className[];
        static Lunar<Light>::RegType methods[];
};

#endif
