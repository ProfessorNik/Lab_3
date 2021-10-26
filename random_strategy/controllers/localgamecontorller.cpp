#include "localgamecontorller.h"
#include "../../services/servicesfactory.h"
#include <QThread>

LocalGameContorller::LocalGameContorller(QSharedPointer<LocalGameData> gd, QObject *parent) : IGameController(parent), gd(gd)
{
    gamer1 = gd->getGamer1();
    gamer2 = gd->getGamer2();
    connect(gd.data(), &LocalGameData::nextGame, this, &LocalGameContorller::prepareBattle);
    connect(gd.data(), &LocalGameData::gameEnd, this, &LocalGameContorller::endGame);

    connect(gamer1.data(), &IGamer::shoot, this, &LocalGameContorller::tryStep);
    connect(gamer2.data(), &IGamer::shoot, this, &LocalGameContorller::tryStep);
    connect(gamer1.data(), &IGamer::fieldRebuilded, this, &LocalGameContorller::startBattle);
    connect(gamer1.data(), &IGamer::fieldRebuilded, this, &LocalGameContorller::startBattle);
}

void LocalGameContorller::startGame()
{
    gd->startGame();
    isEndBattle = true;
}

bool LocalGameContorller::isBuilded()
{
    if(gamer1->isRenewed() && gamer2->isRenewed())
        return true;
    return false;
}

void LocalGameContorller::startBattle()
{
    if(!isBuilded())
        return;
    gamer1->startGame();
    gamer2->startGame();
    isEndBattle = false;
    gamer1Step = true;
    gamer1->changeStep(gamer1Step);
    gamer2->changeStep(!gamer1Step);
}



void LocalGameContorller::tryStep(int x, int y)
{
    ///////
    if(gamer1Step){
        qDebug() << "G1: " << x << y;
        if(gamer2->isAllowedSell(x, y)){
            Field::FieldPlace place = gamer2->shootTo(x, y);
            if(place == Field::FieldPlace::EMPTY_WRECKED_PLACE){
                gamer1Step = !gamer1Step;
            }
            gamer1->updateEnemyField(x, y, place);
        }
        if(gamer2->isWasted()){
            endBattle();
            return;
        }

    }
    else{
        qDebug() << "G2: " << x << y;
        if(gamer1->isAllowedSell(x, y)){
            Field::FieldPlace place = gamer1->shootTo(x, y);
            if(place == Field::FieldPlace::EMPTY_WRECKED_PLACE){
                gamer1Step = !gamer1Step;
            }
            gamer2->updateEnemyField(x, y, place);
        }
        if(gamer1->isWasted()){
            endBattle();
            return;
        }
    }

    gamer1->changeStep(gamer1Step);
    gamer2->changeStep(!gamer1Step);
}

void LocalGameContorller::prepareBattle()
{
    gamer1->rebuild();
    gamer2->rebuild();
}

void LocalGameContorller::endBattle()
{
    qDebug("endBattle");
    gamer1->endGame();
    gamer2->endGame();
    //////
    if(gamer1Step)
        gd->gamer1Win();
    else
        gd->gamer2Win();
    //////
}

