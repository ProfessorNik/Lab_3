#ifndef LOCALGAMECONTORLLER_H
#define LOCALGAMECONTORLLER_H

#include "igamecontroller.h"
#include "../../gamers/humangamer.h"
#include "../../gamers/randomgamer.h"
#include "../../gamers/igamer.h"
#include "../../data/localgamedata.h"


class BuilderService;

class LocalGameContorller : public IGameController
{
public:
    explicit LocalGameContorller(QSharedPointer<LocalGameData> gd, QObject *parent = nullptr);

    QSharedPointer<LocalGameData> gd;
    QSharedPointer<IGamer> gamer1;
    QSharedPointer<IGamer> gamer2;

    bool isEndBattle;
    bool gamer1Step;
    // IGameController interface
public:
    void startGame() override;
public slots:
    void forcedClosing();

private slots:
    void tryStep(int x, int y);
    void prepareBattle();
    void endBattle();
    void endGame();
private:
    bool isBuilded();
    void startBattle();
    void nextBattle();
};

#endif // LOCALGAMECONTORLLER_H
