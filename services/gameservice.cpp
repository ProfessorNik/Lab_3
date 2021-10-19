#include "gameservice.h"

GameService::GameService(Session *session, QObject *parent) : IService(parent)
{
    this->session = session;
    gc = new LocalGameContorller(session, this);
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
    if(session->isEmptyField()){
        session->changeService(ServicesFactory::BUILDER_SERVICE);
        return;
    }
    gc->startGame();
}
