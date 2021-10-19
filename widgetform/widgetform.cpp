#include "widgetform.h"

WidgetForm::WidgetForm(QWidget* widget, QWidget *parent) : QWidget(parent)
{
    QButtonGroup* ruleButtons;
    QPushButton* menuButton;
    menuButton->setText("Menu");
    menuButton->setFixedSize(60,60);
    ruleButtons->addButton(menuButton);


}
