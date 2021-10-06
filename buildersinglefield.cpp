#include "buildersinglefield.h"
#include "QMouseEvent"
#include "QDebug"

BuilderSingleField::BuilderSingleField(QWidget* parent): AbstractSingleField(parent)
{
    this->setMouseTracking(true);
    for(int i = 0; i < Field::X_MAX; i++){
        QVector<Field::FieldPlace> line;
        for(int j = 0; j < Field::Y_MAX; j++)
            line.push_back(Field::FieldPlace::EMPTY_PLACE);
        field.push_back(line);
    }
}

void BuilderSingleField::update(const QVector<QVector<Field::FieldPlace> > &field)
{
    qDebug() << "update1";
    this->isOutShip = true;
    this->field = field;
    this->repaint();
}

void BuilderSingleField::update(const QVector<QVector<Field::FieldPlace> > &field, const QVector<QPair<int, int>> ship, bool isRed)
{
    qDebug() << "update2";
    this->isOutShip = false;
    this->field = field;
    this->ship = ship;
    this->isRed = isRed;
    this->repaint();
}

void BuilderSingleField::drawField(QPainter *qp)
{
    qDebug("drawField");
    for (int x = 0; x < Field::X_MAX ; x++ ) {
        for (int y = 0; y < Field::Y_MAX; y++){
            if(field[x][y] == Field::FieldPlace::EMPTY_PLACE){

            }
            else if (field[x][y] == Field::FieldPlace::SHIP_PLACE){
                drawBlueSquare(qp, x, y);
            }
        }
    }

    if(!isOutShip){
        qDebug("drawShip");
        for(auto coordinates : ship){
            if (0 <= coordinates.first && coordinates.first < Field::X_MAX){
                if(0 <= coordinates.second && coordinates.second < Field::Y_MAX){
                    if (isRed)
                        drawRedSquare(qp, coordinates.first, coordinates.second);
                    else
                        drawBlueSquare(qp, coordinates.first, coordinates.second);
                }
            }
        }
    }
}



void BuilderSingleField::mouseMoveEvent(QMouseEvent *event)
{
    //qDebug() << static_cast<int>(event->position().x() / 30) << " " << static_cast<int>(event->position().y() / 30);
    emit mouseOnPosition(static_cast<int>(event->position().x() / 30), static_cast<int>(event->position().y() / 30));
}

void BuilderSingleField::enterEvent(QEnterEvent *event)
{
    //qDebug() << "Enter in widget: " << static_cast<int>(event->position().x() / 30) << " " << static_cast<int>(event->position().y() / 30);
    emit mouseOnPosition(static_cast<int>(event->position().x() / 30), static_cast<int>(event->position().y() / 30));
}

void BuilderSingleField::leaveEvent(QEvent *event)
{
    //qDebug() << "Live from widget";
    emit mouseOut();
}

void BuilderSingleField::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::LeftButton)
        emit putShipTo(static_cast<int>(event->position().x() / 30), static_cast<int>(event->position().y() / 30));
    if(event->button() == Qt::MouseButton::RightButton)
        emit rotateShip();
}

