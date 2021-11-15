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
    explicit MainMenuService(SeaBattleClient* client, QObject *parent = nullptr);

    void make() override;
private:
    SeaBattleClient* client;
    QSharedPointer<MainMenu> mainMenu;

private slots:
    void localGame();
};

#endif // MAINMENUSERVICE_H
