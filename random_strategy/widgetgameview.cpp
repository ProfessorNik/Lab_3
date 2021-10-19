#include "widgetgameview.h"

WidgetGameView::WidgetGameView(GameModel* model, QWidget *parent) : QWidget(parent), model(model)
{
    connect(model, &GameModel::changed, this, &WidgetGameView::update);

    this->resize(820, 410);
    QHBoxLayout* mainLayout = new QHBoxLayout;

    QVBoxLayout* alliedLayout = new QVBoxLayout;
    alliedLabel = new QLabel("Your filed");
    alliedFieldWidget = new AlliedFieldWidget;
    buildLayout(alliedLayout, alliedLabel, alliedFieldWidget);

    QVBoxLayout* enemyLayout = new QVBoxLayout;
    enemyLabel = new QLabel("Enemy filed");
    enemyFieldWidget = new EnemyFieldWidget;
    buildLayout(enemyLayout, enemyLabel, enemyFieldWidget);

    mainLayout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed));
    mainLayout->addLayout(alliedLayout);
    mainLayout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed));
    mainLayout->addLayout(enemyLayout);
    mainLayout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed));

    this->setLayout(mainLayout);

    connect(enemyFieldWidget, &EnemyFieldWidget::pressToSell, this, &WidgetGameView::shootToSell);
    update();
}

void WidgetGameView::buildLayout(QVBoxLayout* layout, QLabel* label, AbstractFieldWidget* field){
    label->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    field->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Fixed, QSizePolicy::Expanding));
    layout->addWidget(label);
    layout->addWidget(field);
    layout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Fixed, QSizePolicy::Expanding));
}


void WidgetGameView::setAlliedName(const QString &name)
{
    alliedLabel->setText(name);
}

void WidgetGameView::setEnemyName(const QString &name)
{
    enemyLabel->setText(name);
}

WidgetGameView::~WidgetGameView()
{
    delete model;
}

void WidgetGameView::update()
{
    alliedFieldWidget->update(model->getAlliedField().getField());
    enemyFieldWidget->update(model->getEnemyField().getField());
}



