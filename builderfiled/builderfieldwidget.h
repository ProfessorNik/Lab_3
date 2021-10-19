#ifndef BUILDERFIELDWIDGET_H
#define BUILDERFIELDWIDGET_H

#include "../fieldwidget/abstractfieldwidget.h"
#include <QObject>
#include "../field/field.h"

class BuilderFieldWidget : public AbstractFieldWidget
{
    Q_OBJECT
public:
    BuilderFieldWidget(QWidget* parent = nullptr);
    void update(const QVector<QVector<Field::FieldPlace> > &field);
    void update(const QVector<QVector<Field::FieldPlace> > &field,
                const QVector<QPair<int, int> > ship,
                bool isRed);
protected:
    void drawField(QPainter *qp) override;
private:
    QVector<QVector<Field::FieldPlace> > field;
    bool isOutShip = true;
    bool isRed = false;
    QVector<QPair<int, int> > ship;

signals:
    void mouseOnPosition(int x, int y);
    void mouseOut();
    void putShipTo(int x, int y);
    void rotateShip();
protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
};


#endif // BUILDERFIELDWIDGET_H
