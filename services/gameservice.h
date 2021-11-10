#ifndef GAMESERVICE_H
#define GAMESERVICE_H

#include "iservice.h"
#include "../gamecontrollers/localgamecontorller.h"
#include "../gamestatuswidget.h"
#include "../endgamemessagebox.h"

class SeaBattleClient;

class GameService : public IService
{
    Q_OBJECT
public:

    explicit GameService(SeaBattleClient* session, QObject *parent = nullptr);

    void make() override;
private:

    QSharedPointer<LocalGameContorller> gc;
    QSharedPointer<GameStatusWidget> view;
    QSharedPointer<EndGameMessageBox> mBox;
    SeaBattleClient *session;


private slots:
    void exit();

};

#endif // GAMESERVICE_H
