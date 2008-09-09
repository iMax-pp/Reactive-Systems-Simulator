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

#include "staticEntity.h"

// Pour que Lunar comprenne quelque chose à ma classe :
const char StaticEntity::className[] = "StaticEntity";

#define method(class, name) {#name, &class::name}
Lunar<StaticEntity>::RegType StaticEntity::methods[] = {
	method(StaticEntity, setPosition),
	method(StaticEntity, setAngle),
	{0,0}
};

// Constructeur
StaticEntity::StaticEntity(void)
{
	position = new Vec();
	angle = new Vec();
}

StaticEntity::StaticEntity(Vec pos, Vec ang)
{
	position = &pos;
	angle = &ang;
}

// setPosition
// avec un vecteur
void StaticEntity::setPosition(Vec pos)
{ position = &pos; }

// avec des float
void StaticEntity::setPosition(float x, float y, float z)
{
	position->setValue(x, y, z);
}

// avec Lua
int StaticEntity::setPosition(lua_State* L)
{
	int nbArgs = lua_gettop(L);
	
	if (nbArgs == 3 && lua_isnumber(L,1) &&
		lua_isnumber(L,2) && lua_isnumber(L,3))
	{
		position->setValue(lua_tonumber(L,1), lua_tonumber(L,2), lua_tonumber(L,3));
	}
	else if (nbArgs == 0)
	{
		position->setValue(0, 0, 0);
	}
	else
	{
		std::cout << "StaticEntity:setPosition() : mauvais parametres" << std::endl;
	}
	
	return 0;
}

// setAngle
// avec un vecteur
void StaticEntity::setAngle(Vec ang)
{ angle = &ang; }

// avec des float
void StaticEntity::setAngle(float x, float y, float z)
{
	angle->setValue(x, y, z);
}

//avec Lua
int StaticEntity::setAngle(lua_State* L)
{
	int nbArgs = lua_gettop(L);
	
	if (nbArgs == 3 && lua_isnumber(L,1) &&
		lua_isnumber(L,2) && lua_isnumber(L,3))
	{
		angle->setValue(lua_tonumber(L,1), lua_tonumber(L,2), lua_tonumber(L,3));
	}
	else if (nbArgs == 0)
	{
		angle->setValue(0, 0, 0);
	}
	else
	{
		std::cout << "StaticEntity:setAngle() : mauvais parametres" << std::endl;
	}
	
	return 0;
}

// getPosition
Vec* StaticEntity::getPosition(void)
{ return position; }

// getAngle
Vec* StaticEntity::getAngle(void)
{ return angle; }
