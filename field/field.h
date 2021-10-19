#ifndef FIELD_H
#define FIELD_H

#include <QObject>

class Field : public QObject
{
    Q_OBJECT
public:
    typedef enum FieldPlace{
        SHIP_PLACE,
        EMPTY_PLACE,
        SHIP_WRECKED_PLACE,
        SHIP_KILLED_PLACE,
        EMPTY_WRECKED_PLACE
    } FieldPlace;

    explicit Field(QObject *parent = nullptr);

    virtual const QVector<QVector<FieldPlace> >& getField() const = 0;

    static const int X_MAX = 10;
    static const int Y_MAX = 10;

    static const int NUM_SINGLE_DECK_SHIPS = 4;
    static const int NUM_DOUBLE_DECK_SHIPS = 3;
    static const int NUM_THREE_DECK_SHIPS = 2;
    static const int NUM_FOUR_DECK_SHIPS = 1;

    static const int SHIP_MAX_SIZE = 4;
};

#endif // FIELD_H
