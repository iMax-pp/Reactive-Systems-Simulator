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

#include "mainwindow.h"
#define TODOMSG QMessageBox::information( this, tr("ToDo"), tr("This actions has yet to be implemented"), QMessageBox::Ok );

MainWindow::MainWindow()
{
    ProgramSettings settings;

    setMinimumSize(800,500);

    //J'adore ce petit bout de code...je veux ca en poster...well done max :P
    if(settings.value("window/fullscreen").toBool())
        showFullScreen();

    glViewer = new Viewer;
    setCentralWidget(glViewer);

    createActions();
    createMenus();
    createToolBars();
    createStatusBar();
    createDocks();

    connect( glViewer, SIGNAL( sigMsg(QString) ), logWidget, SLOT( slotMsg(QString) ) );

    infos->setViewerPointer(glViewer);
    connect(glViewer, SIGNAL(drawFinished(bool)), infos, SLOT(refreshBox(bool)));

    //Originalement pour savoir si un document a été modifié. Changer pour voir si simulation en cours.
    //connect(textEdit->document(), SIGNAL(contentsChanged()), this, SLOT(documentWasModified()));

    setCurrentFile("");
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    //Si une simulation est en cours, il faut une confirmation pour quitter.
    if( glViewer->isStarted() )
    {
        int quit = QMessageBox::warning(this, QString(tr("Error")),
                                        QString(tr("A simulation is running.\n Do you really want to quit ?")),
                                        QMessageBox::Yes | QMessageBox::No);

        if(quit == QMessageBox::Yes)
        {
            glViewer->stop();
            event->accept();
        }
        else
        {
            event->ignore();
        }
    }
    else
    {
        event->accept();
    }
}


void MainWindow::slotLoadSim()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                            tr("Load Simulation"), ".", tr("Lua Files (*.lua)"));
    if( !fileName.isEmpty() )
    {
        loadFile( fileName );
    }
}

void MainWindow::slotReset()
{
    TODOMSG
}

void MainWindow::slotAbout()
{
   QMessageBox::about(this, tr("About Application"),
            tr("<p>The <b>Reactive Systems Simulator</b>: a total recoding of the CSR Project, with ameliorated GUI and environment, functionality, speed and more.</p>"
               "<p>Compatible with Linux, MacOS and Windows, and any other system capable of compiling C++ code with Qt4, OpenGL and Lua.</p>"
               "<p>This program is open source and released under the GNU General Public License.</p>"
               "<p>The icons used are from the FamFamFam `Silk' icons collection: <a href='http://www.famfamfam.com/lab/icons/silk/'>http://www.famfamfam.com/lab/icons/silk/</a></p>"
               "<p>For more info visit <a href='http://code.google.com/p/projet-csr-cpp/'>http://code.google.com/p/projet-csr-cpp</a>.</p>"));
}


void MainWindow::slotOpenConfigBox()
{
    ConfigDialog dialog;
    dialog.exec();
}


