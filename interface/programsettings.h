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

#ifndef PROGRAMSETTINGS_H
#define PROGRAMSETTINGS_H

#include <QObject>

class QString;
class QSettings;

class ProgramSettings : public QObject {
        Q_OBJECT

    public:
        ProgramSettings();
        ~ProgramSettings();

        bool isFullscreen();
        int shadingMode();
        int ambientLight();
        QString backgroundColor();

    public slots:
        void setFullscreen(int fullscreen);
        void setShadingMode(int value);
        void setAmbientLight(int value);
        void setBackgroundColor(QString color);
        void save();
        void reset();

    private:
        QSettings *m_settings;

        bool m_fullscreen;
        int m_shadingMode;
        int m_ambientLight;
        QString m_backgroundColor;
};

#endif
