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

#ifndef LUAENGINES_H
#define LUAENGINES_H

#include <iostream>
#include <string>
#include <lua.hpp>
#include <QObject>

using namespace std;

class LuaSimpleEngine : public QObject
{
	Q_OBJECT
	
	public:
		LuaSimpleEngine();
		~LuaSimpleEngine();
		bool loadFile(const char *fileName);
		int getInt(const char *varName);
		float getFloat(const char *varName);
		const char *getString(const char *varName);
		bool getBool(const char *varName);
	
	public slots:
		void setInt(int value);

	private:
		lua_State *luaState;
};

class LuaMetaEngine
{
	//Très Compliqué (d'ou le nom pourri...), celui ci se charge d'instancier le projet à partir des fichiers projet en Lua.
	//Meta? Parce que le langage des fichiers projet sera entre C++ et Lua. Les fichiers projet n'étant pas "actifs", ils ne font que configurer les entitées, et tout instancier avant de lancer la simulation.
	//En quelque sorte, il n'y aura qu'un appel de cette chose par projet...
};

#endif

