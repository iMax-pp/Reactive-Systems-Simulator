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

#ifndef AICAPACITIES_H
#define AICAPACITIES_H

#include <vector>

#include "GLEntity.h"

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
