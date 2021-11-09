#ifndef COMPUTERGAMER_H
#define COMPUTERGAMER_H

#include "igamer.h"
#include "../random_strategy/gamemodel.h"
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

    static void defultBuildField(QVector<QVector<Field::FieldPlace> > &field);
    static QVector<QVector<Field::FieldPlace> > randomBuildField();
protected:

    QSharedPointer<GameModel> model;
    virtual void makeStep(int &x, int &y) = 0;
    virtual void rebuildCoords();
private:
    static bool checkNeighborhood(const QVector<QVector<Field::FieldPlace> >&field, int x, int y);

    QSharedPointer<IUser> user;
    QSharedPointer<BuilderFieldStrategy> builder;
    Field::FieldPlace lastShoot;

    bool rebuilded;

private slots:
    void rebuildGamer(AlliedField field);


    // IGamer interface
public:
    bool isWasted() override;

    // IGamer interface
protected:
    void forcedClosing() override;
    Field::FieldPlace getLastShoot() const;
};

#endif // COMPUTERGAMER_H
