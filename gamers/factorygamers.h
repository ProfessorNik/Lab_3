#ifndef FACTORYGAMERS_H
#define FACTORYGAMERS_H

#include <QObject>
#include "../data/session/iwindowsession.h"
#include "../data/iuser.h"

class IGamer;

class FactoryGamers : public QObject
{
    Q_OBJECT
public:
    explicit FactoryGamers(QObject *parent = nullptr);

    enum Gamers{
        HUMAN_GAMER,
        RANDOM_GAMER,
        OPTIMAL_GAMER
    };

    static QSharedPointer<IGamer> createGamer(Gamers gamer, QSharedPointer<IUser> user);
signals:

};

#endif // FACTORYGAMERS_H
