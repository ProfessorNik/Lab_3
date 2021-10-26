#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include "user.h"
#include "session/iwindowsession.h"
#include "../mainwindow.h"
#include "../field/alliedfield.h"
#include "services/servicesfactory.h"
#include "localgamedata.h"
#include <QSharedPointer>

class IService;
class ServicesFactory;

class Session : public QObject, public IWindowSession
{
    Q_OBJECT
public:
    typedef enum Mode{
        RANDOM_STRATEGY,
        OPTIMAL_STRATEGY,
        INTERACTIVE_SESSION,
    }Mode;


    explicit Session(QObject *parent = nullptr);

    void start();

    bool isOnline() const;
    const QString& getUserName();

    void showWidget(QWidget* widget) override;

    bool isEmptyField();
//    const AlliedField &getField();
//    void setField(const AlliedField &newField);

    void changeService(ServicesFactory::Services service);
    void changeMode(Mode mode);
//    const User& getUser() const;

    Mode getMode() const;
//signals:
//    void serviceChanged();
//private slots:
    //    void doDeleteLater();
    QSharedPointer<LocalGameData> getLocalGameData() const;
    void setLocalGameData(QSharedPointer<LocalGameData> newLocalgd);

private:
    void defaultSettings();

    QSharedPointer<IService> lastService;
    QSharedPointer<IService> service;
    QSharedPointer<LocalGameData> localgd;
    MainWindow* window;
    User* user;
    Mode mode;
    bool online;
};

#endif // SESSION_H
