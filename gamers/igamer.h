#ifndef IGAMER_H
#define IGAMER_H

#include <QObject>
#include "../field/field.h"
#include <QString>
#include "factorygamers.h"

class AlliedField;

class IGamer : public QObject
{
    Q_OBJECT
public:
    explicit IGamer(QObject *parent = nullptr);

    virtual bool isAllowedSell(int x, int y) = 0;
    virtual Field::FieldPlace shootTo(int x, int y) = 0;
    virtual void updateEnemyField(int x, int y, Field::FieldPlace place) = 0;
    virtual void changeStep(bool step) = 0;
    virtual const AlliedField & getField() = 0;
    virtual bool isWasted() = 0;
    virtual void startGame() = 0;
    virtual bool isRenewed() = 0;
    virtual void endGame() = 0;
    virtual FactoryGamers::Gamers getGamerVariation() = 0;
    virtual void rebuild() = 0;

signals:
    void shoot(int x, int y);
    void wasted();
    void fieldRebuilded();
};

#endif // IGAMER_H
