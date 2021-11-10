#ifndef ENDGAMEMESSAGEBOX_H
#define ENDGAMEMESSAGEBOX_H

#include <QMessageBox>

class EndGameMessageBox : public QMessageBox
{
    Q_OBJECT
public:
    EndGameMessageBox(QString nameG1, int pointsG1, QString nameG2, int pointsG2);
};

#endif // ENDGAMEMESSAGEBOX_H
