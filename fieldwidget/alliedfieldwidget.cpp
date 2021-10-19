#include "alliedfieldwidget.h"

AlliedFieldWidget::AlliedFieldWidget(QWidget *parent) : AbstractFieldWidget(parent)
{
    for(int i = 0; i < Field::X_MAX; i++){
        QVector<Field::FieldPlace> line;
        for(int j = 0; j < Field::Y_MAX; j++)
            line.push_back(Field::FieldPlace::EMPTY_PLACE);
        field.push_back(line);
    }
}

void AlliedFieldWidget::update(const QVector<QVector<Field::FieldPlace> > &field)
{
    this->field = field;
    this->repaint();
}

void AlliedFieldWidget::drawField(QPainter *qp)
{
    for (int x = 0; x < Field::X_MAX ; x++ ) {
        for (int y = 0; y < Field::Y_MAX; y++){
            if(field[x][y] == Field::FieldPlace::EMPTY_PLACE){

            }
            else if (field[x][y] == Field::FieldPlace::EMPTY_WRECKED_PLACE){
                drawDiagSquare(qp, x, y);
            }
            else if (field[x][y] == Field::FieldPlace::SHIP_PLACE){
                drawBlueSquare(qp, x, y);
            }
            else if (field[x][y] == Field::FieldPlace::SHIP_WRECKED_PLACE){
                drawBlueSquare(qp, x, y);
                drawCross(qp, x, y);
            }
            else if (field[x][y] == Field::FieldPlace::SHIP_KILLED_PLACE){
                drawBlueSquare(qp, x, y);
                drawCross(qp, x, y);
            }
        }
    }
}
