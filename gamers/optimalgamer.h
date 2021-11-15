#ifndef OPTIMALGAMER_H
#define OPTIMALGAMER_H

#include "computergamer.h"

class OptimalGamer : public ComputerGamer
{
    Q_OBJECT
public:
    explicit OptimalGamer(QSharedPointer<IUser> user, QSharedPointer<BuilderFieldStrategy> builder, QObject *parent = nullptr);

    // IGamer interface
public:
    FactoryGamers::Gamers getGamerVariation() override;
    QVector<QVector<QPair<int, int>>> strategyPlaces;
    QList<QPair<int, int>> coordsRandomHint;
    QList<QPair<int, int>> coordsFixedHint;
    QList<QPair<int, int>> coordsAroundHint;

    // ComputerGamer interface
protected:
    void makeStep(int &x, int &y) override;
    void rebuildCoords() override;
private:
    int lastX, lastY;
    int lastWreckedX, lastWreckedY;
    bool killingShip;
    bool isCoordsInSign(int x, int y);

    void addElementToCoordsAroundHint(int x, int y);
    void deleteCoords(int x, int y);
    void updateCoordsAroundHint(Shoot prevShoot);
    void removeElement(QList<QPair<int,int>>& list, int x, int y);
    void removeExcessCellsInCoordsAroundHit();
};

#endif // OPTIMALGAMER_H
