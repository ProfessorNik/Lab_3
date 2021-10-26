#include "localgamedata.h"

LocalGameData::LocalGameData(FactoryGamers::Gamers gamer1, QSharedPointer<IUser> user1,
                             FactoryGamers::Gamers gamer2, QSharedPointer<IUser> user2, int amountGame,
                             QObject *parent) : IGameDataModel(parent), amountGame(amountGame)
{
    this->gamer1 = FactoryGamers::createGamer(gamer1, user1);
    this->gamer2 = FactoryGamers::createGamer(gamer2, user2);
    numGame = 0;
    scoreG1 = 0;
    scoreG2 = 0;
}

void LocalGameData::startGame()
{
    if(!checkOnEndGame())
        emit nextGame();
    else
        emit gameEnd();
}

QSharedPointer<IGamer> LocalGameData::getGamer1() const
{
    return gamer1;
}

QSharedPointer<IGamer> LocalGameData::getGamer2() const
{
    return gamer2;
}

void LocalGameData::gamer1Win()
{
    scoreG1++;
    emit changed();
    if(checkOnEndGame()){
        emit gameEnd();
        return;
    }
    emit nextGame();
}

void LocalGameData::gamer2Win()
{
    scoreG2++;
    emit changed();
    if(checkOnEndGame()){
        emit gameEnd();
        return;
    }
    emit nextGame();
}

bool LocalGameData::checkOnEndGame()
{
    return scoreG1 + scoreG2 >= amountGame;
}

int LocalGameData::getAmountGames()
{
    return amountGame;
}

int LocalGameData::getScoreG1()
{
    return scoreG1;
}

int LocalGameData::getScoreG2()
{
    return scoreG2;
}

LocalGameData::GamerStatus LocalGameData::getStatusG1()
{
    return statusG1;
}

LocalGameData::GamerStatus LocalGameData::getStatusG2()
{
    return statusG2;
}
