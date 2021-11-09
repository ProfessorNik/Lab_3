#include "enemyfield.h"

EnemyField::EnemyField(QObject *parent) : Field(parent)
{
    defultBuildFiled();
}

void EnemyField::refactor()
{
    field.clear();
    defultBuildFiled();
}

const QVector<QVector<Field::FieldPlace> > &EnemyField::getField() const
{
    return field;
}

void EnemyField::update(int x, int y, Field::FieldPlace cell)
{
    if(cell == Field::FieldPlace::SHIP_KILLED_PLACE){
        changeToKilledShip(x, y);
    }

    field[x][y] = cell;
}


void EnemyField::defultBuildFiled()
{
    for(int x = 0; x < Field::X_MAX; x++){
        QVector<Field::FieldPlace> line;
        for(int y = 0; y < Field::Y_MAX; y++){
            line.emplaceBack(Field::FieldPlace::EMPTY_PLACE);
        }
        field.emplaceBack(line);
    }
}

void EnemyField::changeToKilledShip(int x, int y)
{
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0){
                pasteEmptyPlaces(x, y);
                continue;
            }
            if(i != 0 && j != 0)
                continue;

            if((x + i < 0 || x + i >= Field::X_MAX || y + j < 0 || y + j >= Field::Y_MAX))
                continue;

            if(field[x + i][y + j] == Field::FieldPlace::SHIP_WRECKED_PLACE){
                  field[x][y] = Field::FieldPlace::SHIP_WRECKED_PLACE;
//                pasteEmptyPlaces(x, y);
//                field[x + i][y + j] = Field::FieldPlace::SHIP_KILLED_PLACE;
//                pasteEmptyPlaces(x+i, y+i);
                for (int k = 0; k < Field::SHIP_MAX_SIZE; k++){
                    if (x + i*k < 0 || x + i*k >= Field::X_MAX || y + j*k < 0 || y + j*k >= Field::Y_MAX){
                        break;
                    }
                    else if(field[x + i*k][y + j*k] == Field::FieldPlace::SHIP_WRECKED_PLACE){
                        field[x + i*k][y + j*k] = Field::FieldPlace::SHIP_KILLED_PLACE;
                        pasteEmptyPlaces(x + i*k, y + j*k);
                    }else{
                        break;
                    }
                }
            }
        }
    }
}

void EnemyField::pasteEmptyPlaces(int x, int y)
{
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if((x + i < 0 || x + i >= Field::X_MAX || y + j < 0 || y + j >= Field::Y_MAX))
                continue;
            if(field[x + i][y + j] == Field::FieldPlace::EMPTY_PLACE){
               field[x + i][y + j] = Field::FieldPlace::EMPTY_WRECKED_PLACE;
            }
        }
    }
}
