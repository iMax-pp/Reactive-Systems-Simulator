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

#include "GLControler.h"

Controler::Controler()
{
}


Controler::~Controler()
{
}


//Méthodes pour ajouter une entité
/*
void Controler::setWorld(World *world)
{
	// Ici par contre je vois bien une boucle qui récupère les entités dans les différents vecteurs
	// et les ajoute dans le monde
	// sauf si on décide que les entités ne font pas parti du monde, ce qui n'est pas faux.
}
*/


void Controler::addStatEnt(StaticEntity* ent)
{
    // On ajoute notre entité dans le vecteur, il me semble qu'ajoute une entitée n'est que ça...
    m_statEnts.push_back(ent);
}


/*
void Controler::addDynEnt(dynamicEntity* ent)
{
	m_dynEnts.push_back(ent);
}


void Controler::addVoidEnt(voidEntity* ent)
{
	m_voidEnts.push_back(ent);
}


void Controler::addLight(Light* light)
{
	m_lights.push_back(light);
}


//Méthodes pour appliquer un cycle à un groupe ou toutes les entitées

void Controler::runAll()
{
	runWorld();
	runStatEnts();
	runDynEnts();
	runVoidEnts();
	runLights();
}


void Controler::runWorld()
{
}


void Controler::runStatEnts()
{
	for(i = 0 ; i < statEnts.size(); i++) {
    	//Do stuff here
	}
}


void Controler::runDynEnts()
{
}


void Controler::runVoidEnts()
{
}


void Controler::runLights()
{
}


//Méthodes pour dessiner un groupe ou toutes les entitées

void Controler::drawAll()
{
	drawWorld();
	drawStatEnts();
	drawDynEnts();
	drawLights();
}


void Controler::drawWorld()
{
}


void Controler::drawStatEnts()
{
}


void Controler::drawDynEnts()
{
}


void Controler::drawLights()
{
}
*/
