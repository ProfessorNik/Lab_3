#ifndef BUILDERSERVICE_H
#define BUILDERSERVICE_H

#include "iservice.h"
#include "../builderfiled/builderfield.h"

class Session;

class BuilderService : public IService
{
    Q_OBJECT
public:
    explicit BuilderService(Session* session, QObject *parent = nullptr);

private:
    Session* session;
    BuilderField* builder;

private slots:
    void startGame(const QVector<QVector<Field::FieldPlace> >& field);

    // IService interface
public:
    void make() override;
};

#endif // BUILDERSERVICE_H
