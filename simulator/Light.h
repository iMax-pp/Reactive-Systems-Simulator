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

#ifndef LIGHT_H
#define LIGHT_H

#include <QGLViewer/vec.h>
#include <QStringList>
#include "../lua/lunar.h"

using namespace qglviewer;

class Light
{
	public:
		Light(void);										// Constructeurs
		Light(Vec pos, Vec ang);
		Light (lua_State* L){}								// La surdéfinition du constructeur obligatoire pour Lunar
		~Light (){}											// Destructeur

		void setPosition (Vec pos);							// Sert à spécifier une position absolument avec un vecteur
		void setPosition(float x, float y, float z);		// avec des float
		int setPosition (lua_State* L);						// avec Lua
	
		void setAngle (Vec ang);							// Sert à spécifier un angle absolu avec un vecteur
		void setAngle(float x, float y, float z);			// avec des float
		int setAngle (lua_State* L);						// avec Lua
		
		Vec* getPosition (void);							// Accesseurs toujours pratique
		Vec* getAngle (void);

		QStringList getProperties ();						// Renvoit les propriétés de l'entité.
															// Sert à être utilisé directement par l'afficheur d'infos, d'où le QStringList.

	private:
		Vec *position;
		Vec *angle;

		friend class Lunar<Light>;							// 3 choses obligatoires pour Lunar (nom de la classe, et liste des méthodes)
		static const char className[];
		static Lunar<Light>::RegType methods[];
};

#endif
