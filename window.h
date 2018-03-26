#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include "pomodoro.h"

class Window : public QMainWindow
{
private:
    // Menu
    QMenu   *fileMenu;
    QMenu   *aboutMenu;

    // Actions
    QAction *quitAction;
    QAction *settingsAction;
    QAction *aboutAction;

public:
    Window(QObject *parent = 0);

    // Methods
    void createActions();
    void createMenus();

private slots:
    void openSettings();

};

#endif // WINDOW_H
