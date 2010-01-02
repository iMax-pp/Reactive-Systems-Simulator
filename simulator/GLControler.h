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

#ifndef GLCONTROLER_H
#define GLCONTROLER_H

#include "Entities.h"

#include <vector>

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
