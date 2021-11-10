#include "builderfieldgraphic.h"

#include "builderfieldgraphic.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QMouseEvent>
#include <QDebug>
#include "shipwidget.h"

BuilderFieldGraphic::BuilderFieldGraphic(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    QVBoxLayout* shipsLayout = new QVBoxLayout;

    QVBoxLayout* ship1Layout = new QVBoxLayout;
    QVBoxLayout* ship2Layout = new QVBoxLayout;
    QVBoxLayout* ship3Layout = new QVBoxLayout;
    QVBoxLayout* ship4Layout = new QVBoxLayout;

    labelShip1 = new QLabel(QStringLiteral("Ships left: %1").arg(numShip1));
    ship1 = new ShipWidget(1);
    ship1Layout->addWidget(labelShip1);
    ship1Layout->addWidget(ship1);

    labelShip2 = new QLabel(QStringLiteral("Ships left: %1").arg(numShip2));
    ship2 = new ShipWidget(2);
    ship2Layout->addWidget(labelShip2);
    ship2Layout->addWidget(ship2);

    labelShip3 = new QLabel(QStringLiteral("Ships left: %1").arg(numShip3));
    ship3 = new ShipWidget(3);
    ship3Layout->addWidget(labelShip3);
    ship3Layout->addWidget(ship3);

    labelShip4 = new QLabel(QStringLiteral("Ships left: %1").arg(numShip4));
    ship4 = new ShipWidget(4);
    ship4Layout->addWidget(labelShip4);
    ship4Layout->addWidget(ship4);

    shipsLayout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Fixed, QSizePolicy::Expanding));
    shipsLayout->addLayout(ship1Layout);
    shipsLayout->addLayout(ship2Layout);
    shipsLayout->addLayout(ship3Layout);
    shipsLayout->addLayout(ship4Layout);
    shipsLayout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Fixed, QSizePolicy::Expanding));

    connect(ship1, &ShipWidget::shipSelected, this, &BuilderFieldGraphic::shipSelected);
    connect(ship2, &ShipWidget::shipSelected, this, &BuilderFieldGraphic::shipSelected);
    connect(ship3, &ShipWidget::shipSelected, this, &BuilderFieldGraphic::shipSelected);
    connect(ship4, &ShipWidget::shipSelected, this, &BuilderFieldGraphic::shipSelected);

    QVBoxLayout* singleFieldLayout = new QVBoxLayout;
    fieldWidget = new BuilderFieldWidget;
    singleFieldLayout->addWidget(fieldWidget);

    connect(fieldWidget, &BuilderFieldWidget::mouseOnPosition, this, &BuilderFieldGraphic::showShip);
    connect(fieldWidget, &BuilderFieldWidget::mouseOut, this, &BuilderFieldGraphic::hideShip);
    connect(fieldWidget, &BuilderFieldWidget::putShipTo, this, &BuilderFieldGraphic::putShipTo);
    connect(fieldWidget, &BuilderFieldWidget::rotateShip, this, &BuilderFieldGraphic::rotateShip);

    mainLayout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed));
    mainLayout->addLayout(shipsLayout);
    mainLayout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed));
    mainLayout->addLayout(singleFieldLayout);
    mainLayout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed));

    this->setLayout(mainLayout);
    refactor();
}

void BuilderFieldGraphic::refactor()
{
    field.clear();
    numShip1 = 4;
    numShip2 = 3;
    numShip3 = 2;
    numShip4 = 1;
    updateLabels();
    clearField();
    buildEmptyField();
    fieldWidget->update(field);
}

void BuilderFieldGraphic::updateLabels(){
    labelShip1->setText(QStringLiteral("Ships left: %1").arg(numShip1));
    labelShip2->setText(QStringLiteral("Ships left: %1").arg(numShip2));
    labelShip3->setText(QStringLiteral("Ships left: %1").arg(numShip3));
    labelShip4->setText(QStringLiteral("Ships left: %1").arg(numShip4));
}

void BuilderFieldGraphic::clearField()
{
    field.clear();
}

void BuilderFieldGraphic::buildEmptyField()
{
    for(int i = 0; i < Field::X_MAX; i++){
        QVector<Field::FieldPlace> line;
        for(int j = 0; j < Field::Y_MAX; j++)
            line.push_back(Field::FieldPlace::EMPTY_PLACE);
        field.push_back(line);
    }
}

void BuilderFieldGraphic::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::RightButton){
        rotateShip();
    }
}

void BuilderFieldGraphic::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    emit closed();
}

void BuilderFieldGraphic::shipSelected(int size)
{
    if(size == 1 && numShip1 <= 0)
        return;
    else if(size == 2 && numShip2 <= 0)
        return;
    else if(size == 3 && numShip3 <= 0)
        return;
    else if(size == 4 && numShip4 <= 0)
        return;
    shipChoosen = size;
}

void BuilderFieldGraphic::showShip(int x, int y)
{
    if(shipChoosen != -1){
        bool isRed;
        auto ship = buildShip(x, y, isRed);
        fieldWidget->update(field, ship, isRed);
    }
    else
        fieldWidget->update(field);
}

void BuilderFieldGraphic::putShipTo(int x, int y)
{
    if(shipChoosen != -1){
        bool badPos;
        auto ship = buildShip(x, y, badPos);
        if(!badPos){
            if(shipChoosen == 1)
                numShip1--;
            else if(shipChoosen == 2)
                numShip2--;
            else if(shipChoosen == 3)
                numShip3--;
            else if(shipChoosen == 4)
                numShip4--;
            drawShipToField(ship);
            updateLabels();
            fieldWidget->update(field);
            shipChoosen = -1;
            checkOnFilledField();
        }
    }
}

QVector<QPair<int, int> > BuilderFieldGraphic::buildShip(int x, int y, bool& badPos){
    badPos = false;
    QVector<QPair<int, int> > ship;
    for (int i = 0; i < shipChoosen; i++){
        if(!verticalShipRotation){
            ship.push_back(QPair<int, int>(x + i, y));
            if(!isGoodPosForShip(x + i, y)){
                badPos = true;
            }

        }
        else{
            ship.push_back(QPair<int, int>(x, y + i));
            if(!isGoodPosForShip(x, y + i)){
                badPos = true;
            }
        }
    }
    return ship;
}

bool BuilderFieldGraphic::isGoodPosForShip(int x, int y){
    if (isOutFromField(x, y)){
        return false;
    }

    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0)
                continue;

            if(!isOutFromField(x + i, y + j))
                if(field[x + i][y + j] == Field::FieldPlace::SHIP_PLACE)
                        return false;
        }
    }

    return true;
}

bool BuilderFieldGraphic::isOutFromField(int x, int y){
    return !(x >= 0 && x < Field::X_MAX && y >= 0 && y < Field::X_MAX);
}

void BuilderFieldGraphic::hideShip()
{
    fieldWidget->update(field);
}

void BuilderFieldGraphic::checkOnFilledField(){
    if (numShip1 <= 0 && numShip2 <= 0 && numShip3 <= 0 && numShip4 <= 0){
        emit fieldIsReady(field);
    }

}

void BuilderFieldGraphic::rotateShip()
{
    verticalShipRotation = !verticalShipRotation;
}

void BuilderFieldGraphic::drawShipToField(const QVector<QPair<int, int> >& ship){
    for(auto pair: ship){
        field[pair.first][pair.second] = Field::FieldPlace::SHIP_PLACE;
    }
}


