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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../simulator/GLViewer.h"
#include "configdialog.h"
#include "controlswidget.h"
#include "datatrees.h"
#include "informationsbox.h"
#include "logwidget.h"
#include "programsettings.h"

#include <QGroupBox>
#include <QListWidget>
#include <QMainWindow>
#include <QRadioButton>
#include <QToolBox>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <QWidget>
#include <QtGui>

#include <time.h>

class QAction;
class QMenu;

class MainWindow : public QMainWindow {
        Q_OBJECT

    public:
        MainWindow();
        ~MainWindow();

    protected:
        void closeEvent(QCloseEvent* event);

    private slots:
        void slotLoadSim();
        void slotReset();
        void slotAbout();
        void slotOpenConfigBox();
        void slotToggleFullScreen();

    private:
        void createActions();
        void createMenus();
        void createToolBars();
        void createStatusBar();
        void createDocks();
        void loadFile(const QString &fileName);
        void setCurrentFile(const QString &fileName);
        QString strippedName(const QString &fullFileName);

        //Le widget OpenGL
        Viewer*             m_glViewer;

        //Widget, dock et fonctions de la console
        QDockWidget*        m_logDock;
        LogWidget*          m_logWidget;

        //Dock data
        QDockWidget*        m_dataTreesDock;
        DataTrees*          m_dataTrees;

        //Dock d'infos
        QDockWidget*        m_infoDock;
        InformationsBox*    m_infos;

        //Dock et widget du contrôleur
        QDockWidget*        m_controlsDock;
        ControlsWidget*     m_controlsWidget;

        QString             m_currentFile;

        //Menus
        QMenu*              m_systemMenu;
        QMenu*              m_simMenu;
        QMenu*              m_optionsMenu;
        QMenu*              m_helpMenu;

        //Toolbars
        QToolBar*           m_simToolBar;

        //File menu actions
        QAction*            m_resetAct;
        QAction*            m_exitAct;

        //Sim menu actions
        QAction*            m_loadSimAct;
        QAction*            m_runSimAct;
        QAction*            m_restartSimAct;
        QAction*            m_resetSimAct;
        QAction*            m_stopSimAct;

        //Options menu actions
        QAction*            m_fullscreenAct;
        QAction*            m_programConfigAct;
        //QAction*          m_simConfigAct;
        ProgramSettings*    m_settings;

        //Help menu actions
        QAction*            m_aboutAct;
        QAction*            m_aboutQtAct;
};

#endif
