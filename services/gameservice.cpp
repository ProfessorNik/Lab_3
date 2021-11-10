#include "gameservice.h"
#include "../data/localgamedata.h"

GameService::GameService(Session *session, QObject *parent) : IService(parent)
{
    this->session = session;
    this->view = QSharedPointer<GameWidget>(new GameWidget(session->getLocalGameData()));
    gc = QSharedPointer<LocalGameContorller>(new LocalGameContorller(session->getLocalGameData(), this));
//    connect(view.data(), &GameWidget::exit, gc.data(), &LocalGameContorller::exitGame);
    connect(view.data(), &GameWidget::exit, this, &GameService::exit);
   // connect(session->getLocalGameData().data(), &LocalGameData::gameEnd, this, &LocalGameData::endGame);
}

void GameService::changeState(GameState *state)
{
    if (this->state != nullptr)
        delete this->state;
    this->state = state;
    this->state->setContext(this);
}

void GameService::endGame(){

}

void GameService::goToMainMenu()
{

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
