#ifndef FIELD_H
#define FIELD_H

#include<QVector>
#include<QVector2D>

class Field
{
public:
    static const int X_MAX = 10;
    static const int Y_MAX = 10;

    typedef enum FieldPlace{
        SHIP_PLACE,
        EMPTY_PLACE,
        SHIP_WRECKED_PLACE,
        EMPTY_WRECKED_PLACE
    } FieldPlace;
    Field() = default;
    Field(const QVector<QVector<FieldPlace> >& alliedField);

    FieldPlace enemyShootTo(int x, int y);
    void alliedShootTo(int x, int y, const FieldPlace& place);


    const QVector<QVector<FieldPlace> > &getAlliedField() const;

    const QVector<QVector<FieldPlace> > &getEnemyField() const;

private:
    QVector<QVector<FieldPlace> > alliedField;
    QVector<QVector<FieldPlace> > enemyField;

    void fillEnemyField();
};

#endif // FIELD_H
