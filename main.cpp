#include "uiauthentification.hpp"
#include "flowcontroller.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FlowController controller;
    controller.exec();
    //UIAuthentification w;
    //w.show();
    return a.exec();
}
