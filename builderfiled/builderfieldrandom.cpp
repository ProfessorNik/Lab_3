#include "builderfieldrandom.h"
#include <QRandomGenerator>
#include <QMap>
#include <random>
#include <ctime>
#include <QDebug>

BuilderFieldRandom::BuilderFieldRandom(QObject *parent) : AbstractBuilderFieldAlgorithm(parent)
{

}

int BuilderFieldRandom::generateX() const
{
    return rand() % 10;
}

int BuilderFieldRandom::generateY() const
{
    return rand() % 10;
}

bool BuilderFieldRandom::generateOrientation() const
{
    return rand() % 2;
}


AbstractBuilderFieldAlgorithm::CoordsShip BuilderFieldRandom::generateCoordsShip(int quantiyDecks) const
{
    Q_UNUSED(quantiyDecks);
    return {generateX(), generateY(), generateOrientation()};
}
