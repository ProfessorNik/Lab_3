#include "endgamemessagebox.h"

EndGameMessageBox::EndGameMessageBox(QString nameG1, int pointsG1, QString nameG2, int pointsG2)
{
    QString message;

    if(pointsG1 == pointsG2)
        message += "Standoff!";
    else if(pointsG1 > pointsG2)
        message += "Winner " + nameG1 + "!";
    else
        message += "Winner " + nameG2 + "!";
    message += " score " + QString::number(pointsG1) + " : " + QString::number(pointsG2);

    this->setText(message);
}
