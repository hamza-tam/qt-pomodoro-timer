#include "window.h"

Window::Window(QObject *parent) : QMainWindow()
{
    // Adding the pomodoro
    pomodoro = new Pomodoro;
    this->setCentralWidget(pomodoro);

    // adding menus
    createActions();
    createMenus();
    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(aboutMenu);

    menuBar()->setStyleSheet("color: #fff");

    setStyleSheet("background-color: #130f40");
    setWindowTitle("Pomodoro");

    // Events
    connect(pomodoro, SIGNAL(quitApp()), this, SLOT(close()));
    connect(pomodoro, SIGNAL(showApp()), this, SLOT(showNormal()));
}

void Window::createActions()
{
    quitAction = new QAction(tr("Quit"));
    connect(quitAction, SIGNAL(triggered(bool)), this, SLOT(close()));

    settingsAction = new QAction(tr("Settings"));
    connect(settingsAction, SIGNAL(triggered(bool)), pomodoro, SLOT(openSettings()));

    aboutAction = new QAction(tr("About"));
    // connect ?
}

void Window::createMenus()
{
    fileMenu = new QMenu(tr("File"));
    fileMenu->addAction(settingsAction);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAction);

    aboutMenu = new QMenu("About");
    aboutMenu->addAction(aboutAction);
}
