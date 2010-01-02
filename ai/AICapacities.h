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

#ifndef AICAPACITIES_H
#define AICAPACITIES_H

#include "GLEntity.h"
#include <vector>

class AICapacityBase {
    // Nom long :(, mais on aura jamais à s'en servir, c'est une classe abstraite. ^^

};

class AIVision : public AICapacityBase {
    // Donne une capacité de vision machine à l'entité.
    public:
        AIVision();
        ~AIVision();

    private:

};

class AIPathfinding : public AICapacityBase {
    // Donne une capacité de recherche de chemin intelligente à l'entité.
    public:
        AIPathfinding();
        ~AIPathfinding();

    private:

};

class AIFuzzyLogic : public AICapacityBase {
    // Donne une capacité de faire des décisions avec une logique floue.
    // Non binaire à la true/false, plus proche d'un raisonnement humain,
    // il donnera les "meilleurs", "plus proches"...sans utiliser de nombres pour le résultat.
    public:
        AIFuzzyLogic();
        ~AIFuzzyLogic();

    private:

};

class AITalk : public AICapacityBase {
    // Donne une capacité de communication par messages textuels courts.
    public:
        AITalk();
        ~AITalk();

    private:

};

class AIDataComm : public AICapacityBase {
    // AITalk ne permet que de parler par texte, celui-ci donne la capacité
    // "cybernetique" d'envoyer des données.
    public:
        AIDataComm();
        ~AIDataComm();

    private:
};

class AIMemory : public AICapacityBase {
    // Donne une mémoire des évenements et du monde...carte, nombre d'objets, trucs. :)
    // Attention, ceci n'est que la mémoire! La carte n'est qu'une carte,
    // pas la capacité de cartographier.
    public:
        AIMemory();
        ~AIMemory();

    private:
};

class AIMapping : public AICapacityBase {
    // Donne la capacité de cartographier le monde.
    public:
        AIMapping();
        ~AIMapping();

    private:
};

class AIGenetics : public AICapacityBase {
    // Donne la capacité de cartographier le monde.
    // (MS: Uhh? Je ne suis pas convaincu de ce commentaire.)
    public:
        AIMapping();
        ~AIMapping();

    private:
};

#endif
