#ifndef COMPUTERGAMER_H
#define COMPUTERGAMER_H

#include "igamer.h"
#include "../gameMV/gamemodel.h"
#include "../builderfiled/builderfieldstrategy.h"
#include <QSharedPointer>

class ComputerGamer : public IGamer
{
    Q_OBJECT
public:

    explicit ComputerGamer(QSharedPointer<IUser> user, QSharedPointer<BuilderFieldStrategy> builder, QObject *parent = nullptr);

    bool isAllowedSell(int x, int y) override;
    Field::FieldPlace shootTo(int x, int y) override;
    void changeStep(bool step) override;
    void updateEnemyField(int x, int y, Field::FieldPlace place) override;

    const AlliedField &getField() override;
    void startBattle() override;
    bool isRenewed() override;
    void endBattle() override;
    virtual FactoryGamers::Gamers getGamerVariation() override = 0;
    void rebuild() override;
protected:
    typedef struct Shoot{
        int x;
        int y;
        Field::FieldPlace kindPlace;
    } Shoot;

    QSharedPointer<GameModel> model;
    bool isUnknownSell(int x, int y);
    virtual void makeStep(int &x, int &y) = 0;
    virtual void rebuildCoords();
private:
    static bool checkNeighborhood(const QVector<QVector<Field::FieldPlace> >&field, int x, int y);

    QSharedPointer<IUser> user;
    QSharedPointer<BuilderFieldStrategy> builder;
    Shoot lastShoot;

    bool rebuilded;

private slots:
    void rebuildGamer(AlliedField field);


    // IGamer interface
public:
    bool isWasted() override;

    // IGamer interface
protected:
    void forcedClosing() override;
    Shoot getLastShoot() const;

    // IGamer interface
public:
    const QString &getName() override;
};

#endif // COMPUTERGAMER_H
