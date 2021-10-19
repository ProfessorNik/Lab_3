#include "builderservice.h"
#include "../data/session.h"

BuilderService::BuilderService(Session *session, QObject *parent) : IService(parent), session(session)
{
    builder = new BuilderField;
    connect(builder, &BuilderField::fieldIsReady, this, &BuilderService::startGame);
}

void BuilderService::startGame(const QVector<QVector<Field::FieldPlace> > &field)
{
    session->setField(AlliedField(field));
    session->changeService(ServicesFactory::GAME_SERVICE);
}


void BuilderService::make()
{
    session->showWidget(builder);
}
