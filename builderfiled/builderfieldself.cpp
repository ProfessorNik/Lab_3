#include "builderfieldself.h"

BuilderFieldSelf::BuilderFieldSelf(QObject *parent) : BuilderFieldStrategy(parent)
{
    builder = QSharedPointer<BuilderFieldGraphic>(new BuilderFieldGraphic);
    connect(builder.data(), &BuilderFieldGraphic::fieldIsReady, this, &BuilderFieldSelf::sendField);
    connect(builder.data(), &BuilderFieldGraphic::closed, this, &BuilderFieldSelf::closed);
}


void BuilderFieldSelf::build()
{
    builder->refactor();
    builder->show();
}

void BuilderFieldSelf::sendField(QVector<QVector<Field::FieldPlace> > field)
{
    builder->hide();
    emit isBuilded(AlliedField(field));
}


void BuilderFieldSelf::forcedClosing()
{
    builder->hide();
}
