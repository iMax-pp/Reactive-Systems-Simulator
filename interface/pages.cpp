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

#include "pages.h"

WorldConfigPage::WorldConfigPage(QWidget *parent)
: QWidget(parent)
{	
	WorldSettings * settings = new WorldSettings();
	
	QGroupBox *teamsConfigGroup = new QGroupBox(tr("Teams configuration"));
	
	QLabel *numberOfTeamsLabel = new QLabel(tr("Number of Teams :"));
	QSpinBox *numberOfTeamsSelector = new QSpinBox;
	numberOfTeamsSelector->setMinimum(1);
	numberOfTeamsSelector->setMaximum(3);
	numberOfTeamsSelector->setValue(settings->value("numberofteams").toInt());
	QObject::connect(numberOfTeamsSelector, SIGNAL(valueChanged(int)), settings, SLOT(setNumberOfTeams(int)));
	
	QLabel *numberOfEntitiesLabel = new QLabel(tr("Number of Entities per Team :"));
	QSpinBox *numberOfEntitiesSelector = new QSpinBox;
	numberOfEntitiesSelector->setMinimum(1);
	numberOfEntitiesSelector->setMaximum(3);
	numberOfEntitiesSelector->setValue(settings->value("numberofentities").toInt());
	QObject::connect(numberOfEntitiesSelector, SIGNAL(valueChanged(int)), settings, SLOT(setNumberOfEntities(int)));
	
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
	temperatureSelector->setValue(settings->value("temperature").toInt());
	QObject::connect(temperatureSelector, SIGNAL(valueChanged(int)), settings, SLOT(setTemperature(int)));
	
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
	ProgramSettings * settings = new ProgramSettings();
	
	QCheckBox *fullscreenCheckBox = new QCheckBox(tr("Set program fullscreen\n on startup."));
	fullscreenCheckBox->setChecked(settings->value("fullscreen").toBool());
	QObject::connect(fullscreenCheckBox, SIGNAL(stateChanged(int)), settings, SLOT(setFullscreen(int)));
	
	QVBoxLayout *programConfigLayout = new QVBoxLayout;
	programConfigLayout->addWidget(fullscreenCheckBox);
	setLayout(programConfigLayout);
}

OpenGLPage::OpenGLPage(QWidget *parent)
: QWidget(parent)
{
	
}