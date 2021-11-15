#include "builderfiled/builderfieldgraphic.h"
#include <QApplication>
#include "data/seabattleclient.h"
#include "services/servicesfactory.h"
#include "localgamesettingswidget.h"

int main(int argc, char *argv[])
{
    std::srand(time(0));
    QApplication a(argc, argv);
    QSharedPointer<SeaBattleClient> client(new SeaBattleClient);
    client->start();
    client->changeService(ServicesFactory::MAIN_MENU_SERVICE);

    return a.exec();
}
