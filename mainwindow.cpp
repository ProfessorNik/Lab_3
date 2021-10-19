#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

}

void MainWindow::setWidget(QWidget* widget){
    this->setCentralWidget(widget);
}
