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

#include "luaEngine.h"

using namespace std;

LuaEngine::LuaEngine()
{
	// initialisation de l'environnement d'exécution de lua
	luaState = lua_open();
	luaL_openlibs(luaState);
}

LuaEngine::~LuaEngine()
{
	// on n'oublie pas de fermer lua en partant...
	lua_close(luaState);
}

bool LuaEngine::loadFile(const char *fileName)
{
	// on charge le fichier,
	// le chargement rend un booléen qui vaut vrai si le chargement a échoué
	bool result = luaL_dofile(luaState, fileName);
	if(result)
	{
		std::cout << "Cannot load the file" << std::endl;
	}
	return !result;
}

int LuaEngine::readInt(const char *varName)
{
	// on initialise la variable qui sera retournée, on initialise la pile, et on récupère la variable
	int result;
	lua_settop(luaState, 0);
	lua_getglobal(luaState, varName);
	
	// on vérifie le type
	if(lua_isnumber(luaState, -1))
	{ result = lua_tonumber(luaState, -1); }
	else
	{ result = NULL; }
	
	// on dépile, et on retourne la variable
	lua_pop(luaState, 1);
	return result;
}

float LuaEngine::readFloat(const char *varName)
{
	// on initialise la variable qui sera retournée, on initialise la pile, et on récupère la variable
	float result;
	lua_settop(luaState, 0);
	lua_getglobal(luaState, varName);
	
	// on vérifie le type
	if(lua_isnumber(luaState, -1))
	{ result = lua_tonumber(luaState, -1); }
	else
	{ result = NULL; }
	
	// on dépile et on retourne la variable
	lua_pop(luaState, 1);
	return result;
}

bool LuaEngine::readBool(const char *varName)
{
	// on initialise la variable qui sera retournée, on initialise la pile, et on récupère la variable
	bool result;
	lua_settop(luaState, 0);
	lua_getglobal(luaState, varName);
	
	// on vérifie le type
	if(lua_isboolean(luaState, -1))
	{ result = lua_toboolean(luaState, -1); }
	else
	{ result = NULL; }
	
	// on dépile et on retourne la variable
	lua_pop(luaState, 1);
	return result;
}

const char *LuaEngine::readString(const char *varName)
{
	// on initialise la variable qui sera retournée, on initialise la pile, et on récupère la variable
	const char *result;
	lua_settop(luaState, 0);
	lua_getglobal(luaState, varName);
	
	// on vérifie le type
	if(lua_isstring(luaState, -1))
	{ result = lua_tostring(luaState, -1); }
	else
	{ result = NULL; }
	
	// on dépile et on retourne la variable
	lua_pop(luaState, 1);
	return result;
}
