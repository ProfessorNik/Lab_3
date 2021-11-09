#include "factorygamers.h"
#include "humangamer.h"
#include "randomgamer.h"
#include "optimalgamer.h"
#include "../builderfiled/builderfieldself.h"
#include "../builderfiled/builderfieldrandom.h"
#include "../builderfiled/builderfieldrandom.h"

FactoryGamers::FactoryGamers(QObject *parent) : QObject(parent)
{

}

QSharedPointer<IGamer> FactoryGamers::createGamer(Gamers gamer, QSharedPointer<IUser> user)
{
    if(gamer == Gamers::HUMAN_GAMER){
        return QSharedPointer<IGamer>(new HumanGamer(user, QSharedPointer<BuilderFieldStrategy>(new BuilderFieldSelf)));
    }
    if(gamer == Gamers::RANDOM_GAMER){
        return QSharedPointer<IGamer>(new RandomGamer(user, QSharedPointer<BuilderFieldStrategy>(new BuilderFieldRandom)));
    }
    if(gamer == Gamers::OPTIMAL_GAMER){
        return QSharedPointer<IGamer>(new OptimalGamer(user, QSharedPointer<BuilderFieldStrategy>(new BuilderFieldRandom)));
    }
    return nullptr;
}
