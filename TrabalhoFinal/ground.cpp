#include "ground.h"
#include "game.h"

#include <QPixmap>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
extern Game * game;

Ground::Ground(QList<QPointF>pointsToFollow,QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/freetileset/png/Tiles/2.png"));
    //set

    points = pointsToFollow;
    point_index = 0;
    dest = points[0];

    //move
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}


void Ground::move(){

    setPos(x()-10,y());

    if(pos().x() < -180){
        game->groundSpawned--;
        scene()->removeItem(this);
        delete this;
        qDebug()<<"Ground removed";
    }
    if(game->groundSpawned < 20){
        game->spawnGround(game->groundSpawned-1);
    }
}
