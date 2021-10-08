#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "QPushButton"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    connect(ui->interactiveSession, &QPushButton::clicked, this, &MainMenu::interactiveSession);
    connect(ui->optimalStartegy, &QPushButton::clicked, this, &MainMenu::optimalStrategy);
    connect(ui->RandomStrategy, &QPushButton::clicked, this, &MainMenu::randomStrategy);
    connect(ui->statistics, &QPushButton::clicked, this, &MainMenu::statistics);
}

MainMenu::~MainMenu()
{
    delete ui;
}
