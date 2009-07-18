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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <time.h>
#include <QtGui>
#include <QMainWindow>
#include <QListWidget>
#include <QToolBox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QWidget>
#include <QTreeWidget>

#include "logwidget.h"
#include "controlswidget.h"
#include "datatrees.h"
#include "informationsbox.h"
#include "configdialog.h"
#include "../simulator/GLViewer.h"

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

        //Help menu actions
        QAction*            m_aboutAct;
        QAction*            m_aboutQtAct;
};

#endif
