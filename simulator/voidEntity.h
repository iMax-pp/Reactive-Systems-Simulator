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

#ifndef VOIDENTITY_H
#define VOIDENTITY_H

#include "Entity.h"

using namespace qglviewer;

class VoidEntity : public Entity {
	public:
		VoidEntity(void);									// Constructeurs
		VoidEntity(Vec pos, Vec ang);
		VoidEntity (lua_State* L){}							// La surdéfinition du constructeur obligatoire pour Lunar
		~VoidEntity (){}									// Destructeur

		int setPosition (lua_State* L);						// avec Lua

		int setAngle (lua_State* L);						// avec Lua

	private:
		friend class Lunar<VoidEntity>;						// 3 choses obligatoires pour Lunar (nom de la classe, et liste des méthodes)
		static const char className[];
		static Lunar<VoidEntity>::RegType methods[];
};

#endif
