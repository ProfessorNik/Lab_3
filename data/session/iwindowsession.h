#ifndef IWINDOWSESSION_H
#define IWINDOWSESSION_H

class QWidget;

class IWindowSession
{
public:
    virtual void showWidget(QWidget* widget) = 0;
};

#endif // IWINDOWSESSION_H
