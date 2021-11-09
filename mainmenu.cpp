#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QPushButton>

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    ui->accountButton->hide();
    ui->statisticsButton->hide();
    connect(ui->localGameButton, &QPushButton::clicked, this, &MainMenu::localGame);
}

MainMenu::~MainMenu()
{
    delete ui;
}
