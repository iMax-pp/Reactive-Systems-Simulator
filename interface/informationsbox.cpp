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

#include "informationsbox.h"
#include <string>

InformationsBox::InformationsBox(){}

void InformationsBox::setViewerPointer(Viewer* view)
{
	viewer = view;
}

void InformationsBox::listSet(QStringList infos)
{
	clear();
	addItems(infos);
}

void InformationsBox::showEnt(QTreeWidgetItem* ent, int col)
{
	clear();
	std::string temp = ent->text(0).toStdString();
	
	if(temp == "Camera")
	{		
		viewer->getCamData();
	}
	else
	{
		this->addItem(ent->text(0));
		this->addItem(tr("Sorry, no info on this :'("));		
	}
}
