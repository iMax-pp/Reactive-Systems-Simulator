/*
 *    Copyright 2010 Humhpries & Simon
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 *
 */

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
