#include "gamestatuswidget.h"
#include "ui_gamewidget.h"


GameStatusWidget::GameStatusWidget(QSharedPointer<IGameDataModel> model, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget), model(model)
{
    ui->setupUi(this);
    connect(model.data(), &IGameDataModel::changed, this, &GameStatusWidget::update);
    connect(ui->exitButton, &QPushButton::pressed, this, &GameStatusWidget::exit);
    update();
}

GameStatusWidget::~GameStatusWidget()
{
    delete ui;
}

void GameStatusWidget::update()
{
    int amountGame = model->getAmountGames();
    int scoreG1 = model->getScoreG1();
    int scoreG2 = model->getScoreG2();
    ui->nameG1->setText(model->getNameG1());
    ui->nameG2->setText(model->getNameG2());
    ui->amountGames->setText(QString::number(amountGame));
    ui->scoreG1->setText(QString::number(scoreG1));
    ui->scoreG2->setText(QString::number(scoreG2));
    if(model->isEndGame()){
        mb = QSharedPointer<EndGameMessageBox>(new EndGameMessageBox(model->getNameG1(), scoreG1, model->getNameG2(), scoreG2));
        mb->show();
    }
}
