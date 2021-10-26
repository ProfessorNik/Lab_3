#ifndef LOCALGAMESETTINGSWIDGET_H
#define LOCALGAMESETTINGSWIDGET_H

#include <QWidget>
#include "gamers/factorygamers.h"

namespace Ui {
class LocalGameSettingsWidget;
}

class LocalGameSettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LocalGameSettingsWidget(QWidget *parent = nullptr);
    ~LocalGameSettingsWidget();

    int getAmountGames();
    QString getNameG1();
    QString getNameG2();
    FactoryGamers::Gamers getG1();
    FactoryGamers::Gamers getG2();
private:
    Ui::LocalGameSettingsWidget *ui;
private slots:
    void pressedStrart();
signals:
    void settingsReady();
};

#endif // LOCALGAMESETTINGSWIDGET_H
