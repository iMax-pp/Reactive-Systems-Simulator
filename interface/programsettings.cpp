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

#include <QSettings>

ProgramSettings::ProgramSettings()
    : m_settings(new QSettings(QSettings::UserScope, "Reactive Systems Simulator"))
{
    m_fullscreen = m_settings->value("window/fullscreen", false).toBool();
    m_shadingMode = m_settings->value("opengl/shadingmode", 0).toInt();
    m_ambientLight = m_settings->value("opengl/ambientlight", 0).toInt();
    m_backgroundColor = m_settings->value("opengl/backgroundcolor", "black").toString();
}


ProgramSettings::~ProgramSettings()
{
    delete m_settings;
}


bool ProgramSettings::isFullscreen()
{
    return m_fullscreen;
}


void ProgramSettings::setFullscreen(int fullscreen)
{
    if (!fullscreen)
        m_fullscreen = false;
    else
        m_fullscreen = true;
}


int ProgramSettings::shadingMode()
{
    return m_shadingMode;
}


void ProgramSettings::setShadingMode(int value)
{
    m_shadingMode = value;
}


int ProgramSettings::ambientLight()
{
    return m_ambientLight;
}


void ProgramSettings::setAmbientLight(int value)
{
    m_ambientLight = value;
}


QString ProgramSettings::backgroundColor()
{
    return m_backgroundColor;
}


void ProgramSettings::setBackgroundColor(QString color)
{
    m_backgroundColor = color;
}


void ProgramSettings::save()
{
    m_settings->setValue("window/fullscreen", m_fullscreen);
    m_settings->setValue("opengl/shadingmode", m_shadingMode);
    m_settings->setValue("opengl/ambientlight", m_ambientLight);
    m_settings->setValue("opengl/backgroundcolor", m_backgroundColor);
}


void ProgramSettings::reset()
{
    m_fullscreen = m_settings->value("window/fullscreen", false).toBool();
    m_shadingMode = m_settings->value("opengl/shadingmode", 0).toInt();
    m_ambientLight = m_settings->value("opengl/ambientlight", 0).toInt();
    m_backgroundColor = m_settings->value("opengl/backgroundcolor", "black").toString();
}
