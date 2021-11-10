#ifndef SERVICESFACTORY_H
#define SERVICESFACTORY_H

#include "iservice.h"
#include "QSharedPointer"

class SeaBattleClient;

class ServicesFactory
{
public:
    typedef enum Services{
        GAME_SERVICE,
        BUILDER_SERVICE,
        MAIN_MENU_SERVICE,
        LOCAL_GAME_SETTINGS_SERVICE
    } Services;

    static QSharedPointer<IService> buildService(Services service, SeaBattleClient* session);
};

#endif // SERVICESFACTORY_H
