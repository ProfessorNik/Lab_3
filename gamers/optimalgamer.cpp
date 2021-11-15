#include "optimalgamer.h"
#include <algorithm>
#include <QDebug>

OptimalGamer::OptimalGamer(QSharedPointer<IUser> user, QSharedPointer<BuilderFieldStrategy> builder, QObject *parent) : ComputerGamer(user, builder, parent)
{
    strategyPlaces.push_back((QVector<QPair<int, int>>() <<
                              QPair<int, int>(6, 0) <<
                              QPair<int, int>(2, 0) <<
                              QPair<int, int>(0, 2) <<
                              QPair<int, int>(0, 6)));
    strategyPlaces.push_back((QVector<QPair<int, int>>() <<
                              QPair<int, int>(3, 0) <<
                              QPair<int, int>(7, 0) <<
                              QPair<int, int>(9, 2) <<
                              QPair<int, int>(9, 6)));
}



FactoryGamers::Gamers OptimalGamer::getGamerVariation()
{
    return FactoryGamers::Gamers::OPTIMAL_GAMER;
}

void OptimalGamer::makeStep(int &x, int &y)
{
    do{
        updateCoordsAroundHint(getLastShoot());
        if(!coordsAroundHint.isEmpty()){
            x = coordsAroundHint.last().first;
            y = coordsAroundHint.last().second;
        }
        else if(!coordsFixedHint.isEmpty()){
            x = coordsFixedHint.last().first;
            y = coordsFixedHint.last().second;
        }
        else {
            x = coordsRandomHint.last().first;
            y = coordsRandomHint.last().second;
            qDebug() << "size: " << coordsRandomHint.size() << x << y;
        }
        deleteCoords(x, y);
        this->lastX = x;
        this->lastY = y;
    } while (!isUnknownSell(x, y));
}

void OptimalGamer::deleteCoords(int x, int y){
    removeElement(coordsRandomHint, x, y);
    removeElement(coordsFixedHint, x, y);
    removeElement(coordsAroundHint, x, y);
}

void OptimalGamer::updateCoordsAroundHint(Shoot prevShoot)
{
    if(prevShoot.kindPlace == Field::FieldPlace::SHIP_WRECKED_PLACE){
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if ((i == 0 && j != 0) || (i != 0 && j == 0))
                    addElementToCoordsAroundHint(prevShoot.x + i, prevShoot.y + j);
            }
         }
        removeExcessCellsInCoordsAroundHit();
        lastWreckedX = prevShoot.x;
        lastWreckedY = prevShoot.y;
        killingShip = true;
    }
    if(prevShoot.kindPlace == Field::FieldPlace::SHIP_KILLED_PLACE){
        coordsAroundHint.clear();
        killingShip = false;
    }
}

void OptimalGamer::removeElement(QList<QPair<int, int> > &list, int x, int y)
{
    for(auto it = list.cbegin(); it != list.cend(); it++){
        if (it->first == x && it->second == y){
            list.erase(it);
            break;
        }
    }
}

void OptimalGamer::removeExcessCellsInCoordsAroundHit()
{
    if(!killingShip)
        return;

    if(lastX == lastWreckedX){
        auto it = coordsAroundHint.cbegin();
        while (it != coordsAroundHint.cend()){
            if (it->first != lastWreckedX){
                it = coordsAroundHint.erase(it);
            }
            else{
                it++;
            }
        }
    }
    else if (lastY == lastWreckedY){
        auto it = coordsAroundHint.cbegin();
        while (it != coordsAroundHint.cend()){
            if (it->second != lastWreckedY){
                it = coordsAroundHint.erase(it);
            }
            else{
                it++;
            }
        }
    }
}

void OptimalGamer::rebuildCoords()
{
    killingShip = false;
    coordsRandomHint.clear();
    coordsFixedHint.clear();
    coordsAroundHint.clear();

    for(int x = 0; x < Field::X_MAX; x++){
        for(int y = 0; y < Field::Y_MAX; y++){
             coordsRandomHint.push_back({x, y});
        }
    }
    std::random_shuffle(coordsRandomHint.begin(), coordsRandomHint.end());

    for(auto place : strategyPlaces[0]){
        int x = place.first, y = place.second;
        while(x < Field::X_MAX && y < Field::Y_MAX){
            coordsFixedHint.push_back({x, y});
            x++;
            y++;
        }
    }

    for(auto place : strategyPlaces[1]){
        int x = place.first, y = place.second;
        while(x >= 0 && x < Field::X_MAX && y < Field::Y_MAX){
            coordsFixedHint.push_back({x, y});
            x--;
            y++;
        }
    }

    std::reverse(coordsFixedHint.begin(), coordsFixedHint.end());
}

bool OptimalGamer::isCoordsInSign(int x, int y)
{
    return x >= 0 && x < Field::X_MAX && y >= 0 && y < Field::Y_MAX;
}

void OptimalGamer::addElementToCoordsAroundHint(int x, int y)
{
    if(isCoordsInSign(x, y) && isUnknownSell(x, y)){
        coordsAroundHint.push_back({x, y});
    }
}
