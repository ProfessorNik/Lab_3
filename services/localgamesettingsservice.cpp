#include "localgamesettingsservice.h"
#include "data/localuser.h"

LocalGameSettingsService::LocalGameSettingsService(SeaBattleClient *client, QObject *parent) : IService(parent), client(client)
{
    widget = QSharedPointer<LocalGameSettingsWidget>(new LocalGameSettingsWidget);
    connect(widget.data(), &LocalGameSettingsWidget::settingsReady, this, &LocalGameSettingsService::gameSettingsReady);
    connect(widget.data(), &LocalGameSettingsWidget::mainMenu, this, &LocalGameSettingsService::pressedMenu);
}


void LocalGameSettingsService::make()
{
    client->showWidget(widget.data());
}

void LocalGameSettingsService::gameSettingsReady()
{
    FactoryGamers::Gamers gamer1 = widget->getG1();
    QSharedPointer<IUser> user1 = QSharedPointer<IUser>(new LocalUser(widget->getNameG1()));
    FactoryGamers::Gamers gamer2 = widget->getG2();
    QSharedPointer<IUser> user2 =  QSharedPointer<IUser>(new LocalUser(widget->getNameG2()));
    int amountGame = widget->getAmountGames();
    QSharedPointer<LocalGameData> data = QSharedPointer<LocalGameData>(new LocalGameData(
                                                                           gamer1,
                                                                           user1,
                                                                           gamer2,
                                                                           user2,
                                                                           amountGame));
    client->setLocalGameData(data);
    client->changeService(ServicesFactory::GAME_SERVICE);
}

void LocalGameSettingsService::pressedMenu()
{
    client->changeService(ServicesFactory::MAIN_MENU_SERVICE);
}
