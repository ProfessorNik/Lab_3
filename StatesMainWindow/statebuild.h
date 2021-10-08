#ifndef STATEBUILD_H
#define STATEBUILD_H

#include "statemwm.h"
#include "widgetcontroller.h"

class StateBuild : public StateMWM
{
public:
    void changeState(MainWindowModel *context) override;
    WidgetController* getWidget() override;
};

#endif // STATEBUILD_H
