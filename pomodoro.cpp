#include "pomodoro.h"

// Constructor
Pomodoro::Pomodoro(QWidget *parent) : QWidget(parent) {
    createLayout();

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
    timer = new QLabel("text");
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
