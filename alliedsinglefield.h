#ifndef ALLIEDSINGLEFIELD_H
#define ALLIEDSINGLEFIELD_H

#include "abstractsinglefield.h"

class AlliedSingleField : public AbstractSingleField
{
public:
    AlliedSingleField(QWidget* parent = nullptr);
    void update(const QVector<QVector<Field::FieldPlace> >& field);
    // AbstractSingleField interface
protected:
    void drawField(QPainter *qp) override;
private:
    QVector<QVector<Field::FieldPlace> > field;
};

#endif // ALLIEDSINGLEFIELD_H
