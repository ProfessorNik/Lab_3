#ifndef BUILDERFIELD_H
#define BUILDERFIELD_H

#include <QWidget>
#include <QPainter>
#include <QLabel>
#include "buildersinglefield.h"
#include "shipview.h"

class BuilderField : public QWidget
{
    Q_OBJECT
public:
    explicit BuilderField(QWidget *parent = nullptr);

    struct Ship{
        int size;
        QVector<QPair<int, int>> shipCoordinates;
    };

private slots:
    void shipSelected(int size);
    void showShip(int x, int y);
    void hideShip();
    void putShipTo(int x, int y);
    void rotateShip();
signals:
    void fieldIsReady(const QVector<QVector<Field::FieldPlace> >& fieldModel);
private:
    bool verticalShipRotation = true;
    int shipChoosen = -1;

    int numShip1 = 4;
    int numShip2 = 3;
    int numShip3 = 2;
    int numShip4 = 1;

    BuilderSingleField* field;
    QVector<QVector<Field::FieldPlace> > fieldModel;
    QLabel* labelShip1;
    QLabel* labelShip2;
    QLabel* labelShip3;
    QLabel* labelShip4;
    ShipView* ship1;
    ShipView* ship2;
    ShipView* ship3;
    ShipView* ship4;


    // QWidget interface
    void drawShipToField(const QVector<QPair<int, int> >& ship);
    void updateLabels();
    bool isGoodPosForShip(int x, int y);
    bool isOutFromField(int x, int y);
    QVector<QPair<int, int> > buildShip(int x, int y, bool &badPos);
    void checkOnFilledField();
protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // BUILDERFIELD_H
