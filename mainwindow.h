#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "mainmenu.h"
#include "mainwindowmodel.h"
#include "observer.h"

class MainWindow : public QMainWindow, public Observer
{
    Q_OBJECT
public:
    explicit MainWindow(MainWindowModel* model, QWidget *parent = nullptr);

signals:

private:
    MainWindowModel* model;

    // Observer interface
    void placeWidgetToWindow(QWidget *widget);
public:
    void update() override;
};

#endif // MAINWINDOW_H
