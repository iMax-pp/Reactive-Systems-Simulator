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

#include <string>
#include <lua.hpp>
#include "luaEngines.h"

using namespace std;

LuaSimpleEngine::LuaSimpleEngine()
{
	luaState = lua_open();
}

LuaSimpleEngine::~LuaSimpleEngine()
{
	lua_close(luaState);
}

bool LuaSimpleEngine::loadFile(const char *fileName)
{
	return !(luaL_loadfile(luaState,fileName) || lua_pcall(luaState,0,0,0));
}

int LuaSimpleEngine::getInt(const char *varName)
{
	lua_getglobal(luaState,varName);
	if(lua_isnumber(luaState,-1))
	{
		return lua_tonumber(luaState,-1);
	}
	else return NULL;
}

float LuaSimpleEngine::getFloat(const char *varName)
{
	lua_getglobal(luaState,varName);
	if(lua_isnumber(luaState,-1))
	{
		return lua_tonumber(luaState,-1);
	}
	else return NULL;	
}

bool LuaSimpleEngine::getBool(const char *varName)
{
	lua_getglobal(luaState,varName);
	if(lua_isboolean(luaState,-1))
	{
		return lua_toboolean(luaState,-1);
	}
	else return NULL;
}

const char *LuaSimpleEngine::getString(const char *varName)
{
	lua_getglobal(luaState,varName);
	if(lua_isstring(luaState,-1))
	{
		return lua_tostring(luaState,-1);
	}
	else return NULL;
}
