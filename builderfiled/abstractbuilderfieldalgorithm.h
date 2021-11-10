#ifndef ABSTRACTBUILDERFIELDALGORITHM_H
#define ABSTRACTBUILDERFIELDALGORITHM_H

#include "builderfieldstrategy.h"
#include <QVector>
#include <QMap>

class AbstractBuilderFieldAlgorithm : public BuilderFieldStrategy
{
    Q_OBJECT
public:
    explicit AbstractBuilderFieldAlgorithm(QObject *parent = nullptr);

    void init();
    void build() override;
    void forcedClosing() override;
protected:
    typedef struct CoordsShip{
        int x;
        int y;
        int vertical;
    } coordsShip;

    virtual CoordsShip generateCoordsShip(int quantityDecks) const = 0;
private:
    QVector<QVector<Field::FieldPlace> > field;
    QVector<int> numsShips;
    QMap<int, int> numsDeckShips;

    void controlledFieldBuild();
    void clearField();
    void buildEmptyField();
    void locateShips();
    void locateShip(int quantityDecks);
    bool isAvilabelSpaceForVerticalShip(int x, int y, int quantityDecks);
    bool isAvilabelSpaceForHorizontalShip(int x, int y, int quantityDecks);
    void locateVerticalShip(int x, int y, int quantityDecks);
    void locateHorizontalShip(int x, int y, int quantityDecks);
    bool isAvailableSpace(int x, int y);
};

#endif // ABSTRACTBUILDERFIELDALGORITHM_H
