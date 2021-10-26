#ifndef IUSER_H
#define IUSER_H

#include <QObject>
#include <QString>


class IUser : public QObject
{
    Q_OBJECT
public:
    typedef enum Gamers{
        HumanGamer,
        RandomGamer,
        OptimalGamer
    } Gamers;
    explicit IUser(QObject *parent = nullptr);
    virtual const QString& getName() = 0;
    virtual void setGamerStatus(Gamers gamer) = 0;
};

#endif // IUSER_H
