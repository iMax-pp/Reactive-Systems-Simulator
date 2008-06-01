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

#include "pages.h"

WorldConfigPage::WorldConfigPage(QWidget *parent)
: QWidget(parent)
{
	QGroupBox *teamsConfigGroup = new QGroupBox(tr("Teams configuration"));
	
	QLabel *numberOfTeamsLabel = new QLabel(tr("Number of Teams :"));
	QSpinBox *numberOfTeamsSelector = new QSpinBox;
	numberOfTeamsSelector->setMinimum(1);
	numberOfTeamsSelector->setMaximum(3);
	numberOfTeamsSelector->setValue(2);
	
	QLabel *numberOfEntitiesLabel = new QLabel(tr("Number of Entities per Team :"));
	QSpinBox *numberOfEntitiesSelector = new QSpinBox;
	numberOfEntitiesSelector->setMinimum(1);
	numberOfEntitiesSelector->setMaximum(3);
	numberOfEntitiesSelector->setValue(3);	
	
	QVBoxLayout *teamsConfigLayout = new QVBoxLayout;
	teamsConfigLayout->addWidget(numberOfTeamsLabel);
	teamsConfigLayout->addWidget(numberOfTeamsSelector);
	teamsConfigLayout->addWidget(numberOfEntitiesLabel);
	teamsConfigLayout->addWidget(numberOfEntitiesSelector);
	teamsConfigGroup->setLayout(teamsConfigLayout);

	QGroupBox *worldConfig = new QGroupBox(tr("World configuration"));
	
	QLabel *temperatureLabel = new QLabel(tr("Temperature of the World :"));
	QSpinBox *temperatureSelector = new QSpinBox;
	temperatureSelector->setMinimum(0);
	temperatureSelector->setMaximum(100);
	temperatureSelector->setValue(20);	
	
	QVBoxLayout *worldConfigLayout = new QVBoxLayout;
	worldConfigLayout->addWidget(temperatureLabel);
	worldConfigLayout->addWidget(temperatureSelector);
	worldConfig->setLayout(worldConfigLayout);
	
	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(teamsConfigGroup);
	mainLayout->addWidget(worldConfig);
	mainLayout->addStretch(1);
	setLayout(mainLayout);
}


ConfigurationPage::ConfigurationPage(QWidget *parent)
: QWidget(parent)
{
	
}

OpenGLPage::OpenGLPage(QWidget *parent)
: QWidget(parent)
{
	
}