#ifndef GRAPHICFIELDVIEW_H
#define GRAPHICFIELDVIEW_H

#include <QWidget>
#include <QPainter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtDebug>
#include <QSpacerItem>
#include <QLabel>
#include "singlefield.h"
#include "interfacefiledview.h"
#include "observer.h"
#include "observable.h"
#include "fieldmodel.h"

class GraphicFieldView : public QWidget, public InterfaceFiledView, public Observer
{
    Q_OBJECT
public:
    explicit GraphicFieldView(FieldModel* model, QWidget *parent = nullptr);
    void update() override;
private:
    FieldModel* model;
    QLabel* enemyLabel;
    SingleField* enemyField;
    QLabel* alliedLabel;
    SingleField* alliedField;

    void buildLayout(QVBoxLayout *layout, QLabel *label, SingleField *field);
protected:
    void paintEvent(QPaintEvent *event);
    void drawLines(QPainter *qp);
};

#endif // GRAPHICFIELDVIEW_H
