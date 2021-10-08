#ifndef MAINWINDOWMODEL_H
#define MAINWINDOWMODEL_H

#include <QObject>
#include <QWidget>
#include <observable.h>

class MainWindowModel : public QObject, public Observable
{
    Q_OBJECT
public:
    typedef enum State{
        MAIN_MENU,
        INTERACTIVE_SESSION,
        RANDOM_SESSION,
        OPTIMAL_STRATEGY,
        STATISTICS
    } State;

    explicit MainWindowModel(QObject *parent = nullptr);

    void changeState(State state);
    QWidget* getCurWidget();
    State getCurState() const;

signals:

private:
    State curState;
};

#endif // MAINWINDOWMODEL_H
