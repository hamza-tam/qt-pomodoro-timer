#include <QApplication>

#include "pomodoro.h"

int main(int argc, char** argv) {

    QApplication app(argc, argv);

    Pomodoro window;
    window.show();

    return app.exec();

}
