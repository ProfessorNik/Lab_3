#include "builderfieldoptimal.h"
#include "../field/alliedfield.h"
#include <QDebug>

BuilderFieldOptimal::BuilderFieldOptimal(QObject *parent) : AbstractBuilderFieldAlgorithm(parent)
{
    QVector<QVector<Field::FieldPlace> > field;

}


AbstractBuilderFieldAlgorithm::CoordsShip BuilderFieldOptimal::generateCoordsShip(int quantityDecks) const
{
    bool vertical = generateOrientation();
    int x = generateX(quantityDecks, vertical);
    int y = generateY(quantityDecks, vertical);

    return {x, y, vertical};
}

bool BuilderFieldOptimal::generateOrientation() const
{
    return rand() % 2;
}

int BuilderFieldOptimal::generateX(int quantityDecks, bool vertical) const
{
    int x;
    if(vertical && quantityDecks > 1){
        x = rand() % 2;
        if (x == 1)
            x = 9;
    }
    else{
        x = rand() % 10;
    }

    return x;
}

int BuilderFieldOptimal::generateY(int quantityDecks, bool vertical) const
{
    int y;
    if(!vertical && quantityDecks > 1){
        y = rand() % 2;
        if(y == 1)
            y = 9;
    }
    else{
        y = rand() % 10;
    }

    return y;
}

