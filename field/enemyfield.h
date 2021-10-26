#ifndef ENEMYFIELD_H
#define ENEMYFIELD_H

#include "field.h"

class EnemyField : public Field
{
public:
    explicit EnemyField(QObject *parent = nullptr);

    void refactor();
    const QVector<QVector<FieldPlace> > &getField() const override;
    void update(int x, int y, Field::FieldPlace cell);

private:
    QVector<QVector<FieldPlace> > field;
    void defultBuildFiled();
    void changeToKilledShip(int x, int y);
    void pasteEmptyPlaces(int x, int y);
};

#endif // ENEMYFIELD_H
