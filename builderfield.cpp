#include "builderfield.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QMouseEvent>
#include <QDebug>

BuilderField::BuilderField(QWidget *parent) : QWidget(parent)
{
    for(int i = 0; i < Field::X_MAX; i++){
        QVector<Field::FieldPlace> line;
        for(int j = 0; j < Field::Y_MAX; j++)
            line.push_back(Field::FieldPlace::EMPTY_PLACE);
        fieldModel.push_back(line);
    }


    QHBoxLayout* mainLayout = new QHBoxLayout;

    QVBoxLayout* shipsLayout = new QVBoxLayout;

    QVBoxLayout* ship1Layout = new QVBoxLayout;
    QVBoxLayout* ship2Layout = new QVBoxLayout;
    QVBoxLayout* ship3Layout = new QVBoxLayout;
    QVBoxLayout* ship4Layout = new QVBoxLayout;

    labelShip1 = new QLabel(QStringLiteral("Ships left: %1").arg(numShip1));
    ship1 = new ShipView(1);
    ship1Layout->addWidget(labelShip1);
    ship1Layout->addWidget(ship1);

    labelShip2 = new QLabel(QStringLiteral("Ships left: %1").arg(numShip2));
    ship2 = new ShipView(2);
    ship2Layout->addWidget(labelShip2);
    ship2Layout->addWidget(ship2);

    labelShip3 = new QLabel(QStringLiteral("Ships left: %1").arg(numShip3));
    ship3 = new ShipView(3);
    ship3Layout->addWidget(labelShip3);
    ship3Layout->addWidget(ship3);

    labelShip4 = new QLabel(QStringLiteral("Ships left: %1").arg(numShip4));
    ship4 = new ShipView(4);
    ship4Layout->addWidget(labelShip4);
    ship4Layout->addWidget(ship4);



    shipsLayout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Fixed, QSizePolicy::Expanding));
    shipsLayout->addLayout(ship1Layout);
    shipsLayout->addLayout(ship2Layout);
    shipsLayout->addLayout(ship3Layout);
    shipsLayout->addLayout(ship4Layout);
    shipsLayout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Fixed, QSizePolicy::Expanding));

    connect(ship1, &ShipView::shipSelected, this, &BuilderField::shipSelected);
    connect(ship2, &ShipView::shipSelected, this, &BuilderField::shipSelected);
    connect(ship3, &ShipView::shipSelected, this, &BuilderField::shipSelected);
    connect(ship4, &ShipView::shipSelected, this, &BuilderField::shipSelected);

    QVBoxLayout* singleFieldLayout = new QVBoxLayout;
    field = new BuilderSingleField;
    singleFieldLayout->addWidget(field);

    connect(field, &BuilderSingleField::mouseOnPosition, this, &BuilderField::showShip);
    connect(field, &BuilderSingleField::mouseOut, this, &BuilderField::hideShip);
    connect(field, &BuilderSingleField::putShipTo, this, &BuilderField::putShipTo);
    connect(field, &BuilderSingleField::rotateShip, this, &BuilderField::rotateShip);

    mainLayout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed));
    mainLayout->addLayout(shipsLayout);
    mainLayout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed));
    mainLayout->addLayout(singleFieldLayout);
    mainLayout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed));

    this->setLayout(mainLayout);
}


void BuilderField::shipSelected(int size)
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

void BuilderField::showShip(int x, int y)
{
    if(shipChoosen != -1){
        bool isRed;
        auto ship = buildShip(x, y, isRed);
        field->update(fieldModel, ship, isRed);
    }
    else
        field->update(fieldModel);
    qDebug() << x << " " << y;
}

void BuilderField::hideShip()
{
    field->update(fieldModel);
    qDebug() << "hide";
}

bool BuilderField::isOutFromField(int x, int y){
    return !(x >= 0 && x < Field::X_MAX && y >= 0 && y < Field::X_MAX);
}

bool BuilderField::isGoodPosForShip(int x, int y){
    if (isOutFromField(x, y)){
        return false;
    }
    if (!isOutFromField(x, y)){
        if(fieldModel[x][y] == Field::FieldPlace::SHIP_PLACE){
            return false;
        }
    }
    if (!isOutFromField(x + 1, y)) {
        if(fieldModel[x + 1][y] == Field::FieldPlace::SHIP_PLACE)
            return false;
    }
    if (!isOutFromField(x, y + 1)) {
        if (fieldModel[x][y + 1] == Field::FieldPlace::SHIP_PLACE)
            return false;
    }
    if (!isOutFromField(x - 1, y)) {
        if(fieldModel[x - 1][y] == Field::FieldPlace::SHIP_PLACE)
            return false;
    }
    if (!isOutFromField(x, y - 1)) {
        if(fieldModel[x][y - 1] == Field::FieldPlace::SHIP_PLACE)
            return false;
    }
    if (!isOutFromField(x - 1, y - 1)) {
        if (fieldModel[x - 1][y - 1] == Field::FieldPlace::SHIP_PLACE)
            return false;
    }
    else if (!isOutFromField(x + 1, y - 1)) {
        if (fieldModel[x + 1][y - 1] == Field::FieldPlace::SHIP_PLACE)
            return false;
    }
    if (!isOutFromField(x - 1, y + 1)){
        if (fieldModel[x - 1][y + 1] == Field::FieldPlace::SHIP_PLACE)
             return false;
    }
    if (!isOutFromField(x + 1, y + 1)){
        if(fieldModel[x + 1][y + 1] == Field::FieldPlace::SHIP_PLACE)
            return false;
    }
    return true;
}

QVector<QPair<int, int> > BuilderField::buildShip(int x, int y, bool& badPos){
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

void BuilderField::putShipTo(int x, int y)
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
            field->update(fieldModel);
            shipChoosen = -1;
        }
    }
}

void BuilderField::rotateShip()
{
    verticalShipRotation = !verticalShipRotation;
}

void BuilderField::updateLabels(){
    labelShip1->setText(QStringLiteral("Ships left: %1").arg(numShip1));
    labelShip2->setText(QStringLiteral("Ships left: %1").arg(numShip2));
    labelShip3->setText(QStringLiteral("Ships left: %1").arg(numShip3));
    labelShip4->setText(QStringLiteral("Ships left: %1").arg(numShip4));
}

void BuilderField::drawShipToField(const QVector<QPair<int, int> >& ship){
    for(auto pair: ship){
        fieldModel[pair.first][pair.second] = Field::FieldPlace::SHIP_PLACE;
    }
}

void BuilderField::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::RightButton){
        rotateShip();
    }
}




