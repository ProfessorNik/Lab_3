#include "localgamesettingsservice.h"
#include "data/localuser.h"

LocalGameSettingsService::LocalGameSettingsService(SeaBattleClient *session, QObject *parent) : IService(parent), session(session)
{
    widget = QSharedPointer<LocalGameSettingsWidget>(new LocalGameSettingsWidget);
    connect(widget.data(), &LocalGameSettingsWidget::settingsReady, this, &LocalGameSettingsService::gameSettingsReady);
    connect(widget.data(), &LocalGameSettingsWidget::mainMenu, this, &LocalGameSettingsService::pressedMenu);
}


void LocalGameSettingsService::make()
{
    session->showWidget(widget.data());
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
    session->setLocalGameData(data);
    session->changeService(ServicesFactory::GAME_SERVICE);
}

void LocalGameSettingsService::pressedMenu()
{
    session->changeService(ServicesFactory::MAIN_MENU_SERVICE);
}
