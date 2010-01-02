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

#include "staticEntity.h"

// Pour que Lunar comprenne quelque chose à ma classe :
const char StaticEntity::className[] = "StaticEntity";

#define method(class, name) {#name, &class::name}
Lunar<StaticEntity>::RegType StaticEntity::methods[] = {
    method(StaticEntity, setPosition),
    method(StaticEntity, setAngle),
    {0, 0}
};


StaticEntity::StaticEntity()
    : Entity()
{
}


StaticEntity::StaticEntity(Vec position, Vec angle)
    : Entity(position, angle)
{
}


int StaticEntity::setPosition(lua_State* L)
{
    int nbArgs = lua_gettop(L);

    if (nbArgs == 3 && lua_isnumber(L, 1)
        && lua_isnumber(L, 2) && lua_isnumber(L, 3))
        m_position->setValue(lua_tonumber(L, 1), lua_tonumber(L, 2), lua_tonumber(L, 3));
    else if (!nbArgs)
        m_position->setValue(0, 0, 0);
    else
        std::cout << "StaticEntity:setPosition() : wrong parameters" << std::endl;

    return 0;
}


int StaticEntity::setAngle(lua_State* L)
{
    int nbArgs = lua_gettop(L);

    if (nbArgs == 3 && lua_isnumber(L, 1)
        && lua_isnumber(L, 2) && lua_isnumber(L, 3))
        m_angle->setValue(lua_tonumber(L, 1), lua_tonumber(L, 2), lua_tonumber(L, 3));
    else if (!nbArgs)
        m_angle->setValue(0, 0, 0);
    else
        std::cout << "StaticEntity:setAngle() : wrong parameters" << std::endl;

    return 0;
}
