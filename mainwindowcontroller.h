#ifndef MAINWINDOWCONTROLLER_H
#define MAINWINDOWCONTROLLER_H

#include <QObject>
#include "mainwindow.h"
#include "mainwindowmodel.h"

class MainWindowController : public QObject
{
    Q_OBJECT
public:
    explicit MainWindowController(QObject *parent = nullptr);

signals:

private:
    MainWindow* window;
    MainWindowModel* model;
};

#endif // MAINWINDOWCONTROLLER_H
