#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include "pomodoro.h"
#include "settings.h"

class Window : public QMainWindow
{
    Q_OBJECT

private:
    // Pomodoro
    Pomodoro *pomodoro;

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
};

#endif // WINDOW_H
