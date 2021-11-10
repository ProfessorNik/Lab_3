#include "abstractbuilderfieldalgorithm.h"

AbstractBuilderFieldAlgorithm::AbstractBuilderFieldAlgorithm(QObject *parent) : BuilderFieldStrategy(parent)
{
    init();
}

void AbstractBuilderFieldAlgorithm::init()
{
    numsShips << 1 << 2 << 3 << 4;
    numsDeckShips[4] = 1;
    numsDeckShips[3] = 2;
    numsDeckShips[2] = 3;
    numsDeckShips[1] = 4;
}

void AbstractBuilderFieldAlgorithm::forcedClosing()
{

}

void AbstractBuilderFieldAlgorithm::build()
{
    controlledFieldBuild();
    emit isBuilded(AlliedField(field));
}

void AbstractBuilderFieldAlgorithm::controlledFieldBuild()
{
    clearField();
    buildEmptyField();
    locateShips();
}

void AbstractBuilderFieldAlgorithm::clearField()
{
    field.clear();
}

void AbstractBuilderFieldAlgorithm::buildEmptyField()
{
    for(int x = 0; x < Field::X_MAX; x++){
        QVector<Field::FieldPlace> line;
        for(int y = 0; y < Field::Y_MAX; y++){
            line.emplaceBack(Field::FieldPlace::EMPTY_PLACE);
        }
        field.emplaceBack(line);
    }
}

void AbstractBuilderFieldAlgorithm::locateShips()
{
    for(auto numShips : numsShips)
        for(int i = 0; i < numShips; i++)
            locateShip(numsDeckShips[numShips]);
}

void AbstractBuilderFieldAlgorithm::locateShip(int quantityDecks)
{
    while (true) {
        bool vertical = generateOrientation();
        int x = generateX();
        int y = generateY();

        if(vertical){
            if (isAvilabelSpaceForVerticalShip(x, y, quantityDecks)){
                locateVerticalShip(x, y, quantityDecks);
                break;
            }
        }
        else{
            if (isAvilabelSpaceForHorizontalShip(x, y, quantityDecks)){
                locateHorizontalShip(x, y, quantityDecks);
                break;
            }
        }
    }
}

bool AbstractBuilderFieldAlgorithm::isAvilabelSpaceForVerticalShip(int x, int y, int quantityDecks)
{
    for(int i = 0; i < quantityDecks; i++){
        if(!isAvailableSpace(x, y+i)){
            return false;
        }
    }
    return true;
}

bool AbstractBuilderFieldAlgorithm::isAvilabelSpaceForHorizontalShip(int x, int y, int quantityDecks)
{
    for(int i = 0; i < quantityDecks; i++){
        if(!isAvailableSpace(x+i, y)){
            return false;
        }
    }
    return true;
}

void AbstractBuilderFieldAlgorithm::locateVerticalShip(int x, int y, int quantityDecks)
{
    for(int i = 0; i < quantityDecks; i++){
        field[x][y + i] = Field::FieldPlace::SHIP_PLACE;
    }
}

void AbstractBuilderFieldAlgorithm::locateHorizontalShip(int x, int y, int quantityDecks)
{
    for(int i = 0; i < quantityDecks; i++){
        field[x + i][y] = Field::FieldPlace::SHIP_PLACE;
    }
}

bool AbstractBuilderFieldAlgorithm::isAvailableSpace(int x, int y)
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




