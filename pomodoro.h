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
    QLabel      *sessionNumber;

    QLabel      *sessionLabel;
    QLabel      *restLabel;
    QLineEdit   *sessionTime;
    QLineEdit   *restTime;

    QPushButton *applyButton;

    // Other objects and variables
    QTimer *counter;

    // Groups
    QGroupBox   *settingsGroup;
    QVBoxLayout *settingsGroupLayout;

    //Layouts
    QHBoxLayout *buttonsLayout;
    QHBoxLayout *timerLayout;
    QGridLayout *settingsLayout;
    QVBoxLayout *mainLayout;
    QVBoxLayout *infoLayout;
    QHBoxLayout *applyLayout;

    // System tray
    QSystemTrayIcon *sysIcon;
    QMenu       *sysIconMenu;

    // Actions on the app
    QAction     *showAction;
    QAction     *quitAction;


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

private slots:
    void startPomodoro();
    void stopPomodoro();
    void resetPomodoro();
    void secondPassed();

    void nextSession();
    void updateSessionCount();
    void updateSessiontype();
    void applyChanges();

    void quitResponse();
    void showResponse();

signals:
    void sessionEnd();
    void sessionCountChanged();
    void sessionTypeChanged();
    void quitApp();
    void showApp();
};

#endif // POMODORO_H
