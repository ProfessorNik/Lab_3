#ifndef SHIPWIDGET_H
#define SHIPWIDGET_H

#include <QWidget>
#include <QPainter>

class ShipWidget : public QWidget
{
    Q_OBJECT
private:
    const QColor SHIP_OUTLINE_COLOR = "#00685A";
    const QColor SHIP_INLINE_COLOR = "#1E786C";
    int size;
public:
    ShipWidget(int size, QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void drawBlueSquare(QPainter* qp, int pos);

signals:
    void shipSelected(int size);

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // SHIPWIDGET_H
