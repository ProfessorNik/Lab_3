#ifndef GAMESERVICE_H
#define GAMESERVICE_H

#include "iservice.h"
#include "../random_strategy/controllers/localgamecontorller.h"
#include "gamestates/gamestate.h"
#include "../gamewidget.h"


class Session;

class GameService : public IService
{
    Q_OBJECT
public:

    explicit GameService(Session* session, QObject *parent = nullptr);
    void changeState(GameState* state);
private:

    QSharedPointer<LocalGameContorller> gc;
    QSharedPointer<GameWidget> view;
    GameState *state;
    Session *session;

    void goToMainMenu();
    // IService interface
private slots:
    void exit();
public:
    void make() override;
};

#endif // GAMESERVICE_H
