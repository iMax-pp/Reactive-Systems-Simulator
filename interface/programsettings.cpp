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
    if (!fullscreen)
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
