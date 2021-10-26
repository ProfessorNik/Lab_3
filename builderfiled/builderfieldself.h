#ifndef BUILDERFIELDSELF_H
#define BUILDERFIELDSELF_H

#include "builderfieldstrategy.h"
#include "builderfield.h"
#include <QSharedPointer>

class BuilderFieldSelf : public BuilderFieldStrategy
{
    Q_OBJECT
public:
    explicit BuilderFieldSelf(QObject *parent = nullptr);

    void build() override;

private:
    QSharedPointer<BuilderField> builder;
private slots:
    void sendField(QVector<QVector<Field::FieldPlace> > field);
};

#endif // BUILDERFIELDSELF_H
