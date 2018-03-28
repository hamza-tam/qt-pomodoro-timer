#include <QApplication>

#include "window.h"
#include "pomodoro.h"
#include "settings.h"

int main(int argc, char** argv) {

    QApplication app(argc, argv);

    Window window;
    //Settings window;
    window.show();

    return app.exec();

}
