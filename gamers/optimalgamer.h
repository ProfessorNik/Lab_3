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
    QList<QPair<int, int>> randomHint;
    QList<QPair<int, int>> coordsFixedHint;
    QList<QPair<int, int>> coordsAroundHint;

    // ComputerGamer interface
protected:
    void makeStep(int &x, int &y) override;
    void rebuildCoords() override;
private:
    int lastX, lastY;
    int lastWreckedX, lastWreckedY;
    void deleteCoords(int x, int y);
    void updateCoordsAroundHint(Field::FieldPlace place);
    void removeElement(QList<QPair<int,int>>& list, int x, int y);
};

#endif // OPTIMALGAMER_H
