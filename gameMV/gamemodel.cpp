#include "gamemodel.h"

GameModel::GameModel(const AlliedField &alliedField, QObject *parent) : QObject(parent), alliedField(alliedField)
{
    connect(&this->alliedField, &AlliedField::wasted, this, &GameModel::wasted);
}

void GameModel::refactor(const AlliedField &alliedField)
{
    this->alliedField = alliedField;
    this->enemyField.refactor();
}

const AlliedField &GameModel::getAlliedField() const
{
    return alliedField;
}

const EnemyField &GameModel::getEnemyField() const
{
    return enemyField;
}

bool GameModel::isAllowedCell(int x, int y)
{
    return alliedField.isAllowedCell(x, y);
}

Field::FieldPlace GameModel::shoot(int x, int y)
{
    auto place = alliedField.shootTo(x, y);
    emit changed();
    return place;
}

void GameModel::responseOnShoot(int x, int y, Field::FieldPlace place){
    enemyField.update(x, y, place);
    emit changed();
}

bool GameModel::isEmptyPlaceOnEnemyField(int x, int y)
{
    return enemyField.getField()[x][y] == Field::FieldPlace::EMPTY_PLACE;
}

bool GameModel::isWasted()
{
    return alliedField.isWasted();
}



