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

class DataTrees : public QTabWidget
{
	Q_OBJECT
	
	public:
		DataTrees();
		~DataTrees();
		
		MainTree* getMainTree();
		SimTree* getSimTree();
		
	private:			
		MainTree *mainTree;
		SimTree *simTree;		
};


class MainTree : public QTreeWidget
{	
	public:
		MainTree();
		~MainTree();
		
	private:
		QTreeWidgetItem *world;
		QTreeWidgetItem *entities;
		QTreeWidgetItem *dynamicEnts;
		QTreeWidgetItem *staticEnts;
		QTreeWidgetItem *voidEnts;
		//Au secours! Des ents!
		QTreeWidgetItem *camera;
		QTreeWidgetItem *lights;
};

class SimTree : public QTreeWidget
{
	public:
		SimTree();
		~SimTree();

	private:
		QTreeWidgetItem *world;
		QTreeWidgetItem *team1;
		QTreeWidgetItem *team2;
		QTreeWidgetItem *robot1;
		QTreeWidgetItem *robot2;
		QTreeWidgetItem *robot3;
		QTreeWidgetItem *robot4;
		QTreeWidgetItem *robot5;
		QTreeWidgetItem *robot6;
		QTreeWidgetItem *stargate;
		QTreeWidgetItem *keys;
};


#endif
