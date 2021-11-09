#ifndef BUILDERFIELDSTRATEGY_H
#define BUILDERFIELDSTRATEGY_H

#include <QObject>
#include "../field/alliedfield.h"

class BuilderFieldStrategy : public QObject
{
    Q_OBJECT
public:
    explicit BuilderFieldStrategy(QObject *parent = nullptr);

    virtual void build() = 0;
    virtual void forcedClosing() = 0;
signals:
    void isBuilded(AlliedField alliedField);
    void closed();
};

#endif // BUILDERFIELDSTRATEGY_H
