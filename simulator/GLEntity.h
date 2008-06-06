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

#ifndef GLENTITY_H
#define GLENTITY_H

#include <vector>
#include <QStringList>
#include "GLToolBox.h"

//L'entité de base. Statique, peut avoir une représentation graphique, mais ne bouge pas seul.
class GLEntity
{
	public:
		GLEntity();
		~GLEntity();
		
		void setPosition3f(num3f pos); //Sert à spécifier une position absolument
		void setRotation3f(num3f angle); //Sert à spécifier un angle absolu
		void translate3f(num3f relPos); //Sert à positionner une entitée relativement à sa position courante => translation
		void rotate3f(num3f relAngle); //Sert à tourner une entitée relativement à ses angles courants => rotation
		void move(float fact); //Sert à faire avancer ou reculer une entité;
		
		QStringList getProperties(); //Renvoit les propriétés de l'entité.
									 //Sert à être utilisé directement par l'afficheur d'infos, doù le QStringList.
		
	private:
		num3f position;
		num3f angle;
		vector<num3f> vertices;
};

//L'entity "vivante". A ce qui semble être un comportement autonome.
//En faite, c'est un extention de la classe GLEntity qui contient des modificateurs de propriétés conditionnels et réactifs à l'environnement => comportement réactif.
class GLLivingEntity
{
	public:
		GLLivingEntity();
		~GLLivingEntity();
		
		void addRule(); //Ajoute une règle de comportement.
						 //Ce genre de règle n'est pas véritablement propre à un comportement => gravitation, friction, perte/gain de chaleur, etc...
		
		void addState(); //Ajoute un état. cf. AIStateMachine
						  //On suppose que chaque entité "vivante" a au moins un state machine basique mort/vivant.

		void addCapacity(); //Ajoute une capacité.
							 //Une capacité serait une extention des aptitudes de l'entité
							 // => Peut trouver un chemin par A*
							 // => Est soumis aux collisions
							 // => Est dotté de vision machine
							 // => Est soumis aux forces physiques classiques
							 // => ...

	private:
		vector<*AIRule> rules;
		vector<*AIState> states;
		vector<*AICapacity> capacities;
}
#endif
