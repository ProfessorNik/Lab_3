#ifndef LOCALGAMECONTORLLER_H
#define LOCALGAMECONTORLLER_H

#include "igamecontroller.h"
#include "../../gamers/humangamer.h"
#include "../../gamers/randomgamer.h"
#include "../../gamers/igamer.h"

class BuilderService;

class LocalGameContorller : public IGameController
{
public:
    explicit LocalGameContorller(Session* session, QObject *parent = nullptr);

    HumanGamer* gamer1;
    IGamer* gamer2;
    Session* session;

    bool gamer1Step;
    // IGameController interface
public:
    void startGame() override;
private slots:
    void tryStep(int x, int y);
};

#endif // LOCALGAMECONTORLLER_H
