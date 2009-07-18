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
    : m_glViewer(new Viewer)
{
    ProgramSettings settings;
    setMinimumSize(800, 500);

    //J'adore ce petit bout de code...je veux ca en poster...well done max :P
    if (settings.value("window/fullscreen").toBool())
        showFullScreen();

    setCentralWidget(m_glViewer);

    createActions();
    createMenus();
    createToolBars();
    createStatusBar();
    createDocks();

    connect(m_glViewer, SIGNAL(sigMsg(QString)), m_logWidget, SLOT(slotMsg(QString)));

    m_infos->setViewerPointer(m_glViewer);
    connect(m_glViewer, SIGNAL(drawFinished(bool)), m_infos, SLOT(refreshBox(bool)));

    // Originalement pour savoir si un document a été modifié. Changer pour voir si simulation en cours.
    // connect(textEdit->document(), SIGNAL(contentsChanged()), this, SLOT(documentWasModified()));
    setCurrentFile("");
}


MainWindow::~MainWindow()
{
}


void MainWindow::closeEvent(QCloseEvent* event)
{
    //Si une simulation est en cours, il faut une confirmation pour quitter.
    if (m_glViewer->isStarted()) {
        int quit = QMessageBox::warning(this, QString(tr("Error")),
                                        QString(tr("A simulation is running.\n Do you really want to quit ?")),
                                        QMessageBox::Yes | QMessageBox::No);

        if (quit == QMessageBox::Yes) {
            m_glViewer->stop();
            event->accept();
        } else
            event->ignore();
    } else
        event->accept();
}


void MainWindow::slotLoadSim()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load Simulation"),
                                                    ".", tr("Lua Files (*.lua)"));

    if (!fileName.isEmpty())
        loadFile(fileName);
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
    m_resetAct = new QAction(QIcon(":/images/control_repeat_blue.png"), tr("&Reset"), this);
    m_resetAct->setShortcut(tr("Ctrl+R"));
    m_resetAct->setStatusTip(tr("Reset the program."));
    connect(m_resetAct, SIGNAL(triggered()), this, SLOT(slotReset()));

    m_exitAct = new QAction(QIcon(":/images/door_in.png"), tr("E&xit"), this);
    m_exitAct->setShortcut(tr("Ctrl+Q"));
    m_exitAct->setStatusTip(tr("Leave the simulator"));
    connect(m_exitAct, SIGNAL(triggered()), this, SLOT(close()));

    m_loadSimAct = new QAction(QIcon(":/images/folder_page_white.png"), tr("&Load..."), this);
    m_loadSimAct->setShortcut(tr("Ctrl+L"));
    m_loadSimAct->setStatusTip(tr("Load a simulation"));
    connect(m_loadSimAct, SIGNAL(triggered()), this, SLOT(slotLoadSim()));

    m_runSimAct = new QAction(QIcon(":/images/control_play_blue.png"), tr("&Run"), this);
    m_runSimAct->setShortcut(tr("Ctrl+R"));
    m_runSimAct->setStatusTip(tr("Run the simulation"));
    connect(m_runSimAct, SIGNAL(triggered()), m_glViewer, SLOT(start()));

    m_restartSimAct = new QAction(QIcon(":/images/control_repeat_blue.png"), tr("R&estart"), this);
    m_restartSimAct->setStatusTip(tr("Restart the simulation"));
    connect(m_restartSimAct, SIGNAL(triggered()), m_glViewer, SLOT(restart()));

    m_resetSimAct = new QAction(QIcon(":/images/control_start_blue.png"), tr("Re&set"), this);
    m_resetSimAct->setStatusTip(tr("Reset the simulation"));
    connect(m_resetSimAct, SIGNAL(triggered()), m_glViewer, SLOT(reset()));

    m_stopSimAct = new QAction(QIcon(":/images/control_stop_blue.png"), tr("S&top"), this);
    m_stopSimAct->setShortcut(tr("Ctrl+T"));
    m_stopSimAct->setStatusTip(tr("Stop the simulation"));
    connect(m_stopSimAct, SIGNAL(triggered()), m_glViewer, SLOT(stop()));

    // Actions menu Options
    m_fullscreenAct = new QAction(QIcon(":/images/monitor.png"), tr("&Fullscreen"), this);
    m_fullscreenAct->setShortcut(tr("Ctrl+F"));
    m_fullscreenAct->setStatusTip(tr("Switch to fullscreen mode"));
    connect(m_fullscreenAct, SIGNAL(triggered()), this, SLOT(slotToggleFullScreen()));

    m_programConfigAct = new QAction(QIcon(":/images/cog.png"), tr("Program Settings"), this);
    m_programConfigAct->setShortcut(tr("Ctrl+P"));
    m_programConfigAct->setStatusTip(tr("Configure program settings"));
    connect(m_programConfigAct, SIGNAL(triggered()), this, SLOT(slotOpenConfigBox()));

    // m_simConfigAct = new QAction(QIcon(":/images/script_gear.png"), tr("Configure simulation"), this);
    // m_simConfigAct->setStatusTip(tr("Configure the simulation files"));
    // connect(m_simConfigAct, SIGNAL(triggered()), this, SLOT(openConfigBox()));

    m_aboutAct = new QAction(QIcon(":/images/comment.png"), tr("&About"), this);
    m_aboutAct->setStatusTip(tr("About the simulator"));
    connect(m_aboutAct, SIGNAL(triggered()), this, SLOT(slotAbout()));

    m_aboutQtAct = new QAction(tr("About &Qt"), this);
    m_aboutQtAct->setStatusTip(tr("About Qt"));
    connect(m_aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}


