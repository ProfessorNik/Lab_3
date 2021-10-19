#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QHBoxLayout>
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    void setWidget(QWidget *widget);

private:
    QHBoxLayout* mainLayout;

};

#endif // MAINWINDOW_H
