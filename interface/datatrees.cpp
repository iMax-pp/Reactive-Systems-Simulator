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

#include "datatrees.h"

#include <QtGui>

// DataTrees class

DataTrees::DataTrees()
    : m_mainTree(new MainTree())
    , m_simTree(new SimTree())
{
    addTab(m_mainTree, tr("mainTree"));
    addTab(m_simTree, tr("simTree"));
}


DataTrees::~DataTrees()
{
    delete m_mainTree;
    delete m_simTree;
}


MainTree* DataTrees::mainTree()
{
    return m_mainTree;
}


SimTree* DataTrees::simTree()
{
    return m_simTree;
}


#pragma mark -

// MainTree class

MainTree::MainTree()
    : m_world(new QTreeWidgetItem(this))
    , m_entities(new QTreeWidgetItem(this))
    , m_dynamicEnts(new QTreeWidgetItem(m_entities))
    , m_staticEnts(new QTreeWidgetItem(m_entities))
    , m_voidEnts(new QTreeWidgetItem(m_entities))
    , m_camera(new QTreeWidgetItem(this))
    , m_lights(new QTreeWidgetItem(this))
{
    setColumnCount(1);
    setHeaderLabel(tr("Data"));

    m_world->setText(0, tr("World"));
    m_world->setIcon(0, QIcon(":/images/m_world.png"));

    m_entities->setText(0, tr("Entities"));
    m_entities->setIcon(0, QIcon(":/images/bricks.png"));

    m_dynamicEnts->setText(0, tr("Dynamic"));
    m_dynamicEnts->setIcon(0, QIcon(":/images/bullet_green.png"));

    m_staticEnts->setText(0, tr("Static"));
    m_staticEnts->setIcon(0, QIcon(":/images/bullet_red.png"));

    m_voidEnts->setText(0, tr("Void"));
    m_voidEnts->setIcon(0, QIcon(":/images/bullet_blue.png"));

    m_camera->setText(0, tr("Camera"));
    m_camera->setIcon(0, QIcon(":/images/eye.png"));

    m_lights->setText(0, tr("Lights"));
    m_lights->setIcon(0, QIcon(":/images/lightbulb.png"));
}


MainTree::~MainTree()
{
}


#pragma mark -

// SimTree class

SimTree::SimTree()
    : m_world(new QTreeWidgetItem(this))
    , m_team1(new QTreeWidgetItem(this))
    , m_team2(new QTreeWidgetItem(this))
    , m_robot1(new QTreeWidgetItem(m_team1))
    , m_robot2(new QTreeWidgetItem(m_team1))
    , m_robot3(new QTreeWidgetItem(m_team1))
    , m_robot4(new QTreeWidgetItem(m_team2))
    , m_robot5(new QTreeWidgetItem(m_team2))
    , m_robot6(new QTreeWidgetItem(m_team2))
    , m_stargate(new QTreeWidgetItem(this))
    , m_keys(new QTreeWidgetItem(this))
{
    setColumnCount(2);
    setHeaderLabel(tr("Data"));
    setColumnHidden(1, true);

    m_world->setText(0, tr("World"));
    m_world->setIcon(0, QIcon(":/images/m_world.png"));

    m_team1->setText(0, tr("Team 1"));
    m_team1->setIcon(0, QIcon(":/images/user_red.png"));

    m_team2->setText(0, tr("Team 2"));
    m_team2->setIcon(0, QIcon(":/images/user_green.png"));

    m_robot1->setText(0, tr("Robot 1"));
    m_robot1->setIcon(0, QIcon(":/images/bullet_red.png"));

    m_robot2->setText(0, tr("Robot 2"));
    m_robot2->setText(1, tr("#345678")); // MS: What's the purpose of this?
    m_robot2->setIcon(0, QIcon(":/images/bullet_red.png"));

    m_robot3->setText(0, tr("Robot 3"));
    m_robot3->setIcon(0, QIcon(":/images/bullet_red.png"));

    m_robot4->setText(0, tr("Robot 4"));
    m_robot4->setIcon(0, QIcon(":/images/bullet_green.png"));

    m_robot5->setText(0, tr("Robot 5"));
    m_robot5->setIcon(0, QIcon(":/images/bullet_green.png"));

    m_robot6->setText(0, tr("Robot 6"));
    m_robot6->setIcon(0, QIcon(":/images/bullet_green.png"));

    m_stargate->setText(0, tr("Stargate"));
    m_stargate->setIcon(0, QIcon(":/images/cake.png"));

    m_keys->setText(0, tr("Keys"));
    m_keys->setIcon(0, QIcon(":/images/key.png"));
}


SimTree::~SimTree()
{
}
