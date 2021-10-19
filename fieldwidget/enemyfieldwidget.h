#ifndef ENEMYFIELDWIDGET_H
#define ENEMYFIELDWIDGET_H

#include "abstractfieldwidget.h"
#include <QMouseEvent>

class EnemyFieldWidget : public AbstractFieldWidget
{
    Q_OBJECT
public:
    EnemyFieldWidget(QWidget* parent = nullptr);
    void update(const QVector<QVector<Field::FieldPlace> >& field);
    // AbstractSingleField interface
protected:
    void drawField(QPainter *qp) override;
private:
    QVector<QVector<Field::FieldPlace> > field;
signals:
    void pressToSell(int x, int y);
    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // ENEMYFIELDWIDGET_H
