#include "alliedfield.h"

AlliedField::AlliedField(const QVector<QVector<FieldPlace> > &field, QObject *parent) : Field(parent), field(field)
{
    this->field = field;
}



AlliedField::AlliedField(const AlliedField &other)
{
    this->field = other.field;
}

const QVector<QVector<Field::FieldPlace> > &AlliedField::getField() const
{
    return field;
}

const AlliedField &AlliedField::operator=(const AlliedField &other)
{
    field = other.field;
    return *this;
}

bool AlliedField::isAllowedCell(int x, int y)
{
    if (field[x][y] == Field::EMPTY_PLACE ||
            field[x][y] == Field::SHIP_PLACE)
        return true;
    return false;
}

Field::FieldPlace AlliedField::shootTo(int x, int y)
{
    if(field[x][y] == Field::EMPTY_PLACE){
        field[x][y] = Field::EMPTY_WRECKED_PLACE;
        return Field::EMPTY_WRECKED_PLACE;
    }
    if(field[x][y] == Field::SHIP_PLACE){
        field[x][y] = Field::SHIP_WRECKED_PLACE;
        if(checkOnKilledShip(x, y)){
            changeToKilledShip(x, y);
            return Field::FieldPlace::SHIP_KILLED_PLACE;
        }
        return Field::SHIP_WRECKED_PLACE;
    }

    return field[x][y];
}

bool AlliedField::checkOnKilledShip(int x, int y)
{
    bool flag = false;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i != 0 && j != 0)
                continue;
            if((x + i < 0 || x + i >= Field::X_MAX || y + j < 0 || y + j >= Field::Y_MAX))
                continue;

            if(i == 0 && j == 0){
               if(checkOHForOneFieldShip(x, y))
                   return true;
            }

            if(field[x + i][y + j] == Field::FieldPlace::SHIP_WRECKED_PLACE){
                for (int k = 0; k < Field::SHIP_MAX_SIZE + 1; k++){

                    if((x + i*k < 0 || x + i*k >= Field::X_MAX || y + j*k < 0 || y + j*k >= Field::Y_MAX) || (field[x + i*k][y + j*k] ==  Field::FieldPlace::EMPTY_PLACE)){
                        flag = true;
                        break;
                    }
                    if(field[x + i*k][y + j*k] ==  Field::FieldPlace::SHIP_PLACE){
                        return false;
                    }
                }
            }
            else if(field[x+i][y+j] == SHIP_PLACE){
                return false;
            }
        }
    }
    return flag;
}
bool AlliedField::checkOHForOneFieldShip(int x, int y){
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0)
                continue;
            if((x + i < 0 || x + i >= Field::X_MAX || y + j < 0 || y + j >= Field::Y_MAX))
                continue;
            if(field[x + i][y + j] != Field::FieldPlace::EMPTY_PLACE && field[x + i][y + j] != Field::FieldPlace::EMPTY_WRECKED_PLACE)
                return false;
        }
    }
    return true;
}
void AlliedField::changeToKilledShip(int x, int y)
{
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0)
                continue;
            if(i != 0 && j != 0)
                continue;
            if((x + i < 0 || x + i >= Field::X_MAX || y + j < 0 || y + j >= Field::Y_MAX))
                continue;

            if(field[x + i][y + j] == Field::FieldPlace::SHIP_WRECKED_PLACE){
                field[x][y] = Field::FieldPlace::SHIP_KILLED_PLACE;
                field[x + i][y + j] = Field::FieldPlace::SHIP_KILLED_PLACE;
                for (int k = 0; k < Field::SHIP_MAX_SIZE; k++){
                    if((x + i*k < 0 || x + i*k >= Field::X_MAX || y + j*k < 0 || y + j*k >= Field::Y_MAX))
                        return;
                    if(field[x + i*k][y + j*k] == Field::FieldPlace::SHIP_WRECKED_PLACE){
                        field[x + i*k][y + j*k] = Field::FieldPlace::SHIP_KILLED_PLACE;
                    }else{
                        return;
                    }
                }
                return;
            }
        }
    }

    field[x][y] = Field::FieldPlace::SHIP_KILLED_PLACE;
}

