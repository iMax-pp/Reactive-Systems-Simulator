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

#include "datatrees.h"
#include <QtGui>

DataTrees::DataTrees()
{
	//mainTree = new MainTree();
	//simTree = new SimTree();
	
	//QTreeWidget *generalTree = new QTreeWidget();
	//QTreeWidget *simTree = new QTreeWidget();
	
	//addTab(mainTree, tr("General"));
	//addTab(simTree, tr("Simulation"));
	
	mainTree = new MainTree();
	addTab(mainTree, tr("mainTree"));

	simTree = new SimTree();
	addTab(simTree, tr("simTree"));
}

DataTrees::~DataTrees()
{}

MainTree* DataTrees::getMainTree()
{
	return mainTree;
}


MainTree::MainTree()
{
	setColumnCount(1);
	setHeaderLabel(tr("Data"));
	
	world = new QTreeWidgetItem(this);
	world->setText(0, tr("World"));
	world->setIcon(0, QIcon(":/images/world.png"));
	
	entities = new QTreeWidgetItem(this);
	entities->setText(0, tr("Entities"));
	entities->setIcon(0, QIcon(":/images/bricks.png"));

	dynamicEnts = new QTreeWidgetItem(entities);
	dynamicEnts->setText(0, tr("Dynamic"));
	dynamicEnts->setIcon(0, QIcon(":/images/bullet_green.png"));
	
	staticEnts = new QTreeWidgetItem(entities);
	staticEnts->setText(0, tr("Static"));
	staticEnts->setIcon(0, QIcon(":/images/bullet_red.png"));

	voidEnts = new QTreeWidgetItem(entities);
	voidEnts->setText(0, tr("Void"));
	voidEnts->setIcon(0, QIcon(":/images/bullet_blue.png"));

	camera = new QTreeWidgetItem(this);
	camera->setText(0, tr("Camera"));
	camera->setIcon(0, QIcon(":/images/eye.png"));	

	lights = new QTreeWidgetItem(this);
	lights->setText(0, tr("Lights"));
	lights->setIcon(0, QIcon(":/images/lightbulb.png"));	

}

MainTree::~MainTree()
{}


SimTree::SimTree()
{
	setColumnCount(2);
	setHeaderLabel(tr("Data"));
	setColumnHidden(1, true);
	
	world = new QTreeWidgetItem(this);
	world->setText(0, tr("World"));
	world->setIcon(0, QIcon(":/images/world.png"));

	team1 = new QTreeWidgetItem(this);
	team1->setText(0, tr("Team 1"));
	team1->setIcon(0, QIcon(":/images/user_red.png"));

	team2 = new QTreeWidgetItem(this);
	team2->setText(0, tr("Team 2"));
	team2->setIcon(0, QIcon(":/images/user_green.png"));

	robot1 = new QTreeWidgetItem(team1);
	robot1->setText(0, tr("Robot 1"));
	robot1->setIcon(0, QIcon(":/images/bullet_red.png"));

	robot2 = new QTreeWidgetItem(team1);
	robot2->setText(0, tr("Robot 2"));
	robot2->setText(1, tr("#345678"));
	robot2->setIcon(0, QIcon(":/images/bullet_red.png"));

	robot3 = new QTreeWidgetItem(team1);
	robot3->setText(0, tr("Robot 3"));
	robot3->setIcon(0, QIcon(":/images/bullet_red.png"));

	robot4 = new QTreeWidgetItem(team2);
	robot4->setText(0, tr("Robot 4"));
	robot4->setIcon(0, QIcon(":/images/bullet_green.png"));

	robot5 = new QTreeWidgetItem(team2);
	robot5->setText(0, tr("Robot 5"));
	robot5->setIcon(0, QIcon(":/images/bullet_green.png"));

	robot6 = new QTreeWidgetItem(team2);
	robot6->setText(0, tr("Robot 6"));
	robot6->setIcon(0, QIcon(":/images/bullet_green.png"));

	stargate = new QTreeWidgetItem(this);
	stargate->setText(0, tr("Stargate"));
	stargate->setIcon(0, QIcon(":/images/cake.png"));

	keys = new QTreeWidgetItem(this);
	keys->setText(0, tr("Keys"));
	keys->setIcon(0, QIcon(":/images/key.png"));
}

SimTree::~SimTree()
{}
