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
#include "hyena.h"

extern Game * game;
Hyena::Hyena(QObject *parent)
{

    currentframe = 0;

    setPos(1280,570);

    spriteimage = new QPixmap(":/images/2 Hyena/Hyena_walk.png");

    QTimer *move_timer = new  QTimer(this);
    connect(move_timer,&QTimer::timeout, this, &Hyena::nextFrame_H);
    move_timer->start(80);

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);

}
QRectF Hyena::boundingRect() const{
    return QRectF(-10,-10,48,288);

}
void Hyena::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawPixmap(-10,-10, *spriteimage, currentframe, 0,48,288);

}
void Hyena::nextFrame_H(){
    currentframe +=48;
    if(currentframe>=200)currentframe = 0;
    this->update(-10,-10,48,288);
}

void Hyena::move(){

    if(!scene()->collidingItems(this).isEmpty())
    {

        qDebug()<<"Hyena colidido";
        game->health->decrease();
        game->number_death++;

        scene()->removeItem(this);
        delete this;
    }

    setPos(x()-15,y());
    if(pos().x() < 0)
    {

        scene()->removeItem(this);
        delete this;
        qDebug()<<"Hyena removed";
    }
}

QPainterPath Hyena::shape() const{
    QPainterPath path;
    path.addRect(-10,-10,10,10);
    return path;
}
