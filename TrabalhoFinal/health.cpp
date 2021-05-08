#include <QFont>
#include "health.h"
#include "game.h"
#include <QDebug>
#include "gameover.h"

extern Game * game;

Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    health = 3;
    setPlainText(QString("HP: ") + QString::number(health));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("System",20));
}
void Health::decrease()
{
    if (getHealth() > 0){
       health--;
    }
    if(getHealth() == 0 ){

        qDebug()<<"dead";
        game->score->meuTempo->disconnect();
        game->scene->removeItem(game->player);
        game->scene->addItem(game->gameover);
        delete game->player;
    }

    setPlainText(QString("HP: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("System",20));
}
    int Health::getHealth()
{
    return health;
}
