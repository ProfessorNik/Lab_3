#ifndef ISERVICE_H
#define ISERVICE_H

#include <QObject>


class IService : public QObject
{
    Q_OBJECT
public:
    explicit IService(QObject *parent = nullptr);

    virtual void make() = 0;
signals:

};

#endif // ISERVICE_H
