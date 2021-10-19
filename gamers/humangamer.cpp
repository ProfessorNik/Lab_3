#include "humangamer.h"

HumanGamer::HumanGamer(Session* session, QObject *parent) : IGamer(parent), session(session)
{
    model = new GameModel(session->getField());
    view = new WidgetGameView(model);
    connect(view, &WidgetGameView::shootToSell, this, &HumanGamer::tryShoot);
    session->showWidget(view);
    step = false;
}


bool HumanGamer::isAllowedSell(int x, int y)
{
    return model->isAllowedCell(x, y);
}

Field::FieldPlace HumanGamer::shootTo(int x, int y)
{
    return model->shoot(x, y);
}

void HumanGamer::changeStep(bool step)
{
    this->step = step;
}

void HumanGamer::tryShoot(int x, int y)
{
    if(step)
        emit shoot(x, y);
}

void HumanGamer::updateEnemyField(int x, int y, Field::FieldPlace place)
{
    model->responseOnShoot(x, y, place);
}

HumanGamer::~HumanGamer()
{
    delete view;
    delete model;
}
