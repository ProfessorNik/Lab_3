#ifndef LOCALUSER_H
#define LOCALUSER_H

#include "iuser.h"
#include <QObject>

class LocalUser : public IUser
{
    Q_OBJECT
public:
    explicit LocalUser(QString name, QObject *parent = nullptr);

private:
    QString name;
    Gamers gamerStatus;

    // IUser interface
public:
    const QString& getName() override;
    void setGamerStatus(Gamers gamer) override;
};

#endif // LOCALUSER_H
