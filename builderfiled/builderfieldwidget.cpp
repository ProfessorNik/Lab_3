#include "builderfieldwidget.h"
#include "QMouseEvent"
#include "QDebug"

BuilderFieldWidget::BuilderFieldWidget(QWidget* parent): AbstractFieldWidget(parent)
{
    this->setMouseTracking(true);
    for(int i = 0; i < Field::X_MAX; i++){
        QVector<Field::FieldPlace> line;
        for(int j = 0; j < Field::Y_MAX; j++)
            line.push_back(Field::FieldPlace::EMPTY_PLACE);
        field.push_back(line);
    }
}

void BuilderFieldWidget::update(const QVector<QVector<Field::FieldPlace> > &field)
{
    this->isOutShip = true;
    this->field = field;
    this->repaint();
}

void BuilderFieldWidget::update(const QVector<QVector<Field::FieldPlace> > &field, const QVector<QPair<int, int>> ship, bool isRed)
{
    this->isOutShip = false;
    this->field = field;
    this->ship = ship;
    this->isRed = isRed;
    this->repaint();
}

void BuilderFieldWidget::drawField(QPainter *qp)
{
    drawReadyField(qp);

    if(!isOutShip){
        drawNotPastedShip(qp);
    }
}

void BuilderFieldWidget::drawReadyField(QPainter *qp){
    for (int x = 0; x < Field::X_MAX ; x++ ) {
        for (int y = 0; y < Field::Y_MAX; y++){
            if(field[x][y] == Field::FieldPlace::EMPTY_PLACE){

            }
            else if (field[x][y] == Field::FieldPlace::SHIP_PLACE){
                drawBlueSquare(qp, x, y);
            }
        }
    }
}

void BuilderFieldWidget::drawNotPastedShip(QPainter *qp){
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

void BuilderFieldWidget::mouseMoveEvent(QMouseEvent *event)
{
    emit mouseOnPosition(static_cast<int>(event->position().x() / 30), static_cast<int>(event->position().y() / 30));
}

void BuilderFieldWidget::enterEvent(QEnterEvent *event)
{
    emit mouseOnPosition(static_cast<int>(event->position().x() / 30), static_cast<int>(event->position().y() / 30));
}

void BuilderFieldWidget::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    emit mouseOut();
}

void BuilderFieldWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::LeftButton)
        emit putShipTo(static_cast<int>(event->position().x() / 30), static_cast<int>(event->position().y() / 30));
    if(event->button() == Qt::MouseButton::RightButton)
        emit rotateShip();
}
