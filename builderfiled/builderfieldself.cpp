#include "builderfieldself.h"

BuilderFieldSelf::BuilderFieldSelf(QObject *parent) : BuilderFieldStrategy(parent)
{
    builder = QSharedPointer<BuilderField>(new BuilderField);
    connect(builder.data(), &BuilderField::fieldIsReady, this, &BuilderFieldSelf::sendField);
    connect(builder.data(), &BuilderField::closed, this, &BuilderFieldSelf::closed);
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
