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
    numGame = 0;
    scoreG1 = 0;
    scoreG2 = 0;
}

QSharedPointer<IGamer> LocalGameData::getGamer1() const
{
    return gamer1;
}

QSharedPointer<IGamer> LocalGameData::getGamer2() const
{
    return gamer2;
}

void LocalGameData::endGame()
{
    return;
}

void LocalGameData::forcedClosing()
{

}

void LocalGameData::gamer1Win()
{
    scoreG1++;
    emit changed();
}

void LocalGameData::gamer2Win()
{
    scoreG2++;
    emit changed();
}

bool LocalGameData::isNextBattle() const
{
    return scoreG1 + scoreG2 < amountGame;
}

int LocalGameData::getAmountGames() const
{
    return amountGame;
}

int LocalGameData::getScoreG1() const
{
    return scoreG1;
}

int LocalGameData::getScoreG2() const
{
    return scoreG2;
}

LocalGameData::GamerStatus LocalGameData::getStatusG1() const
{
    return statusG1;
}

LocalGameData::GamerStatus LocalGameData::getStatusG2() const
{
    return statusG2;
}

const QString &LocalGameData::getNameG1() const
{
    return gamer1->getName();
}

const QString &LocalGameData::getNameG2() const
{
    return gamer2->getName();
}


bool LocalGameData::isEndGame() const
{
    return !isNextBattle();
}
