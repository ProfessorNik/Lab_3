#include "field.h"
#include <stdexcept>

Field::Field(const QVector<QVector<FieldPlace> >& alliedField){
    this->alliedField = alliedField;
    fillEnemyField();
}

Field::FieldPlace Field::enemyShootTo(int x, int y){
    if ((x < 0 || x >= X_MAX) && (x < 0 || x >= X_MAX)){
        throw "bad value";
    }

    FieldPlace place = alliedField[x][y];
    if (place != FieldPlace::EMPTY_WRECKED_PLACE && place != FieldPlace::SHIP_WRECKED_PLACE){
        if(place == FieldPlace::EMPTY_PLACE){
            alliedField[x][y] = FieldPlace::EMPTY_WRECKED_PLACE;
        }
        else{
            alliedField[x][y] = FieldPlace::SHIP_WRECKED_PLACE;
        }
    }

    return place;
}

void Field::alliedShootTo(int x, int y, const FieldPlace& place){
    if ((x < 0 || x >= X_MAX) && (x < 0 || x >= X_MAX)){
        throw "bad value";
    }

    if(place == FieldPlace::EMPTY_PLACE)
        enemyField[x][y] = FieldPlace::EMPTY_WRECKED_PLACE;
    if(place == FieldPlace::SHIP_PLACE)
        enemyField[x][y] = FieldPlace::SHIP_WRECKED_PLACE;
}

const QVector<QVector<Field::FieldPlace> > &Field::getAlliedField() const
{
    return alliedField;
}

const QVector<QVector<Field::FieldPlace> > &Field::getEnemyField() const
{
    return enemyField;
}

void Field::fillEnemyField()
{
    for(int i = 0; i < X_MAX; i++){
        QVector<FieldPlace> line;
        for(int j = 0; j < Y_MAX; j++)
            line.push_back(FieldPlace::EMPTY_PLACE);
        enemyField.push_back(line);
    }
}



