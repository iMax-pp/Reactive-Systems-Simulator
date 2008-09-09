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

#ifndef LUAENGINE_H
#define LUAENGINE_H

#include <iostream>
#include <string>
#include <lua.hpp>

class LuaEngine
{
	public:
		LuaEngine();
		~LuaEngine();
		
		// la fonction pour ouvrir et exécuter un fichier lua :
		bool loadFile(const char *fileName);
		
		// les fonctions pour lire des paramètres dans un fichier lua :
		int readInt(const char *varName);
		float readFloat(const char *varName);
		bool readBool(const char *varName);
		const char *readString(const char *varName);
		
		// un accesseur pour lua_State :
		lua_State* getLink(void);

	private:
		lua_State *luaState;
};

#endif
