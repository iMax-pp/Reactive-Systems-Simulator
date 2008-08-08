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

#include "worldsettings.h"

WorldSettings::WorldSettings(){}

QVariant WorldSettings::value(const QString key, const QVariant defaultValue)
{
	QSettings settings("config/worldconfig.ini",QSettings::IniFormat);
	QVariant returnedValue = settings.value(key, defaultValue);
	settings.sync();
	
	return returnedValue;
}

void WorldSettings::setValue(const QString key, const QVariant value)
{
	QSettings settings("config/worldconfig.ini",QSettings::IniFormat);
	settings.setValue(key, value);
	settings.sync();
}

void WorldSettings::setNumberOfTeams(int value)
{
	QSettings settings("config/worldconfig.ini",QSettings::IniFormat);
	settings.setValue("numberofteams",value);
	settings.sync();	
}

void WorldSettings::setNumberOfEntities(int value)
{
	QSettings settings("config/worldconfig.ini",QSettings::IniFormat);
	settings.setValue("numberofentities",value);	
	settings.sync();
}

void WorldSettings::setTemperature(int value)
{
	QSettings settings("config/worldconfig.ini",QSettings::IniFormat);
	settings.setValue("temperature",value);	
	settings.sync();
}