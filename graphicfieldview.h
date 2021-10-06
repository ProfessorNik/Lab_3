#ifndef GRAPHICFIELDVIEW_H
#define GRAPHICFIELDVIEW_H

#include <QWidget>
#include <QPainter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtDebug>
#include <QSpacerItem>
#include <QLabel>
#include "alliedsinglefield.h"
#include "enemysinglefield.h"
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
    EnemySingleField* enemyField;
    QLabel* alliedLabel;
    AlliedSingleField* alliedField;

    void buildLayout(QVBoxLayout *layout, QLabel *label, AbstractSingleField *field);
protected:
    void paintEvent(QPaintEvent *event);

};

#endif // GRAPHICFIELDVIEW_H
