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

#ifndef DATATREES_H
#define DATATREES_H

#include <QtGui>
#include "informationsbox.h"

class MainTree;
class SimTree;

class DataTrees : public QTabWidget {
        Q_OBJECT

    public:
        DataTrees();
        ~DataTrees();

        MainTree* mainTree();
        SimTree* simTree();

    private:
        MainTree* m_mainTree;
        SimTree* m_simTree;
};


class MainTree : public QTreeWidget {
    public:
        MainTree();
        ~MainTree();

    private:
        QTreeWidgetItem* m_world;
        QTreeWidgetItem* m_entities;
        QTreeWidgetItem* m_dynamicEnts;
        QTreeWidgetItem* m_staticEnts;
        QTreeWidgetItem* m_voidEnts;
        //Au secours! Des ents!
        QTreeWidgetItem* m_camera;
        QTreeWidgetItem* m_lights;
};

class SimTree : public QTreeWidget {
    public:
        SimTree();
        ~SimTree();

    private:
        QTreeWidgetItem* m_world;
        QTreeWidgetItem* m_team1;
        QTreeWidgetItem* m_team2;
        QTreeWidgetItem* m_robot1;
        QTreeWidgetItem* m_robot2;
        QTreeWidgetItem* m_robot3;
        QTreeWidgetItem* m_robot4;
        QTreeWidgetItem* m_robot5;
        QTreeWidgetItem* m_robot6;
        QTreeWidgetItem* m_stargate;
        QTreeWidgetItem* m_keys;
};

#endif
