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

#include "Entities.h"

class Controler {
    public:
        Controler();
        ~Controler();

        void setWorld(World* world);
        void addStatEnt(StaticEntity* ent);
        void addDynEnt(DynamicEntity* ent);
        void addVoidEnt(VoidEntity* ent);
        void addLight(Light* light);

        void runAll();
        void runWorld();
        void runStatEnts();
        void runDynEnts();
        void runVoidEnts();
        void runLights();

        void drawAll();
        void drawWorld();
        void drawStatEnts();
        void drawDynEnts();
        void drawLights();

    private:
        World*      m_world;
        std::vector <StaticEntity*>m_statEnts;
        std::vector <DynamicEntity*>m_dynEnts;
        std::vector <VoidEntity*>m_voidEnts;
        std::vector <Light*>m_lights;
};

#endif
