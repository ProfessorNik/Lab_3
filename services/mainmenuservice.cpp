#include "mainmenuservice.h"
#include "../data/seabattleclient.h"
#include "servicesfactory.h"

MainMenuService::MainMenuService(SeaBattleClient* client, QObject *parent) : IService(parent), client(client), mainMenu(new MainMenu)
{
    connect(mainMenu.data(), &MainMenu::localGame, this, &MainMenuService::localGame);
    connect(mainMenu.data(), &MainMenu::closed, this, &MainMenuService::closed);
}

void MainMenuService::localGame()
{
    client->changeService(ServicesFactory::LOCAL_GAME_SETTINGS_SERVICE);
}


void MainMenuService::make()
{
    this->client->showWidget(mainMenu.data());
}
