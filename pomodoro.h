#ifndef POMODORO_H
#define POMODORO_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QLineEdit>
#include <QGridLayout>
#include <QGroupBox>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>

#include "default.h"
#include "settings.h"
#include "about.h"

class Pomodoro : public QWidget {

    Q_OBJECT

public:
    Pomodoro(QWidget *parent = 0);

private:
    // Application variables
    bool workSession;
    int sessionCount;
    int timeElapsed;
    int session;
    int rest;
    int stop;

    // Ui components
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *resetButton;

    QLabel      *timer;

    QLabel      *sessionType;

    // Other objects and variables
    QTimer *counter;

    // Groups
    QGroupBox   *settingsGroup;
    QVBoxLayout *settingsGroupLayout;

    //Layouts
    QHBoxLayout *buttonsLayout;
    QHBoxLayout *timerLayout;
    QVBoxLayout *mainLayout;
    QVBoxLayout *infoLayout;

    // System tray
    QSystemTrayIcon *sysIcon;
    QMenu       *sysIconMenu;

    // Actions on the app
    QAction     *showAction;
    QAction     *quitAction;

    Settings    *settings;
    About       *about;


    // Methods
    void createLayout();
    void initializeTimer();
    void updateTimer();
    void setVariables();
    void createTrayIcon();
    void createActions();

    // Tray Methods
    void workStartMessage();
    void restStartMessage();

    QString getTime();

public:
    // Getters
    int* getSessionPointer();
    int* getRestPointer();

private slots:
    void startPomodoro();
    void stopPomodoro();
    void resetPomodoro();
    void secondPassed();

    void nextSession();
    void updateSessiontype();
    void applyChanges();

    void quitResponse();
    void showResponse();

    void openSettings();
    void openAbout();

signals:
    void sessionEnd();
    void sessionTypeChanged();
    void quitApp();
    void showApp();
};

#endif // POMODORO_H
