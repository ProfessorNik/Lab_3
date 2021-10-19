#include "abstractfieldwidget.h"


AbstractFieldWidget::AbstractFieldWidget(QWidget *parent) : QWidget(parent)
{
    //this->setSizeIncrement(300, 300);
    this->setFixedSize(300, 300);
}


void AbstractFieldWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter qp(this);
    qp.save();

    qp.setPen(QPen(OUTLINE_BACKGROUND_COLOR, 4, Qt::SolidLine));
    qp.setBrush(QBrush(BACKGROUND_COLOR));
    qp.drawRect(X1, Y1, LEN_X, LEN_Y);
    qp.restore();

    drawLines(&qp);

    drawField(&qp);

//    drawDiagSquare(&qp, 3, 3);
//    drawDiagSquare(&qp, 3, 5);
//    drawDiagSquare(&qp, 2, 4);
//    drawDiagSquare(&qp, 4, 4);
//    drawBlueSquare(&qp, 3, 4);
//    drawCross(&qp, 3, 4);

//    drawDiagSquare(&qp, 3, 3);
//    drawDiagSquare(&qp, 3, 3);
//    drawDiagSquare(&qp, 9, 9);
//    drawBlueSquare(&qp, 6, 3);

//    //drawCross(&qp, 6, 3);
//    drawBlueSquare(&qp, 7, 3);
//    //drawCross(&qp, 7, 3);
//    drawBlueSquare(&qp, 8, 3);

//    drawRedSquare(&qp, 6, 3);
//    drawRedSquare(&qp, 6, 4);
//    drawRedSquare(&qp, 6, 5);
}

void AbstractFieldWidget::drawDiagSquare(QPainter* qp, int x, int y){
    qp->save();
    qp->setPen(QPen(QBrush(OUTLINE_BACKGROUND_COLOR), 0.5, Qt::SolidLine));
    qp->setBrush(QBrush(DIAG_SQUARE_COLOR, Qt::BDiagPattern));
    qp->drawRect(X1 + x*STEP, y*STEP + Y1, STEP, STEP);
    qp->restore();
}

void AbstractFieldWidget::drawRedSquare(QPainter *qp, int x, int y)
{
    qp->save();
    QPen pen(QBrush(SHIP_RED_OUTLINE_COLOR), 3, Qt::SolidLine);
    qp->setBrush(QBrush(SHIP_RED_INLINE_COLOR));
    qp->setPen(pen);
    qp->drawRect(X1 + x*STEP, y*STEP + Y1, STEP, STEP);
    qp->restore();
}

void AbstractFieldWidget::drawBlueSquare(QPainter* qp, int x, int y){
    qp->save();
    qp->setBrush(QBrush(SHIP_INLINE_COLOR));
    qp->setPen(QPen(QBrush(SHIP_OUTLINE_COLOR), 3, Qt::SolidLine));
    qp->drawRect(X1 + x*STEP, y*STEP + Y1, STEP, STEP);
    qp->restore();
}

void AbstractFieldWidget::drawCross(QPainter *qp, int x, int y){
    qp->save();
    QPen pen(QBrush(CROSS_COLOR), 2, Qt::SolidLine);
    qp->setPen(pen);
    qp->drawLine(X1 + x*STEP, y*STEP + Y1, X1 + (x+1) *STEP, (1+y)*STEP + Y1);
    qp->drawLine(X1 + (x+1) *STEP, y*STEP + Y1 , X1 + x*STEP, Y1 + (y+1)*STEP);
    qp->restore();
}

void AbstractFieldWidget::drawLines(QPainter *qp){
    qp->save();
    QPen pen(OUTLINE_BACKGROUND_COLOR, 0.5, Qt::SolidLine);
    qp->setPen(pen);
    for(int i = 0; i < Field::X_MAX + 1; i++)
        qp->drawLine(X1, i*STEP + Y1, X1 + LEN_X, i*STEP + Y1);

    for(int i = 0; i < Field::Y_MAX + 1; i++)
        qp->drawLine( i*STEP + X1, Y1 , i*STEP + X1, Y1+LEN_Y);
    qp->restore();
}
