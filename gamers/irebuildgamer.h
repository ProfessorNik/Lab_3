#ifndef IREBUILDGAMER_H
#define IREBUILDGAMER_H

#include "factorygamers.h"
#include "../field/alliedfield.h"

class IRebuildGamer
{
public:
    virtual FactoryGamers::Gamers getGamerVariation() = 0;
    virtual void rebuildGamer(AlliedField field) = 0;
};

#endif // IREBUILDGAMER_H
