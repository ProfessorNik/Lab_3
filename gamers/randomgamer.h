#ifndef RANDOMGAMER_H
#define RANDOMGAMER_H

#include "computergamer.h"

class RandomGamer : public ComputerGamer
{
    Q_OBJECT
public:
    explicit RandomGamer(QSharedPointer<IUser> user, QSharedPointer<BuilderFieldStrategy> builder, QObject *parent = nullptr);

    // ComputerGamer interface
protected:
    void makeStep(int &x, int &y) override;

    // IGamer interface
public:
    FactoryGamers::Gamers getGamerVariation() override;

};

#endif // RANDOMGAMER_H
