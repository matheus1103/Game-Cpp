#ifndef TIMER_H
#define TIMER_H
#include <QGraphicsTextItem>
#include <QTimer>


class Score:  public QGraphicsTextItem
{
public:
    Score(QGraphicsItem *parent =0);
    //int addTime();
    int showtime();
    int timer;
    QTimer * meuTempo;

public slots:
    //void addtime();
    void myTime();

private slots:

};

#endif // TIMER_H
