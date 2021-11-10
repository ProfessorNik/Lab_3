#ifndef BUILDERFIELDOPTIMAL_H
#define BUILDERFIELDOPTIMAL_H

#include "abstractbuilderfieldalgorithm.h"

class BuilderFieldOptimal : public AbstractBuilderFieldAlgorithm
{
    Q_OBJECT
public:
    explicit BuilderFieldOptimal(QObject *parent = nullptr);

protected:
    CoordsShip generateCoordsShip(int quantityDecks) const override;
    int generateX(int quantityDecks, bool vertical) const;
    int generateY(int quantityDecks, bool vertical) const;
    bool generateOrientation() const;
};

#endif // BUILDERFIELDOPTIMAL_H
