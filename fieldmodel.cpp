#include "fieldmodel.h"

FieldModel::FieldModel(const QVector<QVector<Field::FieldPlace> >& alliedField) : field(alliedField){

}

bool FieldModel::shotIn(int x, int y){
    auto place = field.enemyShootTo(x, y);
    if(place == Field::FieldPlace::EMPTY_WRECKED_PLACE || place == Field::FieldPlace::SHIP_WRECKED_PLACE){
        return false;
    }
    return true;
}

const Field &FieldModel::getField() const
{
    return field;
}
