#ifndef BUILDERFIELDRANDOM_H
#define BUILDERFIELDRANDOM_H

#include "abstractbuilderfieldalgorithm.h"

class BuilderFieldRandom : public AbstractBuilderFieldAlgorithm
{
    Q_OBJECT

public:
    explicit BuilderFieldRandom(QObject *parent = nullptr);

protected:
    int generateX() const;
    int generateY() const;
    bool generateOrientation() const;

    CoordsShip generateCoordsShip(int quantiyDecks) const override;
};

#endif // BUILDERFIELDRANDOM_H
