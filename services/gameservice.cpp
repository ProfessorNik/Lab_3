#include "gameservice.h"

GameService::GameService(Session *session, QObject *parent) : IService(parent)
{
    this->session = session;
    this->view = QSharedPointer<GameWidget>(new GameWidget(session->getLocalGameData()));
    gc = QSharedPointer<LocalGameContorller>(new LocalGameContorller(session->getLocalGameData(), this));
}

void GameService::changeState(GameState *state)
{
    if (this->state != nullptr)
        delete this->state;
    this->state = state;
    this->state->setContext(this);
}


void GameService::make()
{
    session->showWidget(view.data());
    gc->startGame();
}
