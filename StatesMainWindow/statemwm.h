#ifndef STATEMWM_H
#define STATEMWM_H

#include "mainwindowmodel.h"
#include "widgetcontroller.h"
#include <QWidget>

class StateMWM
{
public:
    virtual void changeState(MainWindowModel* context) = 0;
    virtual WidgetController* getWidget() = 0;
};

#endif // STATEMWM_H
