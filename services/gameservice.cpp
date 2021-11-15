#include "gameservice.h"
#include "../data/localgamedata.h"

GameService::GameService(SeaBattleClient *client, QObject *parent) : IService(parent)
{
    this->client = client;
    this->view = QSharedPointer<GameStatusWidget>(new GameStatusWidget(client->getLocalGameData()));
    gc = QSharedPointer<LocalGameContorller>(new LocalGameContorller(client->getLocalGameData(), this));
    connect(view.data(), &GameStatusWidget::exit, this, &GameService::exit);
}

void GameService::exit()
{
    gc->forcedClosing();
    client->changeService(ServicesFactory::MAIN_MENU_SERVICE);
}


void GameService::make()
{
    client->showWidget(view.data());
    gc->startGame();
}
