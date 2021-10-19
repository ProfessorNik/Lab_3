#ifndef ALLIEDFIELDWIDGET_H
#define ALLIEDFIELDWIDGET_H

#include "abstractfieldwidget.h"

class AlliedFieldWidget : public AbstractFieldWidget
{
public:
    AlliedFieldWidget(QWidget* parent = nullptr);
    void update(const QVector<QVector<Field::FieldPlace> >& field);
    // AbstractSingleField interface
protected:
    void drawField(QPainter *qp) override;
private:
    QVector<QVector<Field::FieldPlace> > field;
};

#endif // ALLIEDFIELDWIDGET_H
