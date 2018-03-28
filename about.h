#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>


class About : public QWidget
{    
public:
    About(QWidget *parent = 0);

private:
    QLabel          *softName;
    QLabel          *aboutText;

    QPushButton     *button;

    QVBoxLayout     *layout;


    // Methods
    void initComponents();
    void initText();
};

#endif // ABOUT_H
