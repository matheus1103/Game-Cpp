#include "abutre.h"
#include "game.h"
#include "player.h"
#include <QObject>
#include <QPixmap>
#include <QTimer>
#include <QGraphicsItem>
#include <stdlib.h>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>

extern Game * game;
Abutre::Abutre(QObject *parent)
{

    currentframe = 0;
    int random_number = rand() % 500 ;
    if (random_number >= 200){
        setPos(1280,random_number);
    }


    spriteimage = new QPixmap(":/images/4 Vulture/Vulture_walk.png");

    QTimer *move_timer = new  QTimer(this);
    connect(move_timer,&QTimer::timeout, this, &Abutre::nextFrame_A);
    move_timer->start(80);

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);

}
QRectF Abutre::boundingRect() const{
    return QRectF(-10,-10,50,192);

}
void Abutre::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawPixmap(-10,-10, *spriteimage, currentframe, 0,50,192);

}
void Abutre::nextFrame_A(){
    currentframe +=48;
    if(currentframe>=150)currentframe = 0;
    this->update(-10,-10,50,192);
}

void Abutre::move(){

    if(!scene()->collidingItems(this).isEmpty())
    {
        qDebug()<<"Passarinho colidido";
        game->health->decrease();
        game->number_death++;
        scene()->removeItem(this);
        delete this;
    }

    setPos(x()-5,y());
    if(pos().x() < 0)
    {

        scene()->removeItem(this);
        delete this;
        qDebug()<<"Passarinho removed";
    }
}

QPainterPath Abutre::shape() const{
    QPainterPath path;
    path.addRect(-10,-10,10,10);
    return path;
}
