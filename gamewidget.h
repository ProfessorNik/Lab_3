#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "igamedatamodel.h"
#include <QSharedPointer>
#include "endgamemessagebox.h"

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
    QSharedPointer<EndGameMessageBox> mb;
private slots:
    void update();
signals:
    void exit();
};

#endif // GAMEWIDGET_H
