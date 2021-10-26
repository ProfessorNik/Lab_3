#include "session.h"

Session::Session(QObject *parent) : QObject(parent)
{
    user = new User();
    window = new MainWindow;
    this->service = nullptr;
    defaultSettings();
}

void Session::start()
{
    window->show();
}

bool Session::isOnline() const
{
    return online;
}

void Session::defaultSettings()
{
    user->setName("player");
    online = false;
}

QSharedPointer<LocalGameData> Session::getLocalGameData() const
{
    return localgd;
}

void Session::setLocalGameData(QSharedPointer<LocalGameData> newLocalgd)
{
    localgd = newLocalgd;
}

Session::Mode Session::getMode() const
{
    return mode;
}

//const User &Session::getUser() const
//{
//    return *user;
//}

const QString &Session::getUserName()
{
    return user->getName();
}

void Session::showWidget(QWidget *widget)
{
    window->setWidget(widget);
}

bool Session::isEmptyField()
{
    return user->isEmptyField();
}

//const AlliedField &Session::getField()
//{
//    return  user->getField();
//}

//void Session::setField(const AlliedField &newField)
//{
//    user->setField(newField);
//}

void Session::changeService(ServicesFactory::Services service)
{
    this->lastService = this->service;
    this->service = ServicesFactory::buildService(service, this);
    this->service->make();
}

void Session::changeMode(Mode mode)
{
    this->mode = mode;
}
