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

#include "programsettings.h"

ProgramSettings::ProgramSettings()
    : m_settings(new QSettings("config/programconfig.ini", QSettings::IniFormat))
{
}


ProgramSettings::~ProgramSettings()
{
    delete m_settings;
}


void ProgramSettings::setFullscreen(int fullscreen)
{
    if (fullscreen == 0)
        m_settings->setValue("window/fullscreen", false);
    else
        m_settings->setValue("window/fullscreen", true);
}


void ProgramSettings::setShadingMode(int value)
{
    m_settings->setValue("opengl/shadingmode", value);
}


void ProgramSettings::setAmbientLight(int value)
{
    m_settings->setValue("opengl/ambientlight", value);
}


void ProgramSettings::setBackgroundColor(QString color)
{
    m_settings->setValue("opengl/backgroundcolor", color);
}
