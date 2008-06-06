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

#ifndef GLCONTROLER_H
#define GLCONTROLER_H

#include <vector>

#include <QObject>
#include <QStringList>

#include "GLEntity.h"

class GLControler : public QObject
{
	public:
		GLControler
		~GLControler
	
		//Ces deux fontions se chargent d'ajouter et d'enlever les entitées au monde.
		//On passe par le controleur pour que celui-ci ait un controle total sur le monde.
		*GLEntity addEntity(); //Constructeur d'entitées.
							   //pas sur de comment concevoir son constructeur encore. Renvoit un pointeur pour pouvoir utiliser l'entité.
		void delEntity(GLEntity ent); //Destructeur.
									  //Pas sur de comment spécifier l'entitée: instance ou pointeur?
		
	private:
		vector<*Entity> _Entities; //Un vecteur c'est une sorte de de tableau/pile/file hybride qui peut être itérée, utilisée avec des indices, et a des méthode push/pop. 

	signals:
		void newEntity(Entity *ent);

	public slots:
		
};

#endif
