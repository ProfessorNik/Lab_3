#include "graphicfieldview.h"


GraphicFieldView::GraphicFieldView(FieldModel* model, QWidget *parent) : QWidget(parent), model(model){
    model->addObserver(this);
    this->resize(820, 410);
    QHBoxLayout* mainLayout = new QHBoxLayout;

    QVBoxLayout* alliedLayout = new QVBoxLayout;
    alliedLabel = new QLabel("Your filed");
    alliedField = new AlliedSingleField;
    buildLayout(alliedLayout, alliedLabel, alliedField);

    QVBoxLayout* enemyLayout = new QVBoxLayout;
    enemyLabel = new QLabel("Enemy filed");
    enemyField = new EnemySingleField;
    buildLayout(enemyLayout, enemyLabel, enemyField);

    mainLayout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed));
    mainLayout->addLayout(alliedLayout);
    mainLayout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed));
    mainLayout->addLayout(enemyLayout);
    mainLayout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed));

    this->setLayout(mainLayout);
}

void GraphicFieldView::buildLayout(QVBoxLayout* layout, QLabel* label, AbstractSingleField* field){
    label->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    field->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Fixed, QSizePolicy::Expanding));
    layout->addWidget(label);
    layout->addWidget(field);
    layout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Fixed, QSizePolicy::Expanding));
}

void GraphicFieldView::update()
{
    const auto& field = model->getField();
    const auto& alliedField = field.getAlliedField();
    const auto& enemyField = field.getEnemyField();
}

void GraphicFieldView::paintEvent(QPaintEvent *event){

}

