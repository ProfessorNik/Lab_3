#include "localgamecontorller.h"
#include "../services/servicesfactory.h"
#include <QThread>

LocalGameContorller::LocalGameContorller(QSharedPointer<LocalGameData> gd, QObject *parent) : IGameController(parent), gd(gd)
{
    gamer1 = gd->getGamer1();
    gamer2 = gd->getGamer2();

    connect(gamer1.data(), &IGamer::shoot, this, &LocalGameContorller::tryStep, Qt::QueuedConnection);
    connect(gamer2.data(), &IGamer::shoot, this, &LocalGameContorller::tryStep, Qt::QueuedConnection);
    connect(gamer1.data(), &IGamer::fieldRebuilded, this, &LocalGameContorller::startBattle, Qt::QueuedConnection);
    connect(gamer2.data(), &IGamer::fieldRebuilded, this, &LocalGameContorller::startBattle, Qt::QueuedConnection);
}


//this method called for start serii game
void LocalGameContorller::startGame()
{
    gd->startGame();
    nextBattle();
    isEndBattle = true;
}

//closed child window when push button "Exit"
void LocalGameContorller::forcedClosing()
{
    gamer1->forcedClosing();
    gamer2->forcedClosing();
    gd->forcedClosing();
}

//started prepare gamers for next battle if there are still games
void LocalGameContorller::nextBattle()
{
    if(gd->isNextBattle())
        prepareBattle();
    else
        endGame();
}

void LocalGameContorller::prepareBattle()
{
    gamer1->rebuild();
    gamer2->rebuild();
}

//this slot called when gamers is ready
void LocalGameContorller::startBattle()
{
    if(!isBuilded())
        return;
    gamer1->startBattle();
    gamer2->startBattle();
    isEndBattle = false;
    gamer1Step = rand() % 2;
    gamer1->changeStep(gamer1Step);
    gamer2->changeStep(!gamer1Step);
}

void LocalGameContorller::endBattle()
{
    qDebug("endBattle");
    gamer1->endBattle();

    gamer2->endBattle();
    //////
    if(gamer1Step)
        gd->gamer1Win();
    else
        gd->gamer2Win();
    //////
    nextBattle();
}

void LocalGameContorller::endGame()
{
    gd->endGame();
}

bool LocalGameContorller::isBuilded()
{
    if(gamer1->isRenewed() && gamer2->isRenewed()){
        return true;
    }
    return false;
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


