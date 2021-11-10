#ifndef BUILDERFIELDGRAPHIC_H
#define BUILDERFIELDGRAPHIC_H

#include <QWidget>
#include "../field/field.h"
#include <QLabel>
#include "shipwidget.h"
#include "builderfieldwidget.h"

class BuilderFieldGraphic : public QWidget
{
    Q_OBJECT
public:
    explicit BuilderFieldGraphic(QWidget *parent = nullptr);

    void refactor();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

private slots:
    void shipSelected(int size);
    void showShip(int x, int y);
    void hideShip();
    void putShipTo(int x, int y);
    void rotateShip();

private:
    bool verticalShipRotation = true;
    int shipChoosen = -1;

    int numShip1 = 4;
    int numShip2 = 3;
    int numShip3 = 2;
    int numShip4 = 1;

    BuilderFieldWidget* fieldWidget;
    QVector<QVector<Field::FieldPlace> > field;
    QLabel* labelShip1;
    QLabel* labelShip2;
    QLabel* labelShip3;
    QLabel* labelShip4;
    ShipWidget* ship1;
    ShipWidget* ship2;
    ShipWidget* ship3;
    ShipWidget* ship4;

    void clearField();
    void buildEmptyField();
    void drawShipToField(const QVector<QPair<int, int> >& ship);
    void updateLabels();
    bool isGoodPosForShip(int x, int y);
    bool isOutFromField(int x, int y);
    QVector<QPair<int, int> > buildShip(int x, int y, bool &badPos);
    void checkOnFilledField();


signals:
    void fieldIsReady(const QVector<QVector<Field::FieldPlace> >& fieldModel);
    void closed();
};

#endif // BUILDERFIELDGRAPHIC_H
