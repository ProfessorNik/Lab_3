#ifndef LOCALGAMESETTINGSSERVICE_H
#define LOCALGAMESETTINGSSERVICE_H

#include "iservice.h"
#include "../localgamesettingswidget.h"
#include "../data/localgamedata.h"
#include "../data/seabattleclient.h"

class LocalGameSettingsService : public IService
{
    Q_OBJECT
public:
    explicit LocalGameSettingsService(SeaBattleClient* client, QObject *parent = nullptr);

    void make() override;
private slots:
    void gameSettingsReady();
    void pressedMenu();
private:
    SeaBattleClient *client;
    QSharedPointer<LocalGameSettingsWidget> widget;
};

#endif // LOCALGAMESETTINGSSERVICE_H
