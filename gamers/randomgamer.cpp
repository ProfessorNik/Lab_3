#include "randomgamer.h"
#include <QRandomGenerator>

RandomGamer::RandomGamer(QSharedPointer<IUser> user, QSharedPointer<BuilderFieldStrategy> builder, QObject *parent) : ComputerGamer(user, builder, parent)
{

}


void RandomGamer::makeStep(int &x, int &y)
{
        x = rand() % 10;
        y = rand() % 10;
}


FactoryGamers::Gamers RandomGamer::getGamerVariation()
{
    return FactoryGamers::Gamers::RANDOM_GAMER;
}

