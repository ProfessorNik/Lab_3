#ifndef COMPUTERGAMER_H
#define COMPUTERGAMER_H

#include "igamer.h"
#include "../random_strategy/gamemodel.h"

class ComputerGamer : public IGamer
{
    Q_OBJECT
public:
    explicit ComputerGamer(QObject *parent = nullptr);

    bool isAllowedSell(int x, int y) override;
    Field::FieldPlace shootTo(int x, int y) override;
    void changeStep(bool step) override;
      void updateEnemyField(int x, int y, Field::FieldPlace place) override;

    static void defultBuildField(QVector<QVector<Field::FieldPlace> > &field);
    static QVector<QVector<Field::FieldPlace> > randomBuildField();
protected:
    GameModel* model;
    virtual void makeStep(int &x, int &y) = 0;
private:
    static bool checkNeighborhood(const QVector<QVector<Field::FieldPlace> >&field, int x, int y);
};

#endif // COMPUTERGAMER_H
