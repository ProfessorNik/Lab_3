#include "randomstrategycontroller.h"

RandomStrategyController::RandomStrategyController(GameModel *gameModel, QObject *parent) : QObject(parent)
{
    this->gameModel = gameModel;
    gameView = new WidgetGameView(gameModel);
    gameView->show();
}
