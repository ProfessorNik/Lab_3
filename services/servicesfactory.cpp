#include "servicesfactory.h"
#include "gameservice.h"
#include "builderservice.h"
#include "mainmenuservice.h"
#include "../data/session.h"
#include <QString>

QSharedPointer<IService> ServicesFactory::buildService(Services service, Session *session)
{
    if(service == Services::BUILDER_SERVICE)
        return QSharedPointer<IService>(new BuilderService(session));
    if(service == Services::GAME_SERVICE)
        return QSharedPointer<IService>(new GameService(session));
    if(service == Services::MAIN_MENU_SERVECE)
        return QSharedPointer<IService>(new MainMenuService(session));
    return nullptr;
}
