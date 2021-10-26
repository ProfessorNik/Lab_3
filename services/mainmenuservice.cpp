#include "mainmenuservice.h"
#include "../data/session.h"
#include "servicesfactory.h"

MainMenuService::MainMenuService(Session* session, QObject *parent) : IService(parent)
{
    this->session = session;
    this->mainMenu = new MainMenu;
    connect(mainMenu, &MainMenu::localGame, this, &MainMenuService::localGame);
}

void MainMenuService::localGame()
{
    session->changeMode(Session::Mode::RANDOM_STRATEGY);
    session->changeService(ServicesFactory::LOCAL_GAME_SETTINGS_SERVICE);
}


void MainMenuService::make()
{
    this->session->showWidget(mainMenu);
}
