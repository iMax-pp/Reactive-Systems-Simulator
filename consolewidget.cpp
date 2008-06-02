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

#include <QtGui>

#include "consolewidget.h"

ConsoleWidget::ConsoleWidget(){}

void ConsoleWidget::newMsg(const QString &message)
{
	//On met en place les structures de temps
	time_t rawtime;
	struct tm * timeinfo;
	char timeBuffer [12];

	//On s'en sert pour prendre l'heure. Ca sera nécessaire à chaque fois.
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	strftime(timeBuffer,11,"[%X] ",timeinfo);

	addItem(message.prepend(timeBuffer));
	scrollToItem(currentItem());
}

void ConsoleWidget::sendMsg(const QString &message)
{
	newMsg(message);
}
