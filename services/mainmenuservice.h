#ifndef MAINMENUSERVICE_H
#define MAINMENUSERVICE_H

#include "iservice.h"
#include <QObject>
#include <QSharedPointer>
#include "mainmenu.h"

class SeaBattleClient;

class MainMenuService : public IService
{
public:
    explicit MainMenuService(SeaBattleClient* session, QObject *parent = nullptr);

private:
    SeaBattleClient* session;
    QSharedPointer<MainMenu> mainMenu;

private slots:
    void localGame();

    // IService interface
public:
    void make() override;
};

#endif // MAINMENUSERVICE_H
