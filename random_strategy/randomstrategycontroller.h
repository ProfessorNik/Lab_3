#ifndef RANDOMSTRATEGYCONTROLLER_H
#define RANDOMSTRATEGYCONTROLLER_H

#include <QObject>
#include <QVector>
#include "gamemodel.h"
#include "widgetgameview.h"

class RandomStrategyController : public QObject
{
    Q_OBJECT
public:
    explicit RandomStrategyController(GameModel* gameModel, QObject *parent = nullptr);

private:
   WidgetGameView* gameView;
   GameModel* gameModel;
};

#endif // RANDOMSTRATEGYCONTROLLER_H
