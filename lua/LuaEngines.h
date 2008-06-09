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

class LuaSimpleEngine
{
	//Très Simple (d'ou le nom) celui la ne fait que extraire des valeurs, pour les configs par exemple...voir même les écrire...
};

class LuaMetaEngine
{
	//Très Compliqué (d'ou le nom pourri...), celui ci se charge d'instancier le projet à partir des fichiers projet en Lua.
	//Meta? Parce que le langage des fichiers projet sera entre C++ et Lua. Les fichiers projet n'étant pas "actifs", ils ne font que configurer les entitées, et tout instancier avant de lancer la simulation.
	//En quelque sorte, il n'y aura qu'un appel de cette chose par projet...
};

#endif
