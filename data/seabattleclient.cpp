#include "seabattleclient.h"

SeaBattleClient::SeaBattleClient(QObject *parent) : QObject(parent)
{
    window = new MainWindow;
    this->service = nullptr;
}

void SeaBattleClient::start()
{
    window->show();
}

QSharedPointer<LocalGameData> SeaBattleClient::getLocalGameData() const
{
    return localgd;
}

void SeaBattleClient::setLocalGameData(QSharedPointer<LocalGameData> newLocalgd)
{
    localgd = newLocalgd;
}

void SeaBattleClient::showWidget(QWidget *widget)
{
    window->setWidget(widget);
}

void SeaBattleClient::changeService(ServicesFactory::Services service)
{
    this->service = ServicesFactory::buildService(service, this);
    this->service->make();
}
