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

    virtual int getAmountGames() = 0;
    virtual int getScoreG1() = 0;
    virtual int getScoreG2() = 0;
    virtual GamerStatus getStatusG1() = 0;
    virtual GamerStatus getStatusG2() = 0;
signals:
    void changed();
};

#endif // IGAMEDATAMODEL_H
