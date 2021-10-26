#include "randomgamer.h"
#include <QRandomGenerator>

RandomGamer::RandomGamer(QSharedPointer<IUser> user, QSharedPointer<BuilderFieldStrategy> builder, QObject *parent) : ComputerGamer(user, builder, parent)
{

}


void RandomGamer::makeStep(int &x, int &y)
{
    QRandomGenerator generator;
    while (true) {
        x = generator.bounded(0, Field::X_MAX - 1);
        y = generator.bounded(0, Field::Y_MAX - 1);

        if(model->isEmptyPlaceOnEnemyField(x, y))
            break;
    }
}


FactoryGamers::Gamers RandomGamer::getGamerVariation()
{
    return FactoryGamers::Gamers::RANDOM_GAMER;
}

