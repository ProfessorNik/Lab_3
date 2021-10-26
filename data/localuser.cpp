#include "localuser.h"

LocalUser::LocalUser(QString name, QObject *parent) : IUser(parent), name(name)
{

}


const QString &LocalUser::getName()
{
    return name;
}

void LocalUser::setGamerStatus(Gamers gamer)
{
    gamerStatus = gamer;
}