void MainWindow::createActions()
{
    resetAct = new QAction(QIcon(":/images/control_repeat_blue.png"), tr("&Reset"), this);
    resetAct->setShortcut(tr("Ctrl+R"));
    resetAct->setStatusTip(tr("Reset the program."));
    connect(resetAct, SIGNAL(triggered()), this, SLOT(slotReset()));

    exitAct = new QAction(QIcon(":/images/door_in.png"), tr("E&xit"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    exitAct->setStatusTip(tr("Leave the simulator"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    loadSimAct = new QAction(QIcon(":/images/folder_page_white.png"), tr("&Load..."), this);
    loadSimAct->setShortcut(tr("Ctrl+L"));
    loadSimAct->setStatusTip(tr("Load a simulation"));
    connect(loadSimAct, SIGNAL(triggered()), this, SLOT(slotLoadSim()));

    runSimAct = new QAction(QIcon(":/images/control_play_blue.png"), tr("&Run"), this);
    runSimAct->setShortcut(tr("Ctrl+R"));
    runSimAct->setStatusTip(tr("Run the simulation"));
    connect(runSimAct, SIGNAL(triggered()), glViewer, SLOT(start()));

    restartSimAct = new QAction(QIcon(":/images/control_repeat_blue.png"), tr("R&estart"), this);
    restartSimAct->setStatusTip(tr("Restart the simulation"));
    //connect(restartSimAct, SIGNAL(triggered()), glViewer, SLOT(restart()));

    resetSimAct = new QAction(QIcon(":/images/control_start_blue.png"), tr("Re&set"), this);
    resetSimAct->setStatusTip(tr("Reset the simulation"));
    //connect(resetSimAct, SIGNAL(triggered()), glViewer, SLOT(reset()));

    stopSimAct = new QAction(QIcon(":/images/control_stop_blue.png"), tr("S&top"), this);
    stopSimAct->setShortcut(tr("Ctrl+T"));
    stopSimAct->setStatusTip(tr("Stop the simulation"));
    //connect(stopSimAct, SIGNAL(triggered()), glViewer, SLOT(stop()));

    //Actions menu Options
    fullscreenAct = new QAction(QIcon(":/images/monitor.png"), tr("&Fullscreen"), this);
    fullscreenAct->setShortcut(tr("Ctrl+F"));
    fullscreenAct->setStatusTip(tr("Switch to fullscreen mode"));
    connect(fullscreenAct, SIGNAL(triggered()), this, SLOT(slotToggleFullScreen()));

    programConfigAct = new QAction(QIcon(":/images/cog.png"), tr("Program Settings"), this);
    programConfigAct->setShortcut(tr("Ctrl+P"));
    programConfigAct->setStatusTip(tr("Configure program settings"));
    connect(programConfigAct, SIGNAL(triggered()), this, SLOT(slotOpenConfigBox()));

//	simConfigAct = new QAction(QIcon(":/images/script_gear.png"), tr("Configure simulation"), this);
//	simConfigAct->setStatusTip(tr("Configure the simulation files"));
//	connect(simConfigAct, SIGNAL(triggered()), this, SLOT(openConfigBox()));

    aboutAct = new QAction(QIcon(":/images/comment.png"), tr("&About"), this);
    aboutAct->setStatusTip(tr("About the simulator"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(slotAbout()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("About Qt"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}


void MainWindow::createMenus()
{
    systemMenu = menuBar()->addMenu(tr("&System"));
    systemMenu->addAction(resetAct);
    systemMenu->addSeparator();
    systemMenu->addAction(exitAct);

    simMenu = menuBar()->addMenu(tr("S&imulation"));
    simMenu->addAction(loadSimAct);
    simMenu->addAction(runSimAct);
    simMenu->addAction(restartSimAct);
    simMenu->addAction(resetSimAct);
    simMenu->addAction(stopSimAct);

    simMenu = menuBar()->addMenu(tr("&Options"));
    simMenu->addAction(fullscreenAct);
    simMenu->addAction(programConfigAct);
    //simMenu->addAction(simConfigAct);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}


void MainWindow::createToolBars()
{
    simToolBar = addToolBar(tr("Simulation"));
    simToolBar->addAction(loadSimAct);
    simToolBar->addAction(runSimAct);
    simToolBar->addAction(restartSimAct);
    simToolBar->addAction(resetSimAct);
    simToolBar->addAction(stopSimAct);
}


void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready to roll"));
}


void MainWindow::createDocks()
{
    setCorner(Qt::BottomRightCorner,Qt::RightDockWidgetArea);

    logWidget = new LogWidget;
    logWidget->setMaximumHeight(100);
    logWidget->newMsg(QString("The simulator is up and ready to roll..."));
    logDock = new QDockWidget(tr("Console"), this);
    logDock->setWidget(logWidget);
    addDockWidget(Qt::BottomDockWidgetArea, logDock);


    dataTrees = new DataTrees();
    dataTreesDock = new QDockWidget(tr("Data Trees"), this);
    dataTreesDock->setWidget(dataTrees);
    addDockWidget(Qt::RightDockWidgetArea, dataTreesDock);


    infos = new InformationsBox;
    infoDock = new QDockWidget(tr("Data Dock"), this);
    infoDock->setWidget(infos);
    addDockWidget(Qt::RightDockWidgetArea, infoDock);

    QObject::connect(dataTrees->getMainTree(), SIGNAL(itemClicked(QTreeWidgetItem*, int)),
                     infos, SLOT(setCurrentItem(QTreeWidgetItem*, int)));
    QObject::connect(dataTrees->getSimTree(), SIGNAL(itemClicked(QTreeWidgetItem*, int)),
                     infos, SLOT(setCurrentItem(QTreeWidgetItem*, int)));


    controlsWidget = new ControlsWidget;
    controlsDock = new QDockWidget(tr("Controls"), this);
    controlsDock->setWidget(controlsWidget);
    addDockWidget(Qt::RightDockWidgetArea, controlsDock);
}


void MainWindow::loadFile(const QString &fileName)
{
    logWidget->newMsg( "You chose: " + fileName );
}


void MainWindow::setCurrentFile(const QString &fileName)
{
    return;
}


QString MainWindow::strippedName(const QString &fullFileName)
{
    //Apparement cette partie donne uniquement le nom du ficher. Utile pour la barre de status et le titre.
    return QFileInfo(fullFileName).fileName();
}


void MainWindow::slotToggleFullScreen()
{
    ( isFullScreen() ) ? showNormal() : showFullScreen();
}
