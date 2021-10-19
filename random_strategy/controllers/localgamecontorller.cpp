#include "localgamecontorller.h"
#include "../../services/servicesfactory.h"

LocalGameContorller::LocalGameContorller(Session *session, QObject *parent) : IGameController(parent)
{
    this->session = session;
}

void LocalGameContorller::startGame()
{
    gamer1 = new HumanGamer(session, this);
    if(session->getMode() == Session::RANDOM_STRATEGY)
        gamer2 = new RandomGamer(this);
    connect(gamer1, &IGamer::shoot, this, &LocalGameContorller::tryStep);
    connect(gamer2, &IGamer::shoot, this, &LocalGameContorller::tryStep);

    gamer1Step = true;
    gamer1->changeStep(gamer1Step);
    gamer2->changeStep(!gamer1Step);
}

void LocalGameContorller::tryStep(int x, int y)
{
    if(gamer1Step){
        qDebug() << "G1: " << x << y;
        if(gamer2->isAllowedSell(x, y)){
            Field::FieldPlace place = gamer2->shootTo(x, y);
            if(place == Field::FieldPlace::EMPTY_WRECKED_PLACE){
                gamer1Step = !gamer1Step;
            }
            gamer1->updateEnemyField(x, y, place);
        }
    }
    else{
        qDebug() << "G2: " << x << y;
        if(gamer1->isAllowedSell(x, y)){
            Field::FieldPlace place = gamer1->shootTo(x, y);
            if(place == Field::FieldPlace::EMPTY_WRECKED_PLACE){
                gamer1Step = !gamer1Step;
            }
            gamer2->updateEnemyField(x, y, place);
        }
    }

    gamer1->changeStep(gamer1Step);
    gamer2->changeStep(!gamer1Step);
}
