#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameService;

class GameState
{
    GameService* context;

    virtual void make(){};

public:
    void setContext(GameService *newContext);
};

#endif // GAMESTATE_H
