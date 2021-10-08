#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(MainWindowModel* model, QWidget *parent) : QMainWindow(parent)
{
    model->addObserver(this);
    this->model = model;
    this->placeWidgetToWindow(model->getCurWidget());
}

void MainWindow::update()
{
    delete this->layout();
    QWidget* widget = model->getCurWidget();
    this->placeWidgetToWindow(widget);
}


void MainWindow::placeWidgetToWindow(QWidget* widget){
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(widget);
    this->setLayout(layout);
}
