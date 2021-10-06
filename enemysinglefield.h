#ifndef ENEMYSINGLEFIELD_H
#define ENEMYSINGLEFIELD_H

#include "abstractsinglefield.h"

class EnemySingleField : public AbstractSingleField
{
    Q_OBJECT
public:
    EnemySingleField(QWidget* parent = nullptr);
    void update(const QVector<QVector<Field::FieldPlace> >& field);
    // AbstractSingleField interface
protected:
    void drawField(QPainter *qp) override;
private:
    QVector<QVector<Field::FieldPlace> > field;
};

#endif // ENEMYSINGLEFIELD_H
