#include "mainmenuservice.h"
#include "../data/seabattleclient.h"
#include "servicesfactory.h"

MainMenuService::MainMenuService(SeaBattleClient* session, QObject *parent) : IService(parent), session(session), mainMenu(new MainMenu)
{
    connect(mainMenu.data(), &MainMenu::localGame, this, &MainMenuService::localGame);
}

void MainMenuService::localGame()
{
    session->changeService(ServicesFactory::LOCAL_GAME_SETTINGS_SERVICE);
}


void MainMenuService::make()
{
    this->session->showWidget(mainMenu.data());
}
