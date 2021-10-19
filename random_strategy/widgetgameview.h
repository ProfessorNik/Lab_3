#ifndef WIDGETGAMEVIEW_H
#define WIDGETGAMEVIEW_H

#include <QWidget>
#include <QLabel>
#include "fieldwidget/enemyfieldwidget.h"
#include "fieldwidget/alliedfieldwidget.h"
#include <QPainter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtDebug>
#include <QSpacerItem>
#include <QLabel>
#include <QString>
#include "gamemodel.h"

class WidgetGameView : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetGameView(GameModel* model, QWidget *parent = nullptr);

    void setAlliedName(const QString& name);
    void setEnemyName(const QString& name);

    ~WidgetGameView();
private:
    QLabel* alliedLabel;
    QLabel* enemyLabel;

    AlliedFieldWidget* alliedFieldWidget;
    EnemyFieldWidget* enemyFieldWidget;

    GameModel* model;
    void buildLayout(QVBoxLayout *layout, QLabel *label, AbstractFieldWidget *field);

signals:
     void shootToSell(int x, int y);
public slots:
    void update();
};

#endif // WIDGETGAMEVIEW_H
