#include "settings.h"

Settings::Settings(QWidget *parent) : QWidget(parent)
{
    createButtons();
    createLabels();
    createLineEdits();
    createLayouts();

    setLayout(mainLayout);

    setWindowTitle("test");
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
    restEdit    = new QLineEdit();
}

void Settings::createLayouts()
{
    // edits layout
    editsLayout = new QGridLayout();
    editsLayout->addWidget(sessionLabel, 1,1);
    editsLayout->addWidget(sessionEdit, 1,2);
    editsLayout->addWidget(restLabel, 2,1);
    editsLayout->addWidget(restEdit, 2,2);
²
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
