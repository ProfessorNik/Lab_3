#ifndef INTERFACEFILEDMODEL_H
#define INTERFACEFILEDMODEL_H

#include "field.h"

class InterfaceFiledModel
{
public:
    virtual bool shotIn(int x, int y) = 0;
    virtual const Field& getField() const = 0;
};

#endif // INTERFACEFILEDMODEL_H
