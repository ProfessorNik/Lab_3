#include "servicesfactory.h"
#include "gameservice.h"
#include "mainmenuservice.h"
#include "localgamesettingsservice.h"
#include "../data/seabattleclient.h"
#include <QString>

QSharedPointer<IService> ServicesFactory::buildService(Services service, SeaBattleClient *client)
{
    if(service == Services::GAME_SERVICE)
        return QSharedPointer<IService>(new GameService(client));
    if(service == Services::MAIN_MENU_SERVICE)
        return QSharedPointer<IService>(new MainMenuService(client));
    if(service == Services::LOCAL_GAME_SETTINGS_SERVICE)
        return QSharedPointer<IService>(new LocalGameSettingsService(client));
    return nullptr;
}
