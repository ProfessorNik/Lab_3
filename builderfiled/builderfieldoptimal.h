#ifndef BUILDERFIELDOPTIMAL_H
#define BUILDERFIELDOPTIMAL_H

#include "builderfieldstrategy.h"

class BuilderFieldOptimal : public BuilderFieldStrategy
{
    Q_OBJECT
public:
    explicit BuilderFieldOptimal(QObject *parent = nullptr);

    void build() override;
    void forcedClosing() override;
private:
    QVector<QVector<Field::FieldPlace> > optimalBuildField();
    bool checkNeighborhood(const QVector<QVector<Field::FieldPlace> >& field,int x, int y);
    void defaultBuildField(QVector<QVector<Field::FieldPlace> >& field);
};

#endif // BUILDERFIELDOPTIMAL_H
