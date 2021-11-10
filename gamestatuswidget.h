#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "igamedatamodel.h"
#include <QSharedPointer>
#include "endgamemessagebox.h"

namespace Ui {
class GameWidget;
}

class GameStatusWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameStatusWidget(QSharedPointer<IGameDataModel> model, QWidget *parent = nullptr);
    ~GameStatusWidget();

private:
    Ui::GameWidget *ui;
    QSharedPointer<IGameDataModel> model;
    QSharedPointer<EndGameMessageBox> mb;
private slots:
    void update();
signals:
    void exit();
};

#endif // GAMEWIDGET_H
