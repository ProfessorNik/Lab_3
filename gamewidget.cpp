#include "gamewidget.h"
#include "ui_gamewidget.h"

GameWidget::GameWidget(QSharedPointer<IGameDataModel> model, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget), model(model)
{
    ui->setupUi(this);
    connect(model.data(), &IGameDataModel::changed, this, &GameWidget::update);
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
    ui->amountGames->setText(QString::number(amountGame));
    ui->scoreG1->setText(QString::number(scoreG1));
    ui->scoreG2->setText(QString::number(scoreG2));

}
