#include "gameservice.h"
#include "../data/localgamedata.h"

GameService::GameService(SeaBattleClient *session, QObject *parent) : IService(parent)
{
    this->session = session;
    this->view = QSharedPointer<GameStatusWidget>(new GameStatusWidget(session->getLocalGameData()));
    gc = QSharedPointer<LocalGameContorller>(new LocalGameContorller(session->getLocalGameData(), this));
    connect(view.data(), &GameStatusWidget::exit, this, &GameService::exit);
}

void GameService::exit()
{
    gc->forcedClosing();
    session->changeService(ServicesFactory::MAIN_MENU_SERVICE);
}


void GameService::make()
{
    session->showWidget(view.data());
    gc->startGame();
}
