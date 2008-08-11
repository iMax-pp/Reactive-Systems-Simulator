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

#include "consolewidget.h"
#include "controlswidget.h"
#include "datatrees.h"
#include "informationsbox.h"
#include "configdialog.h"
#include "../simulator/GLViewer.h"
#include "../lua/luaEngines.h"

class QAction;
class QMenu;
//class GLViewer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void newSim();
    void open();
    bool save();
    bool saveAs();
    void about();
    void documentWasModified();
	void openConfigBox();
	void toggleFullScreen();

private:
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void createDocks(); //Ajoute les parties docks
    bool maybeSave();
    void loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);

    //Le widget OpenGL
    Viewer *glViewer;
    
    //Widget, dock et fonctions de la console
    QDockWidget *consoleDock;
    ConsoleWidget *consoleWidget;
    
	//Dock data
	QDockWidget *dataTreesDock;
	DataTrees *dataTrees;
	
	//Dock d'infos
	QDockWidget *infoDock;
	InformationsBox *infos;
    
	//Dock et widget du contrôleur
    QDockWidget *controlsDock;
    ControlsWidget *controlsWidget;

    QString curFile;

	//Menus
    QMenu *fileMenu;
    QMenu *simMenu;
    QMenu *optionsMenu;
    QMenu *helpMenu;
    
    //Toolbars
    QToolBar *fileToolBar;
    QToolBar *simToolBar;

	//File menu actions
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *exitAct;
    
    //Sim menu actions
    QAction *runSimAct;
	QAction *restartSimAct;
    QAction *resetSimAct;
    QAction *stopSimAct;

    //Options menu actions
    QAction *fullscreenAct;
    QAction *programConfigAct;
    //QAction *simConfigAct;
    
    //Help menu actions
    QAction *aboutAct;
    QAction *aboutQtAct;
};

#endif
