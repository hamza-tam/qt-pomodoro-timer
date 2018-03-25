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

    //Layouts
    QHBoxLayout *buttonsLayout;
    QHBoxLayout *timerLayout;
    QGridLayout *settingsLayout;
    QVBoxLayout *mainLayout;
    QVBoxLayout *infoLayout;
    QHBoxLayout *applyLayout;

    // Methods
    void createLayout();
    void initializeTimer();
    void updateTimer();
    void setVariables();

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

signals:
    void sessionEnd();
    void sessionCountChanged();
    void sessionTypeChanged();
};

#endif // POMODORO_H
