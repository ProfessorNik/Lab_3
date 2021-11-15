#include "computergamer.h"
#include "QRandomGenerator"
#include "../field/field.h"
#include <QMap>

ComputerGamer::ComputerGamer(QSharedPointer<IUser> user, QSharedPointer<BuilderFieldStrategy> builder, QObject *parent) : IGamer(parent),  user(user), builder(builder)
{
    connect(builder.data(), &BuilderFieldStrategy::isBuilded, this, &ComputerGamer::rebuildGamer, Qt::QueuedConnection);
    connect(builder.data(), &BuilderFieldStrategy::closed, this, &ComputerGamer::closed, Qt::QueuedConnection);
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

void ComputerGamer::rebuildCoords()
{

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

ComputerGamer::Shoot ComputerGamer::getLastShoot() const
{
    return lastShoot;
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
    lastShoot = {x, y, place};
    model->responseOnShoot(x, y, place);
}


const AlliedField& ComputerGamer::getField()
{
    return model->getAlliedField();
}

void ComputerGamer::startBattle()
{
    rebuilded = false;
}

bool ComputerGamer::isRenewed()
{
    return rebuilded;
}

void ComputerGamer::endBattle()
{

}


void ComputerGamer::rebuild()
{
    lastShoot = {0, 0, Field::FieldPlace::EMPTY_PLACE};
    rebuildCoords();
    builder->build();
}

bool ComputerGamer::isUnknownSell(int x, int y)
{
    return model->isEmptyPlaceOnEnemyField(x, y);
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


void ComputerGamer::forcedClosing()
{
    builder->forcedClosing();
}


const QString &ComputerGamer::getName()
{
    return user->getName();
}
