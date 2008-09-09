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

#ifndef STATICENTITY_H
#define STATICENTITY_H

#include <QGLViewer/vec.h>
#include <QStringList>
#include "../lua/lunar.h"

using namespace qglviewer;

class StaticEntity
{
	public:
		StaticEntity(void);								// Constructeurs
		StaticEntity(Vec pos, Vec ang);
		StaticEntity (lua_State* L){}					// La surdéfinition du constructeur obligatoire pour Lunar
		~StaticEntity (){}								// idem pour le destructeur

		void setPosition (Vec pos);						// Sert à spécifier une position absolument avec un vecteur
		void setPosition(float x, float y, float z);	// avec des float
		int setPosition (lua_State* L);					// avec Lua
	
		void setAngle (Vec ang);						// Sert à spécifier un angle absolu avec un vecteur
		void setAngle(float x, float y, float z);		// avec des float
		int setAngle (lua_State* L);					// avec Lua
		
		Vec* getPosition (void);						// Accesseurs toujours pratique
		Vec* getAngle (void);

		QStringList getProperties ();					//Renvoit les propriétés de l'entité.
														//Sert à être utilisé directement par l'afficheur d'infos, doù le QStringList.

	private:
		Vec *position;
		Vec *angle;

		friend class Lunar<StaticEntity>;				// 3 choses obligatoires pour Lunar (nom de la classe, et liste des méthodes)
		static const char className[];
		static Lunar<StaticEntity>::RegType methods[];
};

#endif
