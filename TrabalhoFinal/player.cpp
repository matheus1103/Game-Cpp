#include "player.h"
#include "abutre.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent>
#include "hyena.h"
#include "game.h"
extern Game * game;

Player::Player(QObject *parent)
{
    pulo = new QTimer(this);

    currentframe = 0;
    spriteimage = new QPixmap(":/images/6 Bear/Walk.png");
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Player::nextFrame);
    timer->start(40);

}


void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Left){
            setPos(x()-10,y());

    }
    else if(event->key()== Qt::Key_Right){
            setPos(x()+10,y());
    }
    else if(event->key()== Qt::Key_Up){
        if(pos().y()== 570){
            connect(pulo, SIGNAL(timeout()), this, SLOT(jump()));
            pulo->start(20);
        }

    }

}
void Player::jump()
{
     setPos(x(),y()-10);
     if(pos().y() <= 450)
     {
         pulo->disconnect();

         qDebug()<<"acabouPulo";

     }
}


QRectF Player::boundingRect() const{
    return QRectF(-10,-10,72,480);

}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawPixmap(-10,-10, *spriteimage, currentframe, 0,72,480);

}

void Player::nextFrame(){
    currentframe +=72;
    if(currentframe>=400)currentframe = 0;
    this->update(-10,-10,72,480);

    if(pos().y()<570){
        setPos(x(),y()+7);
    }
    else if(pos().y()>=570){
        setPos(x(),570);
    }
}


void Player::spawn(){
    Abutre * abutre = new Abutre();
    scene()->addItem(abutre);

    Hyena * hyena = new Hyena();
    scene()->addItem(hyena);
}

QPainterPath Player::shape() const
{
    QPainterPath path;
    path.addRect(-10, -20, 20, 40);
    return path;
}
