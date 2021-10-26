#ifndef BUILDERFIELDRANDOM_H
#define BUILDERFIELDRANDOM_H

#include "builderfieldstrategy.h"

class BuilderFieldRandom : public BuilderFieldStrategy
{
    Q_OBJECT

public:
    explicit BuilderFieldRandom(QObject *parent = nullptr);

    void build() override;
private:
    static QVector<QVector<Field::FieldPlace> > randomBuildField();
    static bool checkNeighborhood(const QVector<QVector<Field::FieldPlace> >& field, int x, int y);
    static void defultBuildField(QVector<QVector<Field::FieldPlace> >& field);
};

#endif // BUILDERFIELDRANDOM_H
