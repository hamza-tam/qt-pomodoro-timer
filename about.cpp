#include "about.h"

About::About(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("About this software");

    initText();
    initComponents();

    layout = new QVBoxLayout();
    layout->addSpacing(10);
    layout->addWidget(softName);
    layout->addSpacing(10);
    layout->addWidget(aboutText);
    layout->addSpacing(20);
    layout->addWidget(button);
    layout->addSpacing(10);

    setLayout(layout);
}

void About::initComponents()
{
    button = new QPushButton("OK !");
    connect(button, SIGNAL(clicked(bool)), this, SLOT(close()));
}

void About::initText()
{
    softName = new QLabel("Pomodoro App \n v1.0");
    QFont font;
    font.setPixelSize(22);
    font.setBold(true);
    softName->setFont(font);
    softName->setAlignment(Qt::AlignCenter);

    aboutText = new QLabel("This software was made\nby Hamza Tamenaoul\nusing Qt 5.10");
    font.setPixelSize(13);
    font.setBold(false);
    aboutText->setFont(font);
    aboutText->setAlignment(Qt::AlignCenter);
}
