#include "humangamer.h"

HumanGamer::HumanGamer(QSharedPointer<IUser> user, QSharedPointer<BuilderFieldStrategy> builder, QObject *parent) :
    IGamer(parent), builder(builder), user(user)
{
    this->step = false;
    connect(builder.data(), &BuilderFieldStrategy::isBuilded, this, &HumanGamer::rebuildGamer, Qt::QueuedConnection);
    connect(builder.data(), &BuilderFieldStrategy::closed, this, &HumanGamer::closed, Qt::QueuedConnection);
    this->rebilded = false;
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

const AlliedField &HumanGamer::getField()
{
    return model->getAlliedField();
}

FactoryGamers::Gamers HumanGamer::getGamerVariation()
{
    return FactoryGamers::Gamers::HUMAN_GAMER;
}

void HumanGamer::startBattle()
{
    rebilded = false;
    view->show();

}

bool HumanGamer::isRenewed()
{
    return rebilded;
}

void HumanGamer::endBattle()
{
    view->hide();
}

void HumanGamer::rebuildGamer(AlliedField field)
{
    if (model.isNull() || view.isNull()){
        model = QSharedPointer<GameModel>(new GameModel(field));
        connect(model.data(), &GameModel::wasted, this, &HumanGamer::wasted);
        view = QSharedPointer<WidgetGameView>(new WidgetGameView(model));
        connect(view.data(), &WidgetGameView::shootToSell, this, &HumanGamer::tryShoot);
        //connect(view.data(), &WidgetGameView::closed, this, &HumanGamer::closed);
    }
    else{
        model->refactor(field);
        view->update();
    }

    rebilded = true;
    emit fieldRebuilded();
}



HumanGamer::~HumanGamer()
{

}


void HumanGamer::rebuild()
{
    builder->build();
}


bool HumanGamer::isWasted()
{
    return model->isWasted();
}


void HumanGamer::forcedClosing()
{
    if(!view.isNull())
        view->hide();
    builder->forcedClosing();
}
