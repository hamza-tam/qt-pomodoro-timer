#ifndef POMODORO_H
#define POMODORO_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTimer>

class Pomodoro : public QWidget {

    Q_OBJECT

public:
    Pomodoro(QWidget *parent = 0);

private:
    // Ui components
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *resetButton;
    QLabel *timer;

    // Other objects and variables
    QTimer *counter;
    int timeElapsed;

    //Layouts
    QHBoxLayout *buttonsLayout;
    QHBoxLayout *timerLayout;
    QVBoxLayout *mainLayout;

    // Methods
    void createLayout();
    void initializeTimer();
    void updateTimer();

    QString getTime();

private slots:
    void startPomodoro();
    void stopPomodoro();
    void resetPomodoro();
    void secondPassed();
};

#endif // POMODORO_H
