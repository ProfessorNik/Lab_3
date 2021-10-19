#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include "user.h"
#include "../mainwindow.h"
#include "../field/alliedfield.h"
#include "services/servicesfactory.h"
#include <QSharedPointer>

class IService;
class ServicesFactory;

class Session : public QObject
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

    void showWidget(QWidget* widget);

    bool isEmptyField();
    const AlliedField &getField();
    void setField(const AlliedField &newField);

    void changeService(ServicesFactory::Services service);
    void changeMode(Mode mode);
//    const User& getUser() const;

    Mode getMode() const;
//signals:
//    void serviceChanged();
//private slots:
//    void doDeleteLater();
private:
    void defaultSettings();

    QSharedPointer<IService> lastService;
    QSharedPointer<IService> service;
    MainWindow* window;
    User* user;
    Mode mode;
    bool online;
};

#endif // SESSION_H
