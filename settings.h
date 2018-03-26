#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

class Settings : public QWidget
{
    Q_OBJECT

public:
    Settings(QWidget *parent = 0);

private:
    // Buttons
    QPushButton     *resetButton;
    QPushButton     *applyButton;

    // Labels
    QLabel          *sessionLabel;
    QLabel          *restLabel;

    // Line edits
    QLineEdit       *sessionEdit;
    QLineEdit       *restEdit;

    // Layouts
    QGridLayout     *editsLayout;
    QHBoxLayout     *buttonLayout;
    QVBoxLayout     *mainLayout;

    // Methods

    void createButtons();
    void createLabels();
    void createLineEdits();
    void createLayouts();
};

#endif // SETTINGS_H
