#ifndef ALLIEDFIELD_H
#define ALLIEDFIELD_H

#include "field.h"

class AlliedField : public Field
{
    Q_OBJECT
public:
    explicit AlliedField(const QVector<QVector<FieldPlace> >& field, QObject *parent = nullptr);
    AlliedField(const AlliedField& other);
    const QVector<QVector<FieldPlace> > &getField() const override;
    const AlliedField& operator=(const AlliedField& other);

    bool isAllowedCell(int x, int y);
    Field::FieldPlace shootTo(int x, int y);

private:
    QVector<QVector<FieldPlace> > field;

    bool checkOnKilledShip(int x, int y);
    void changeToKilledShip(int x, int y);
    bool checkOHForOneFieldShip(int x, int y);
};

#endif // ALLIEDFIELD_H
