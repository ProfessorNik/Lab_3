#include "gamewidget.h"
#include "ui_gamewidget.h"


GameWidget::GameWidget(QSharedPointer<IGameDataModel> model, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget), model(model)
{
    ui->setupUi(this);
    connect(model.data(), &IGameDataModel::changed, this, &GameWidget::update);
    connect(ui->exitButton, &QPushButton::pressed, this, &GameWidget::exit);
    update();
}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::update()
{
    qDebug("update");
    int amountGame = model->getAmountGames();
    qDebug() << amountGame;
    int scoreG1 = model->getScoreG1();
    qDebug() << scoreG1;
    int scoreG2 = model->getScoreG2();
    qDebug() << scoreG2;
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
