#ifndef IGAMEDATAMODEL_H
#define IGAMEDATAMODEL_H

#include <QObject>

class IGameDataModel : public QObject
{
    Q_OBJECT
public:
    explicit IGameDataModel(QObject *parent = nullptr);

    typedef enum GamerStatus{
        GAME,
        BUILD,
        VAIT
    }GamerStatus;

    virtual int getAmountGames() const = 0;
    virtual int getScoreG1() const = 0;
    virtual int getScoreG2() const = 0;
    virtual GamerStatus getStatusG1() const = 0;
    virtual GamerStatus getStatusG2() const = 0;
    virtual const QString& getNameG1() const = 0;
    virtual const QString& getNameG2() const = 0;
    virtual bool isEndGame() const = 0;
signals:
    void changed();
};

#endif // IGAMEDATAMODEL_H
