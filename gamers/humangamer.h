#ifndef HUMANGAMER_H
#define HUMANGAMER_H

#include "igamer.h"
#include "../data/session.h"
#include "../random_strategy/widgetgameview.h"
#include "../random_strategy/gamemodel.h"

class HumanGamer : public IGamer
{
    Q_OBJECT
public:
    explicit HumanGamer(Session *session, QObject *parent = nullptr);

    bool isAllowedSell(int x, int y) override;
    Field::FieldPlace shootTo(int x, int y) override;
    void changeStep(bool step) override;
    void updateEnemyField(int x, int y, Field::FieldPlace place) override;

    GameModel* getGameModel();

    ~HumanGamer();
private:
    Session* session;
    GameModel* model;
    WidgetGameView* view;

    bool step;
private slots:
    void tryShoot(int x, int y);


};


#endif // HUMANGAMER_H
