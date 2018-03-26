#include "pomodoro.h"

// Constructor
Pomodoro::Pomodoro(QWidget *parent) : QWidget(parent) {
    // Intialising some variables:
    setVariables();
    // Starting the app
    createLayout();
    initializeTimer();

    createActions();

    createTrayIcon();


    // Events
    connect(this, SIGNAL(sessionEnd()), this, SLOT(nextSession()));
    connect(this, SIGNAL(sessionCountChanged()), this, SLOT(updateSessionCount()));
    connect(this, SIGNAL(sessionTypeChanged()), this, SLOT(updateSessiontype()));


    setLayout(mainLayout);
    setWindowTitle("Pomodoro");

    sysIcon->show();
}

// Setting application variables
void Pomodoro::setVariables() {
    workSession  = true;
    sessionCount = 0;
    session      = 1;
    rest         = 1;
    timeElapsed  = 0;
    stop         = session * 60;
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

    applyButton = new QPushButton("Apply");
    connect(applyButton, SIGNAL(clicked(bool)), this, SLOT(applyChanges()));

    // Creating the timer text
    timer = new QLabel;
    timer->setText(getTime());
    QFont font;
    font.setPointSize(22);
    timer->setFont(font);

    // Creating info to display:
    sessionType   = new QLabel("Session type : Work");
    sessionNumber = new QLabel("Number of sessions : 0");

    // Creating settings controls
    sessionLabel = new QLabel("Session time");
    restLabel    = new QLabel("Rest time");

    sessionTime  = new QLineEdit(QString::number(session));
    sessionTime->setAlignment(Qt::AlignRight);

    restTime     = new QLineEdit(QString::number(rest));
    restTime->setAlignment(Qt::AlignRight);

    // Creating layouts

    // Creating button layout
    buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(startButton);
    buttonsLayout->addWidget(stopButton);
    buttonsLayout->addWidget(resetButton);

    // Creating timer layout
    timerLayout = new QHBoxLayout;
    timerLayout->addStretch();
    timerLayout->addWidget(timer);
    timerLayout->addStretch();

    // Creating the settings layout
    settingsLayout = new QGridLayout();
    settingsLayout->addWidget(sessionLabel, 1,1, Qt::AlignCenter);
    settingsLayout->addWidget(sessionTime, 2,1, Qt::AlignCenter);
    settingsLayout->addWidget(restLabel, 1,2, Qt::AlignCenter);
    settingsLayout->addWidget(restTime, 2,2, Qt::AlignCenter);

    // Creating apply settings layout
    applyLayout = new QHBoxLayout();
    applyLayout->addStretch();
    applyLayout->addWidget(applyButton);


    // Creating the info layout
    infoLayout = new QVBoxLayout();
    infoLayout->addWidget(sessionType);
    infoLayout->addWidget(sessionNumber);

    // Creating main layout
    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(timerLayout);
    mainLayout->addLayout(buttonsLayout);
    mainLayout->addLayout(infoLayout);
    mainLayout->addSpacing(20);
    mainLayout->addLayout(settingsLayout);
    mainLayout->addLayout(applyLayout);
}

void Pomodoro::createActions() {
    showAction = new QAction("Pomodoro");
    connect(showAction, SIGNAL(triggered(bool)), this, SLOT(showResponse()));

    quitAction = new QAction("Quit");
    connect(quitAction, SIGNAL(triggered(bool)), this, SLOT(quitResponse()));
}

void Pomodoro::createTrayIcon() {
    sysIconMenu = new QMenu();

    sysIconMenu->addAction(showAction);
    sysIconMenu->addAction(quitAction);

    sysIcon = new QSystemTrayIcon(this);
    sysIcon->setContextMenu(sysIconMenu);
}

void Pomodoro::workStartMessage() {
    sysIcon->showMessage("Pomodoro", "Work session");
}

void Pomodoro::restStartMessage() {
    sysIcon->showMessage("Pomodoro", "Rest session");
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
    // Checking if the session ended
    if (timeElapsed >= stop) {
        emit sessionEnd();
    }

    timer->setText(getTime());
}

void Pomodoro::startPomodoro() {
    counter->start(1000);

    sysIcon->showMessage("Pomodoro", "Pomodoro Starting");
}

void Pomodoro::stopPomodoro() {
    counter->stop();

    sysIcon->showMessage("Pomodoro", "Pomodoro Stopped");
}

void Pomodoro::resetPomodoro() {
    timeElapsed = 0;
    counter->stop();
    counter->start(1000);
    updateTimer();

    sessionCount = 0;
    workSession = true;

    emit sessionCountChanged();
    emit sessionTypeChanged();
}

void Pomodoro::nextSession() {
    timeElapsed = 0;

    if (workSession) {
        workSession = false;
        stop = rest * 60;

        restStartMessage();

        emit sessionTypeChanged();
    } else {
        workSession = true;
        stop = session * 60;
        sessionCount++;

        workStartMessage();

        emit sessionCountChanged();
        emit sessionTypeChanged();
    }
}

void Pomodoro::quitResponse() {
    emit quitApp();
}

void Pomodoro::showResponse() {
    emit showApp();
}

void Pomodoro::updateSessionCount() {
    sessionNumber->setText("Number of sessions : " + QString::number(sessionCount));
}

void Pomodoro::updateSessiontype() {
    QString text;
    if (workSession) text = "Work";
    else text = "Rest";

    sessionType->setText("Session Type : " + text);
}

void Pomodoro::applyChanges() {
    counter->stop();

    // TODO: check if data is valid

    timeElapsed = 0;
    session     = sessionTime->text().toInt();
    rest        = restTime->text().toInt();
    stop        = session * 60;

    counter->start(1000);
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
