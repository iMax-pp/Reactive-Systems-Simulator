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

MainWindow::MainWindow()
{
	ProgramSettings settings;
	
	setMinimumSize(800,500);
	
	//J'adore ce petit bout de code...je veux ça en poster...well done max :P
	if(settings.value("window/fullscreen").toBool())
	{ showFullScreen(); }

	
    createActions();
    createMenus();
    createToolBars();
    createStatusBar();
    createDocks(); //Ajoute les parties docks

    glViewer = new Viewer;
    glViewer->setConsole(consoleWidget);
    //glViewer->setInfos(infos);
    setCentralWidget(glViewer);
	
	infos->setViewerPointer(glViewer);
	connect(glViewer, SIGNAL(sceneRefresh()), infos, SLOT(refreshBox()));
	connect(runSimAct, SIGNAL(triggered()), glViewer, SLOT(startAnimation()));
	connect(stopSimAct, SIGNAL(triggered()), glViewer, SLOT(stopAnimation()));
	connect(restartSimAct, SIGNAL(triggered()), glViewer, SLOT(restart()));
	connect(resetSimAct, SIGNAL(triggered()), glViewer, SLOT(reset()));

	//Originalement pour savoir si un document a été modifié. Changer pour voir si simulation en cours.
    //connect(textEdit->document(), SIGNAL(contentsChanged()), this, SLOT(documentWasModified()));

    setCurrentFile("");
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	//Si une simulation est en cours, il faut une confirmation pour quitter.
    if (maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::newSim()
{
	//Idem que pour le faite de quitter, on doit confirmer, mais en faite ça servira peut-être pas.
	/*
    if (maybeSave()) {
        textEdit->clear();
        setCurrentFile("");
    }
    */
}

void MainWindow::open()
{
	//De novo Idem, sauf que cette version servira surement.
    /*
    if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty())
            loadFile(fileName);
    }
    */
}

bool MainWindow::save()
{
	//A voir. Si la simulation est nouvelle, on fait un saveAs.
	//Et à priori sauvegarder voudra juste dire sauvegarder les données de la simulation et son état, pas la simulation elle même, puisqu'on aura pas la possibilité d'éditer.
	/*
    if (curFile.isEmpty()) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
    */
}

bool MainWindow::saveAs()
{
	// cf MainWindow::save()
	/*
    QString fileName = QFileDialog::getSaveFileName(this);
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);
    */
}

void MainWindow::about()
{
   QMessageBox::about(this, tr("About Application"),
            tr("<p>The <b>Reactive Systems Simulator</b>: a total recoding of the CSR Project, with ameliorated GUI and environment, functionality, speed and more.</p>"
               "<p>Compatible with Linux, MacOS and Windows, and any other system capable of compiling C++ code with Qt4, OpenGL and Lua.</p>"
               "<p>This program is open source and released under the GNU General Public License.</p>"
               "<p>The icons used are from the FamFamFam `Silk' icons collection: <a href='http://www.famfamfam.com/lab/icons/silk/'>http://www.famfamfam.com/lab/icons/silk/</a></p>"
               "<p>For more info visit <a href='http://code.google.com/p/projet-csr-cpp/'>http://code.google.com/p/projet-csr-cpp</a>.</p>"));
}

void MainWindow::documentWasModified()
{
	// A remplacer...par une sorte de bool pour l'état de marche de la simulation.
	/*
    setWindowModified(textEdit->document()->isModified());
    */
}

void MainWindow::openConfigBox()
{
	ConfigDialog dialog;
	dialog.exec();
}

void MainWindow::createActions()
{
	//Actions menu File
	//Je nous vois mal écrire un truc pour fabriquer des simulations pour le moment
	/*
    newAct = new QAction(QIcon(":/images/script.png"), tr("&New"), this);
    newAct->setShortcut(tr("Ctrl+N"));
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
	*/

    openAct = new QAction(QIcon(":/images/folder_page_white.png"), tr("&Open..."), this);
    openAct->setShortcut(tr("Ctrl+O"));
    openAct->setStatusTip(tr("Load a simulation"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    saveAct = new QAction(QIcon(":/images/script_save.png"), tr("&Save"), this);
    saveAct->setShortcut(tr("Ctrl+S"));
    saveAct->setStatusTip(tr("Save current simulation data and state"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    saveAsAct = new QAction(tr("Save &As..."), this);
    saveAsAct->setStatusTip(tr("Save current simulation data and state under a new name"));
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

    exitAct = new QAction(QIcon(":/images/door_in.png"), tr("E&xit"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    exitAct->setStatusTip(tr("Leave the simulator"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
    
	//Mise en place provisoire des nouvelles actions, SLOTs et SIGNALs à faire.
	
		//Actions menu Sim
	    runSimAct = new QAction(QIcon(":/images/control_play_blue.png"), tr("&Run"), this);
	    runSimAct->setShortcut(tr("Ctrl+R"));
	    runSimAct->setStatusTip(tr("Run the simulation"));
	
	    restartSimAct = new QAction(QIcon(":/images/control_repeat_blue.png"), tr("R&estart"), this);
	    restartSimAct->setStatusTip(tr("Restart the simulation"));
	
	    resetSimAct = new QAction(QIcon(":/images/control_start_blue.png"), tr("Re&set"), this);
	    resetSimAct->setStatusTip(tr("Reset the simulation"));
	
	    stopSimAct = new QAction(QIcon(":/images/control_stop_blue.png"), tr("S&top"), this);
	    stopSimAct->setShortcut(tr("Ctrl+T"));
	    stopSimAct->setStatusTip(tr("Stop the simulation"));
	
		//Actions menu Options
	    fullscreenAct = new QAction(QIcon(":/images/monitor.png"), tr("&Fullscreen"), this);
	    fullscreenAct->setShortcut(tr("Ctrl+F"));
	    fullscreenAct->setStatusTip(tr("Switch to fullscreen mode"));
		connect(fullscreenAct, SIGNAL(triggered()), this, SLOT(toggleFullScreen()));
	
	    programConfigAct = new QAction(QIcon(":/images/cog.png"), tr("Program Settings"), this);
		programConfigAct->setShortcut(tr("Ctrl+P"));
	    programConfigAct->setStatusTip(tr("Configure program settings"));
		connect(programConfigAct, SIGNAL(triggered()), this, SLOT(openConfigBox()));

	
//	    simConfigAct = new QAction(QIcon(":/images/script_gear.png"), tr("Configure simulation"), this);
//	    simConfigAct->setStatusTip(tr("Configure the simulation files"));
//		connect(simConfigAct, SIGNAL(triggered()), this, SLOT(openConfigBox()));


	//Action menu Help
    aboutAct = new QAction(QIcon(":/images/comment.png"), tr("&About"), this);
    aboutAct->setStatusTip(tr("About the simulator"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("About Qt"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

	//Commentés pour le moment, c'est pas utile.
	//Ou alors pour donner la capacité de copier les données courantes dans le presse-machin
	/*
    cutAct->setEnabled(false);
    copyAct->setEnabled(false);
    connect(textEdit, SIGNAL(copyAvailable(bool)),
            cutAct, SLOT(setEnabled(bool)));
    connect(textEdit, SIGNAL(copyAvailable(bool)),
            copyAct, SLOT(setEnabled(bool)));
    */
}

void MainWindow::createMenus()
{
	//Creation des menus :P
	//File menu
    fileMenu = menuBar()->addMenu(tr("&File"));
    //fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

	//Sim menu
    simMenu = menuBar()->addMenu(tr("&Simulation"));
    simMenu->addAction(runSimAct);
    simMenu->addAction(restartSimAct);
    simMenu->addAction(resetSimAct);
    simMenu->addAction(stopSimAct);

	//Options menu
    simMenu = menuBar()->addMenu(tr("&Options"));
    simMenu->addAction(fullscreenAct);
    simMenu->addAction(programConfigAct);
    //simMenu->addAction(simConfigAct);

    menuBar()->addSeparator();

	//Help menu
    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}

void MainWindow::createToolBars()
{
	//Creation des toolbars
    fileToolBar = addToolBar(tr("File"));
    //fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);

    simToolBar = addToolBar(tr("Simulation"));
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
	
	//Création de la console
	consoleDock = new QDockWidget(tr("Console"), this);
	consoleDock->setAllowedAreas(Qt::BottomDockWidgetArea);
	addDockWidget(Qt::BottomDockWidgetArea, consoleDock);
	consoleWidget = new ConsoleWidget;
	consoleDock->setWidget(consoleWidget);	
	consoleWidget->newMsg(QString("The simulator is up and ready to roll..."));
	
	consoleWidget->setMaximumHeight(100);
	
	// Dock de liste des informations disponibles
	dataTreesDock = new QDockWidget(tr("Data Trees"), this);
	addDockWidget(Qt::RightDockWidgetArea, dataTreesDock);
	dataTrees = new DataTrees();
	dataTreesDock->setWidget(dataTrees);

	// Dock d'affichage des informations
	infoDock = new QDockWidget(tr("Data Dock"), this);
	infoDock->setAllowedAreas(Qt::BottomDockWidgetArea
								 | Qt::TopDockWidgetArea);
	addDockWidget(Qt::RightDockWidgetArea, infoDock);
		
	infos = new InformationsBox;
	infoDock->setWidget(infos);
	QObject::connect(dataTrees->getMainTree(), SIGNAL(itemClicked(QTreeWidgetItem*, int)), infos, SLOT(setCurrentItem(QTreeWidgetItem*, int)));
	QObject::connect(dataTrees->getSimTree(), SIGNAL(itemClicked(QTreeWidgetItem*, int)), infos, SLOT(setCurrentItem(QTreeWidgetItem*, int)));	
	//Création du dock de contrôle
	controlsDock = new QDockWidget(tr("Controls"), this);
	controlsDock->setAllowedAreas(Qt::LeftDockWidgetArea
	                              | Qt::RightDockWidgetArea);
	addDockWidget(Qt::RightDockWidgetArea, controlsDock);
	
	controlsWidget = new ControlsWidget;
	controlsDock->setWidget(controlsWidget);
	
	//connections
	//QObject::connect(listItems, SIGNAL(itemClicked(QTreeWidgetItem*,int)),infos,SLOT(setInfoText(QTreeWidgetItem*,int)));
	//QObject::connect(glWidget, SIGNAL(consoleMsg(QString)), consoleWidget, SLOT(sendMsg(QString)));
}

bool MainWindow::maybeSave()
{
	//Pas encore implémenté :P
	//Regarde si une simulation est en chargée, si oui on peut sauvegarder les données et son état.
	/*
    if (textEdit->document()->isModified()) {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("Application"),
                     tr("The document has been modified.\n"
                        "Do you want to save your changes?"),
                     QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (ret == QMessageBox::Save)
            return save();
        else if (ret == QMessageBox::Cancel)
            return false;
    }
    */
    return true;
}

void MainWindow::loadFile(const QString &fileName)
{
	//Chargement d'un fichier de simulation Lua ici
	/*
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    textEdit->setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);
    */
}

bool MainWindow::saveFile(const QString &fileName)
{
	// Pas si simple que ça...
	// Faudrait sauvegarder les données de la simulation et son état.
	/*
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << textEdit->toPlainText();
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    */
    return true;
}

void MainWindow::setCurrentFile(const QString &fileName)
{
	// Fonctionalité change pas, elle garde en mémoire le nom de fichier de la simulation en cours.
	/*
    curFile = fileName;
    textEdit->document()->setModified(false);
    setWindowModified(false);

    QString shownName;
    if (curFile.isEmpty())
        shownName = "untitled.txt";
    else
        shownName = strippedName(curFile);

    setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(tr("Application")));
    */
}

QString MainWindow::strippedName(const QString &fullFileName)
{
	//Apparement cette partie donne uniquement le nom du ficher. Utile pour la barre de status et le titre.
    return QFileInfo(fullFileName).fileName();
}

void MainWindow::toggleFullScreen()
{
	// C'est toi qui as codé ça Max?
	if(!isFullScreen())
		{showFullScreen();}
	else
		{showNormal();}
}
