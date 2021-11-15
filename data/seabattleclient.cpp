#include "seabattleclient.h"

SeaBattleClient::SeaBattleClient(QObject *parent) : QObject(parent), window(new MainWindow)
{
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
    if(!this->service.isNull())
        disconnect(this->service.data(), &IService::closed, window.data(), &MainWindow::close);
    this->service = ServicesFactory::buildService(service, this);
    connect(this->service.data(), &IService::closed, window.data(), &MainWindow::close);
    this->service->make();
}
