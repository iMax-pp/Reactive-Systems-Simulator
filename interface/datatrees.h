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

#ifndef DATATREES_H
#define DATATREES_H

#include "informationsbox.h"
#include <QtGui>

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
