#ifndef HUMANGAMER_H
#define HUMANGAMER_H

#include "igamer.h"
#include "../data/seabattleclient.h"
#include "../data/iuser.h"
#include "../gameMV/gamemodel.h"
#include "../gameMV/widgetgameview.h"
#include <QSharedPointer>
#include "factorygamers.h"
#include "irebuildgamer.h"
#include "../builderfiled/builderfieldstrategy.h"
#include "../builderfiled/builderfieldself.h"

class HumanGamer : public IGamer, public IRebuildGamer
{
    Q_OBJECT
public:
    explicit HumanGamer(QSharedPointer<IUser> user, QSharedPointer<BuilderFieldStrategy> builder, QObject *parent = nullptr);

    bool isAllowedSell(int x, int y) override;
    Field::FieldPlace shootTo(int x, int y) override;
    void changeStep(bool step) override;
    void updateEnemyField(int x, int y, Field::FieldPlace place) override;
    const AlliedField & getField() override;


    void startBattle() override;
    void rebuild() override;
    bool isRenewed() override;
    bool isWasted() override;
    void endBattle() override;

    FactoryGamers::Gamers getGamerVariation() override;

    ~HumanGamer();
private slots:
    void rebuildGamer(AlliedField field) override;
private:
    QSharedPointer<BuilderFieldStrategy> builder;
    QSharedPointer<GameModel> model;
    QSharedPointer<WidgetGameView> view;
    QSharedPointer<IUser> user;

    bool step;
    bool rebilded;
private slots:
    void tryShoot(int x, int y);

    // IGamer interface
public:
    void forcedClosing() override;

    // IGamer interface
public:
    const QString& getName() override;
};


#endif // HUMANGAMER_H
