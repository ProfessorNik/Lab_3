#include "mainwindowmodel.h"


MainWindowModel::MainWindowModel(QObject *parent) : QObject(parent)
{

}

void MainWindowModel::changeState(State state)
{
    curState = state;
}



QWidget *MainWindowModel::getCurWidget()
{

}

MainWindowModel::State MainWindowModel::getCurState() const
{
    return curState;
}


