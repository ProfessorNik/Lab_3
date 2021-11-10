#ifndef IGAMECONTROLLER_H
#define IGAMECONTROLLER_H

#include <QObject>
#include "../data/seabattleclient.h"

class IGameController : public QObject
{
    Q_OBJECT
public:
    IGameController(QObject* parent = nullptr);

    virtual void startGame() = 0;
signals:
    void endGame();
};

#endif // IGAMECONTROLLER_H
