#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QPushButton>

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    connect(ui->randomButton, &QPushButton::clicked, this, &MainMenu::randomStrategy);
}

MainMenu::~MainMenu()
{
    delete ui;
}
