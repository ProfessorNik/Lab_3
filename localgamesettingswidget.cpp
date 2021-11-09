#include "localgamesettingswidget.h"
#include "ui_localgamesettingswidget.h"

LocalGameSettingsWidget::LocalGameSettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LocalGameSettingsWidget)
{
    ui->setupUi(this);
    ui->amountGame->setMinimum(1);
    ui->amountGame->setValue(1);
    connect(ui->startButton, &QPushButton::pressed, this, &LocalGameSettingsWidget::pressedStrart);
    connect(ui->menuButton, &QPushButton::pressed, this, &LocalGameSettingsWidget::mainMenu);
}

LocalGameSettingsWidget::~LocalGameSettingsWidget()
{
    delete ui;
}

int LocalGameSettingsWidget::getAmountGames()
{
    return ui->amountGame->value();
}

QString LocalGameSettingsWidget::getNameG1()
{
    return ui->nameG1->text();
}

QString LocalGameSettingsWidget::getNameG2()
{
    return ui->nameG2->text();
}

FactoryGamers::Gamers LocalGameSettingsWidget::getG1()
{
    if(ui->comboBoxG1->currentText() == "Human")
        return FactoryGamers::Gamers::HUMAN_GAMER;
    if(ui->comboBoxG1->currentText() == "Random")
        return FactoryGamers::Gamers::RANDOM_GAMER;
    if(ui->comboBoxG1->currentText() == "Optimal")
        return FactoryGamers::Gamers::OPTIMAL_GAMER;
    qDebug("Error LocalGameSttingsWidget");
    return FactoryGamers::Gamers::RANDOM_GAMER;
}

FactoryGamers::Gamers LocalGameSettingsWidget::getG2()
{
    if(ui->comboBoxG2->currentText() == "Human")
        return FactoryGamers::Gamers::HUMAN_GAMER;
    if(ui->comboBoxG2->currentText() == "Random")
        return FactoryGamers::Gamers::RANDOM_GAMER;
    if(ui->comboBoxG2->currentText() == "Optimal")
        return FactoryGamers::Gamers::OPTIMAL_GAMER;
    qDebug("Error LocalGameSttingsWidget");
    return FactoryGamers::Gamers::RANDOM_GAMER;
}

void LocalGameSettingsWidget::pressedStrart()
{
    if(ui->nameG1->text() != "" && ui->nameG2->text() != ""){
        if(ui->nameG1->text() != ui->nameG2->text())
            emit settingsReady();
    }
}
