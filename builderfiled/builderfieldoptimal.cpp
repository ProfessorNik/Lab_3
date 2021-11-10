#include "builderfieldoptimal.h"
#include "../field/alliedfield.h"
#include <QDebug>

BuilderFieldOptimal::BuilderFieldOptimal(QObject *parent) : BuilderFieldStrategy(parent)
{
    QVector<QVector<Field::FieldPlace> > field;

}

void BuilderFieldOptimal::defaultBuildField(QVector<QVector<Field::FieldPlace> >& field)
{
    field.clear();
    for(int x = 0; x < Field::X_MAX; x++){
        QVector<Field::FieldPlace> line;
        for(int y = 0; y < Field::Y_MAX; y++){
            line.emplaceBack(Field::FieldPlace::EMPTY_PLACE);
        }
        field.emplaceBack(line);
    }
}

void BuilderFieldOptimal::build()
{
    auto field = optimalBuildField();
    for (auto line : field){
        qDebug() << line;
    }
    emit isBuilded(AlliedField(field));
}

void BuilderFieldOptimal::forcedClosing()
{
}

QVector<QVector<Field::FieldPlace> > BuilderFieldOptimal::optimalBuildField()
{
    QVector<QVector<Field::FieldPlace> > field;
    defaultBuildField(field);

    QVector<int> numsShips;
    numsShips << 1
              << 2
              << 3
              << 4;
    QMap<int, int> numsDeckShips;
    numsDeckShips[4] = 1;
    numsDeckShips[3] = 2;
    numsDeckShips[2] = 3;
    numsDeckShips[1] = 4;
    for(auto numShips : numsShips){
        for(int i = 0; i < numShips; i++){
            while(true){
                bool vertical;
                int x, y;
                vertical = rand() % 2;
                if(numsDeckShips[numShips] > 1){
                    if(!vertical){
                        x = rand() % 10;
                        y = rand() % 2;
                    if (y == 1)
                        y = 9;
                    }
                    else{
                        x = rand() % 2;
                        y = rand() % 10;
                        if(x == 1){
                            x = 9;
                        }
                    }
                }
                else{
                     x = rand() % 10;
                     y = rand() % 10;
                }

                if(!vertical){
                    bool canPlace = true;
                    for(int j = 0; j < numsDeckShips[numShips]; j++){
                        if(!checkNeighborhood(field, x+j, y)){
                            canPlace = false;
                            break;
                        }
                    }
                    if(canPlace){
                        for(int j = 0; j < numsDeckShips[numShips]; j++){
                            field[x + j][y] = Field::FieldPlace::SHIP_PLACE;

                        }
                        break;
                    }
                }
                else{
                    bool canPlace = true;
                    for(int j = 0; j < numsDeckShips[numShips]; j++){
                        if(!checkNeighborhood(field, x, y+j)){
                            canPlace = false;
                            break;
                        }
                    }
                    if(canPlace){
                        for(int j = 0; j < numsDeckShips[numShips]; j++){
                            field[x][y + j] = Field::FieldPlace::SHIP_PLACE;
                        }
                         break;
                    }

                }
            }
        }
    }

    return field;
}

bool BuilderFieldOptimal::checkNeighborhood(const QVector<QVector<Field::FieldPlace> >& field, int x, int y)
{
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0)
               if((x + i < 0 || x + i >= Field::X_MAX || y + j < 0 || y + j >= Field::Y_MAX))
                   return false;

            if((x + i < 0 || x + i >= Field::X_MAX || y + j < 0 || y + j >= Field::Y_MAX))
                continue;
            if(field[x + i][y + j] != Field::FieldPlace::EMPTY_PLACE)
                return false;
        }
    }
    return true;
}

