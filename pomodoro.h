#ifndef POMODORO_H
#define POMODORO_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>


class Pomodoro : public QWidget
{
public:
    Pomodoro(QWidget *parent = 0);

private:
    // Ui components
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *resetButton;
    QLabel *timer;

    //Layouts
    QHBoxLayout *buttonsLayout;
    QHBoxLayout *timerLayout;
    QVBoxLayout *mainLayout;

    // Methods
    void createLayout();

private slots:
    void startTimer();
};

#endif // POMODORO_H
