#include "servicesfactory.h"
#include "gameservice.h"
#include "mainmenuservice.h"
#include "localgamesettingsservice.h"
#include "../data/seabattleclient.h"
#include <QString>

QSharedPointer<IService> ServicesFactory::buildService(Services service, SeaBattleClient *session)
{
    if(service == Services::GAME_SERVICE)
        return QSharedPointer<IService>(new GameService(session));
    if(service == Services::MAIN_MENU_SERVICE)
        return QSharedPointer<IService>(new MainMenuService(session));
    if(service == Services::LOCAL_GAME_SETTINGS_SERVICE)
        return QSharedPointer<IService>(new LocalGameSettingsService(session));
    return nullptr;
}
