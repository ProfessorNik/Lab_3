#ifndef IGAMER_H
#define IGAMER_H

#include <QObject>
#include "../field/field.h"


class IGamer : public QObject
{
    Q_OBJECT
public:
    explicit IGamer(QObject *parent = nullptr);

    virtual bool isAllowedSell(int x, int y) = 0;
    virtual Field::FieldPlace shootTo(int x, int y) = 0;
    virtual void updateEnemyField(int x, int y, Field::FieldPlace place) = 0;
    virtual void changeStep(bool step) = 0;
signals:
    void shoot(int x, int y);
};

#endif // IGAMER_H
