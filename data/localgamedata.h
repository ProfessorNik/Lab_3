#ifndef LOCALGAMEDATA_H
#define LOCALGAMEDATA_H

#include <QObject>
#include "../gamers/igamer.h"
#include <QSharedPointer>
#include "../data/iuser.h"
#include "../gamers/factorygamers.h"
#include "../igamedatamodel.h"

class IWindowSession;

class LocalGameData : public IGameDataModel
{
    Q_OBJECT
public:

    explicit LocalGameData(FactoryGamers::Gamers gamer1,
                           QSharedPointer<IUser> user1,
                           FactoryGamers::Gamers gamer2,
                           QSharedPointer<IUser> user2,
                           int amountGame,
                           QObject *parent = nullptr);

    void createGamer1(QSharedPointer<IUser> user, int a);
    void createGamer2(QSharedPointer<IUser> user, int a);

    void startGame();

    bool isNextBattle() const;

    QSharedPointer<IGamer> getGamer1() const;
    QSharedPointer<IGamer> getGamer2() const;

    void endGame();
    void forcedClosing();

    void gamer1Win();
    void gamer2Win();


signals:
    void nextGame();
    void gameEnd();

private:
    int amountGame;
    int numGame;
    int scoreG1;
    int scoreG2;
    bool next;
    GamerStatus statusG1;
    GamerStatus statusG2;

    QSharedPointer<IGamer> gamer1;
    QSharedPointer<IGamer> gamer2;

    // IGameDataModel interface
public:
    int getAmountGames() const override;
    int getScoreG1() const override;
    int getScoreG2() const override;
    GamerStatus getStatusG1() const override;
    GamerStatus getStatusG2() const override;
    const QString& getNameG1() const override;
    const QString& getNameG2() const override;

    bool isEndGame() const override;
};

#endif // LOCALGAMEDATA_H