void MainWindow::createMenus()
{
    m_systemMenu = menuBar()->addMenu(tr("&System"));
    m_systemMenu->addAction(m_resetAct);
    m_systemMenu->addSeparator();
    m_systemMenu->addAction(m_exitAct);

    m_simMenu = menuBar()->addMenu(tr("S&imulation"));
    m_simMenu->addAction(m_loadSimAct);
    m_simMenu->addAction(m_runSimAct);
    m_simMenu->addAction(m_restartSimAct);
    m_simMenu->addAction(m_resetSimAct);
    m_simMenu->addAction(m_stopSimAct);

    m_simMenu = menuBar()->addMenu(tr("&Options"));
    m_simMenu->addAction(m_fullscreenAct);
    m_simMenu->addAction(m_programConfigAct);
    // m_simMenu->addAction(m_simConfigAct);

    menuBar()->addSeparator();

    m_helpMenu = menuBar()->addMenu(tr("&Help"));
    m_helpMenu->addAction(m_aboutAct);
    m_helpMenu->addAction(m_aboutQtAct);
}


void MainWindow::createToolBars()
{
    m_simToolBar = addToolBar(tr("Simulation"));
    m_simToolBar->addAction(m_loadSimAct);
    m_simToolBar->addAction(m_runSimAct);
    m_simToolBar->addAction(m_restartSimAct);
    m_simToolBar->addAction(m_resetSimAct);
    m_simToolBar->addAction(m_stopSimAct);
}


void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready to roll"));
}


void MainWindow::createDocks()
{
    setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);

    m_logWidget = new LogWidget;
    m_logWidget->setMaximumHeight(100);
    m_logWidget->newMsg(QString("The simulator is up and ready to roll..."));

    m_logDock = new QDockWidget(tr("Console"), this);
    m_logDock->setWidget(m_logWidget);
    addDockWidget(Qt::BottomDockWidgetArea, m_logDock);

    m_dataTrees = new DataTrees();
    m_dataTreesDock = new QDockWidget(tr("Data Trees"), this);
    m_dataTreesDock->setWidget(m_dataTrees);
    addDockWidget(Qt::RightDockWidgetArea, m_dataTreesDock);

    m_infos = new InformationsBox;
    m_infoDock = new QDockWidget(tr("Data Dock"), this);
    m_infoDock->setWidget(m_infos);
    addDockWidget(Qt::RightDockWidgetArea, m_infoDock);

    QObject::connect(m_dataTrees->mainTree(), SIGNAL(itemClicked(QTreeWidgetItem*, int)),
                     m_infos, SLOT(setCurrentItem(QTreeWidgetItem*, int)));
    QObject::connect(m_dataTrees->simTree(), SIGNAL(itemClicked(QTreeWidgetItem*, int)),
                     m_infos, SLOT(setCurrentItem(QTreeWidgetItem*, int)));

    m_controlsWidget = new ControlsWidget;
    m_controlsDock = new QDockWidget(tr("Controls"), this);
    m_controlsDock->setWidget(m_controlsWidget);
    addDockWidget(Qt::RightDockWidgetArea, m_controlsDock);
}


void MainWindow::loadFile(const QString &fileName)
{
    m_logWidget->newMsg("You chose: " + fileName);
}


void MainWindow::setCurrentFile(const QString &fileName)
{
    return;
}


QString MainWindow::strippedName(const QString &fullFileName)
{
    // Apparement cette partie donne uniquement le nom du ficher.
    // Utile pour la barre de status et le titre.
    return QFileInfo(fullFileName).fileName();
}


void MainWindow::slotToggleFullScreen()
{
    (isFullScreen()) ? showNormal() : showFullScreen();
}
