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

#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include "programsettings.h"

#include <QDialog>
#include <QWidget>
#include <QtGui>

class QListWidget;
class QListWidgetItem;
class QStackedWidget;

// Partie Pages de configuration

class ConfigurationPage : public QWidget {
        Q_OBJECT

    public:
        ConfigurationPage(ProgramSettings*);
        void reset(ProgramSettings*);

    private:
        QCheckBox* m_fullscreenCheckBox;
};

class OpenGLPage : public QWidget {
        Q_OBJECT

    public:
        OpenGLPage(ProgramSettings*);
        void reset(ProgramSettings*);

    private:
        QSpinBox* m_shadingmode;
        QSpinBox* m_ambientlight;
        QComboBox* m_backgroundcolor;
};


// Partie boîte de configuration

class ConfigDialog : public QDialog {
        Q_OBJECT

    public:
        ConfigDialog(ProgramSettings*);

    public slots:
        void changePage(QListWidgetItem* current, QListWidgetItem* previous);
        void apply();
        void revert();

    private:
        void createIcons();

        QListWidget* m_contentsWidget;
        QStackedWidget* m_pagesWidget;
        ProgramSettings* m_settings;
        ConfigurationPage* m_configurationPage;
        OpenGLPage* m_openGLPage;
};

#endif
