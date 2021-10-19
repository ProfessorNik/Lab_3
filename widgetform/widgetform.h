#ifndef WIDGETFORM_H
#define WIDGETFORM_H

#include <QWidget>
#include <QButtonGroup>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class WidgetForm : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetForm(QWidget* widget, QWidget *parent = nullptr);

signals:

};

#endif // WIDGETFORM_H
