#ifndef SHIPVIEW_H
#define SHIPVIEW_H

#include <QWidget>
#include <QPainter>

class ShipView : public QWidget
{
    Q_OBJECT
private:
    const QColor SHIP_OUTLINE_COLOR = "#00685A";
    const QColor SHIP_INLINE_COLOR = "#1E786C";
    int size;
public:
    ShipView(int size, QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void drawBlueSquare(QPainter* qp, int pos);

signals:
    void shipSelected(int size);

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // SHIPVIEW_H
