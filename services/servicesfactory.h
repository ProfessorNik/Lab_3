#ifndef SERVICESFACTORY_H
#define SERVICESFACTORY_H

#include "iservice.h"
#include "QSharedPointer"

class Session;

class ServicesFactory
{
public:
    typedef enum Services{
        GAME_SERVICE,
        BUILDER_SERVICE,
        MAIN_MENU_SERVICE,
        LOCAL_GAME_SETTINGS_SERVICE
    } Services;

    static QSharedPointer<IService> buildService(Services service, Session* session);
};

#endif // SERVICESFACTORY_H
