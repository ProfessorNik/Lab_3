#include "builderfieldrandom.h"
#include <QRandomGenerator>
#include <QMap>

BuilderFieldRandom::BuilderFieldRandom(QObject *parent) : BuilderFieldStrategy(parent)
{

}


void BuilderFieldRandom::build()
{
   auto field = randomBuildField();
   emit isBuilded(AlliedField(field));
}

QVector<QVector<Field::FieldPlace> > BuilderFieldRandom::randomBuildField()
{
    QVector<QVector<Field::FieldPlace> > field;
    defultBuildField(field);
    QRandomGenerator genetator;
    QVector<int> numsShips;
    numsShips << 4
              << 3
              << 2
              << 1;
    QMap<int, int> numsDeckShips;
    numsDeckShips[4] = 1;
    numsDeckShips[3] = 2;
    numsDeckShips[2] = 3;
    numsDeckShips[1] = 4;
    for(auto numShips : numsShips){
        for(int i = 0; i < numShips; i++){
            while(true){
//                qDebug("try to set ship");
                int x = genetator.bounded(0, Field::X_MAX);
                int y = genetator.bounded(0, Field::X_MAX);
                bool vertical = genetator.bounded(0, 1);
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

bool BuilderFieldRandom::checkNeighborhood(const QVector<QVector<Field::FieldPlace> >& field,int x, int y)
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

void BuilderFieldRandom::defultBuildField(QVector<QVector<Field::FieldPlace> >& field)
{
    for(int x = 0; x < Field::X_MAX; x++){
        QVector<Field::FieldPlace> line;
        for(int y = 0; y < Field::Y_MAX; y++){
            line.emplaceBack(Field::FieldPlace::EMPTY_PLACE);
        }
        field.emplaceBack(line);
    }
}

