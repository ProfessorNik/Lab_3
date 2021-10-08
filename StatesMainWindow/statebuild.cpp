#include "statebuild.h"
#include "buildersinglefield.h"


void StateBuild::changeState(MainWindowModel *context)
{
    auto state = context->getCurState();
    context->changeState(state);
}

WidgetController *StateBuild::getWidget()
{

}

