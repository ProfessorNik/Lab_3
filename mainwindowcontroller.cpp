#include "mainwindowcontroller.h"

MainWindowController::MainWindowController(QObject *parent) : QObject(parent)
{
    this->model = new MainWindowModel;
    this->window = new MainWindow(this->model);
    this->window->show();
}
