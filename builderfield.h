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
signals:

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
protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // BUILDERFIELD_H
