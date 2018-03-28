#include "settings.h"

Settings::Settings(QWidget *parent) : QWidget(parent)
{
    createButtons();
    createLabels();
    createLineEdits();
    createLayouts();

    setLayout(mainLayout);

    setWindowTitle("Pomodoro settings");

    connect(resetButton, SIGNAL(clicked(bool)), this, SLOT(resetClicked()));
    connect(applyButton, SIGNAL(clicked(bool)), this, SLOT(applyClicked()));
}

void Settings::createButtons()
{
    resetButton = new QPushButton(tr("Reset"));

    applyButton = new QPushButton(tr("Apply"));
}

void Settings::createLabels()
{
    sessionLabel = new QLabel("Session duration");
    restLabel    = new QLabel("Rest duration");
}

void Settings::createLineEdits()
{
    sessionEdit = new QLineEdit();
    sessionEdit->setAlignment(Qt::AlignRight);

    restEdit    = new QLineEdit();
    restEdit->setAlignment(Qt::AlignRight);
}

void Settings::createLayouts()
{
    // edits layout
    editsLayout = new QGridLayout();
    editsLayout->addWidget(sessionLabel, 1,1);
    editsLayout->addWidget(sessionEdit, 1,2);
    editsLayout->addWidget(restLabel, 2,1);
    editsLayout->addWidget(restEdit, 2,2);

    //button layout
    buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch();
    buttonLayout->addWidget(applyButton);
    buttonLayout->addWidget(resetButton);

    //MainLayout
    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(editsLayout);
    mainLayout->addLayout(buttonLayout);
}

void Settings::setVariables(int *current_session, int* current_rest)
{
    session = current_session;
    rest    = current_rest;

    sessionEdit->setText(QString::number(*session));
    restEdit->setText(QString::number(*rest));
}

void Settings::resetClicked()
{
    *session = WORK;
    *rest    = REST;

    emit settingsChanged();

    this->close();
}

void Settings::applyClicked()
{
    *session = sessionEdit->text().toInt();
    *rest    = restEdit->text().toInt();

    emit settingsChanged();

    this->close();
}
