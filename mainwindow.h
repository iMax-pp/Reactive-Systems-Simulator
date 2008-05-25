#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QWidget>

class QAction;
class QMenu;
class GLWidget;

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

private:
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void createDocks(); //Ajoute les parties docks
    void readSettings();
    void writeSettings();
    bool maybeSave();
    void loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);

    //Le widget OpenGL
    GLWidget *glWidget;
    
    //Widget, dock et fonctions de la console
    QDockWidget *consoleDock;
    QListWidget *console;
    void toConsole(const QString &message);

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
    QAction *simConfigAct;
    
    //Help menu actions
    QAction *aboutAct;
    QAction *aboutQtAct;
};

#endif
