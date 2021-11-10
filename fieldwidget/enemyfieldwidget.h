#ifndef ENEMYFIELDWIDGET_H
#define ENEMYFIELDWIDGET_H

#include "abstractfieldwidget.h"
#include <QMouseEvent>
#include <QTimer>

class EnemyFieldWidget : public AbstractFieldWidget
{
    Q_OBJECT
public:
    EnemyFieldWidget(QWidget* parent = nullptr);
    void update(const QVector<QVector<Field::FieldPlace> >& field);
protected:
    void drawField(QPainter *qp) override;
    void mousePressEvent(QMouseEvent *event) override;
private slots:
    void changeStep();
private:
    QVector<QVector<Field::FieldPlace> > field;
    QSharedPointer<QTimer> timer;
    bool step;
signals:
    void pressToSell(int x, int y);
};

#endif // ENEMYFIELDWIDGET_H
