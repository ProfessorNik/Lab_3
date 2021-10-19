#include "mainmenuservice.h"
#include "../data/session.h"
#include "servicesfactory.h"

MainMenuService::MainMenuService(Session* session, QObject *parent) : IService(parent)
{
    this->session = session;
    this->mainMenu = new MainMenu;
    connect(mainMenu, &MainMenu::randomStrategy, this, &MainMenuService::randomStrategy);
}

void MainMenuService::randomStrategy()
{
    session->changeMode(Session::Mode::RANDOM_STRATEGY);
    session->changeService(ServicesFactory::GAME_SERVICE);
}


void MainMenuService::make()
{
    this->session->showWidget(mainMenu);
}
