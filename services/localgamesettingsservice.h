#ifndef LOCALGAMESETTINGSSERVICE_H
#define LOCALGAMESETTINGSSERVICE_H

#include "iservice.h"
#include "../localgamesettingswidget.h"
#include "../data/localgamedata.h"
#include "../data/session.h"

class LocalGameSettingsService : public IService
{
    Q_OBJECT
public:
    explicit LocalGameSettingsService(Session* session, QObject *parent = nullptr);

    void make() override;
private slots:
    void gameSettingsReady();
private:
    Session *session;
    QSharedPointer<LocalGameSettingsWidget> widget;
};

#endif // LOCALGAMESETTINGSSERVICE_H
