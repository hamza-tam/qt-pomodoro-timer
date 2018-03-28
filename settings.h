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

#include "default.h"

class Settings : public QWidget
{
    Q_OBJECT

private:
    // Variables
    int *session;
    int *rest;

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

public:
    // Setters
    void setVariables(int *current_session, int *current_rest);

private slots:
    void resetClicked();
    void applyClicked();

signals:
    void settingsChanged();
};

#endif // SETTINGS_H
