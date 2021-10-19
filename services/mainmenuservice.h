#ifndef MAINMENUSERVICE_H
#define MAINMENUSERVICE_H

#include "iservice.h"
#include <QObject>
#include "mainmenu.h"

class Session;

class MainMenuService : public IService
{
public:
    explicit MainMenuService(Session* session, QObject *parent = nullptr);

private:
    Session* session;
    MainMenu* mainMenu;

private slots:
    void randomStrategy();

    // IService interface
public:
    void make() override;
};

#endif // MAINMENUSERVICE_H
