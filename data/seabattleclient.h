#ifndef SEABATTLECLIENT_H
#define SEABATTLECLIENT_H

#include <QObject>
#include "session/iwindowsession.h"
#include "../mainwindow.h"
#include "../field/alliedfield.h"
#include "services/servicesfactory.h"
#include "localgamedata.h"
#include <QSharedPointer>

class IService;
class ServicesFactory;

class SeaBattleClient : public QObject, public IWindowSession
{
    Q_OBJECT
public:
    typedef enum Mode{
        RANDOM_STRATEGY,
        OPTIMAL_STRATEGY,
        INTERACTIVE_SESSION,
    }Mode;


    explicit SeaBattleClient(QObject *parent = nullptr);

    void start();
    void showWidget(QWidget* widget) override;

    void changeService(ServicesFactory::Services service);

    QSharedPointer<LocalGameData> getLocalGameData() const;
    void setLocalGameData(QSharedPointer<LocalGameData> newLocalgd);

private:
    void defaultSettings();

    QSharedPointer<IService> service;
    QSharedPointer<LocalGameData> localgd;
    MainWindow* window;
    Mode mode;
};

#endif // SEABATTLECLIENT_H
