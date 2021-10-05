#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "observer.h"
#include <QVector>

class Observable
{
public:
    void addObserver(Observer *observer);
    void notifyUpdate();
    private:
       QVector<Observer*> observers;
};

#endif // OBSERVABLE_H
