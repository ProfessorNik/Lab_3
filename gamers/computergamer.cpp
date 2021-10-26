#include "computergamer.h"
#include "QRandomGenerator"
#include "../field/field.h"
#include <QMap>

ComputerGamer::ComputerGamer(QSharedPointer<IUser> user, QSharedPointer<BuilderFieldStrategy> builder, QObject *parent) : IGamer(parent),  user(user), builder(builder)
{
    connect(builder.data(), &BuilderFieldStrategy::isBuilded, this, &ComputerGamer::rebuildGamer);
    rebuilded = false;
}


bool ComputerGamer::isAllowedSell(int x, int y)
{
    return model->isAllowedCell(x, y);
}

Field::FieldPlace ComputerGamer::shootTo(int x, int y)
{
    return model->shoot(x, y);
}

QVector<QVector<Field::FieldPlace> > ComputerGamer::randomBuildField()
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

bool ComputerGamer::checkNeighborhood(const QVector<QVector<Field::FieldPlace> >& field,int x, int y)
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

void ComputerGamer::defultBuildField(QVector<QVector<Field::FieldPlace> >& field)
{
    for(int x = 0; x < Field::X_MAX; x++){
        QVector<Field::FieldPlace> line;
        for(int y = 0; y < Field::Y_MAX; y++){
            line.emplaceBack(Field::FieldPlace::EMPTY_PLACE);
        }
        field.emplaceBack(line);
    }
}

void ComputerGamer::changeStep(bool step)
{
    if (step){
        int x, y;
        makeStep(x, y);
        emit shoot(x, y);
    }
}



void ComputerGamer::updateEnemyField(int x, int y, Field::FieldPlace place)
{
    model->responseOnShoot(x, y, place);
}


const AlliedField& ComputerGamer::getField()
{
    return model->getAlliedField();
}

void ComputerGamer::startGame()
{
    rebuilded = false;
}

bool ComputerGamer::isRenewed()
{
    return rebuilded;
}

void ComputerGamer::endGame()
{

}


void ComputerGamer::rebuild()
{
    builder->build();
}

void ComputerGamer::rebuildGamer(AlliedField field)
{
    if(model.isNull()){
        model = QSharedPointer<GameModel>(new GameModel(field));
        connect(model.data(), &GameModel::wasted, this, &ComputerGamer::wasted);
    }
    else{
        model->refactor(field);
    }
    rebuilded = true;
    emit fieldRebuilded();
}



bool ComputerGamer::isWasted()
{
    return model->isWasted();
}
