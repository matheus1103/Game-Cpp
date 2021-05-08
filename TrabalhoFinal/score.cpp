#include "score.h"
#include <QFont>
#include "game.h"
extern Game * game;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)

{
    timer = 0;

    meuTempo = new QTimer(this);
    connect(meuTempo,&QTimer::timeout, this, &Score::myTime);
    meuTempo->start(7000);

    setPlainText(QString("Score: ") + QString::number(timer)+ QString(" Points"));
    setDefaultTextColor(Qt::black);
    setFont(QFont("System",20));

}

int Score::showtime()
{
    return timer;
}



void Score::myTime()
{
    qDebug()<<"+100";
    timer += 100 ;
    setPlainText(QString("Score: ") + QString::number(timer) + QString(" Points"));
    setDefaultTextColor(Qt::black);
    setFont(QFont("System",20));
}
