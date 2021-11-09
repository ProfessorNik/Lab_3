//#include "mainwindow.h"
#include "builderfiled/builderfield.h"
#include <QApplication>
#include "random_strategy/gamemodel.h"
#include "random_strategy/widgetgameview.h"
#include "data/session.h"
#include "services/servicesfactory.h"
#include "localgamesettingswidget.h"

int main(int argc, char *argv[])
{
    std::srand(time(0));
    QApplication a(argc, argv);
    Session* session = new Session();
    session->start();
    session->changeService(ServicesFactory::MAIN_MENU_SERVICE);


    return a.exec();
}
