#include "pomodoro.h"

// Constructor
Pomodoro::Pomodoro(QWidget *parent) : QWidget(parent) {
    timeElapsed = 0;

    createLayout();
    initializeTimer();

    setLayout(mainLayout);
    setWindowTitle("Pomodoro");
}

// Creating Ui components
void Pomodoro::createLayout() {
    // Creating buttons
    startButton = new QPushButton("Start");
    connect(startButton, SIGNAL(clicked()), this, SLOT(startPomodoro()));

    stopButton = new QPushButton("Stop");
    connect(stopButton, SIGNAL(clicked()), this, SLOT(stopPomodoro()));

    resetButton = new QPushButton("Reset");
    connect(resetButton, SIGNAL(clicked()), this, SLOT(resetPomodoro()));

    // Creating the timer text
    timer = new QLabel;
    timer->setText(getTime());
    QFont font;
    font.setPointSize(22);
    timer->setFont(font);

    // Creating layouts
    buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(startButton);
    buttonsLayout->addWidget(stopButton);
    buttonsLayout->addWidget(resetButton);

    timerLayout = new QHBoxLayout;
    timerLayout->addStretch();
    timerLayout->addWidget(timer);
    timerLayout->addStretch();

    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(timerLayout);
    mainLayout->addLayout(buttonsLayout);
}

void Pomodoro::initializeTimer() {
    counter = new QTimer;
    connect(counter, SIGNAL(timeout()), this, SLOT(secondPassed()));
}

void Pomodoro::secondPassed() {
    timeElapsed++;
    updateTimer();
}

void Pomodoro::updateTimer() {
    timer->setText(getTime());
}

void Pomodoro::startPomodoro() {
    counter->start(1000);
}

void Pomodoro::stopPomodoro() {
    counter->stop();
}

void Pomodoro::resetPomodoro() {
    timeElapsed = 0;
    updateTimer();
}

// Formating time string
QString Pomodoro::getTime() {
    int sec = timeElapsed % 60;
    int min = timeElapsed / 60;

    QString sec_string;
    if (sec < 10) sec_string = "0" + QString::number(sec);
    else sec_string = QString::number(sec);

    QString min_string;
    if (min < 10) min_string = "0" + QString::number(min);
    else min_string = QString::number(min);

    return min_string + " : " + sec_string;
}
