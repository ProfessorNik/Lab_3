#ifndef FIELDMODEL_H
#define FIELDMODEL_H

#include "interfacefiledmodel.h"
#include "observable.h"

class FieldModel : public InterfaceFiledModel, public Observable
{
public:
    FieldModel(const QVector<QVector<Field::FieldPlace> >& alliedField);
    bool shotIn(int x, int y) override;
    const Field &getField() const override;
private:
    Field field;
};

#endif // FIELDMODEL_H
