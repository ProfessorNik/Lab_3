#ifndef BUILDERFIELDSELF_H
#define BUILDERFIELDSELF_H

#include "builderfieldstrategy.h"
#include "builderfieldgraphic.h"
#include <QSharedPointer>

class BuilderFieldSelf : public BuilderFieldStrategy
{
    Q_OBJECT
public:
    explicit BuilderFieldSelf(QObject *parent = nullptr);

    void build() override;

private:
    QSharedPointer<BuilderFieldGraphic> builder;
private slots:
    void sendField(QVector<QVector<Field::FieldPlace> > field);

    // BuilderFieldStrategy interface
public:
    void forcedClosing() override;
};

#endif // BUILDERFIELDSELF_H
