#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "igamedatamodel.h"
#include <QSharedPointer>

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QSharedPointer<IGameDataModel> model, QWidget *parent = nullptr);
    ~GameWidget();

private:
    Ui::GameWidget *ui;
    QSharedPointer<IGameDataModel> model;
private slots:
    void update();
};

#endif // GAMEWIDGET_H
