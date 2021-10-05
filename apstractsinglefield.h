#ifndef APSTRACTSINGLEFIELD_H
#define APSTRACTSINGLEFIELD_H

#include <QWidget>
#include <QPainter>
#include "field.h"

class SingleField : public QWidget
{
    Q_OBJECT
public:
    explicit SingleField(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void drawLines(QPainter *qp);

    const int STEP = 30;
    const int X1 = 0;
    const int Y1 = 0;
    const int LEN_X = 300;
    const int LEN_Y = 300;

    //https://colorscheme.ru/#3e31Pw0w0w0w0
    const QColor OUTLINE_BACKGROUND_COLOR = Qt::black;
    const QColor BACKGROUND_COLOR = "#5DD0C0";
    const QColor CROSS_COLOR = "#A60000";
    const QColor SHIP_OUTLINE_COLOR = "#00685A";
    const QColor SHIP_INLINE_COLOR = "#1E786C";
    const QColor DIAG_SQUARE_COLOR = Qt::black;

    virtual void drawField(QPainter* qp)
    {

    }
private:


    void drawCross(QPainter *qp, int x, int y);
    void drawBlueSquare(QPainter *qp, int x, int y);
    void drawDiagSquare(QPainter *qp, int x, int y);
};

#endif // APSTRACTSINGLEFIELD_H
