//#include "mainwindow.h"
#include "builderfiled/builderfield.h"
#include <QApplication>
#include "random_strategy/gamemodel.h"
#include "random_strategy/widgetgameview.h"
#include "data/session.h"
#include "services/servicesfactory.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Session* session = new Session();
    session->start();
    session->changeService(ServicesFactory::MAIN_MENU_SERVECE);

    return a.exec();
}
