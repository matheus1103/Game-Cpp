#ifndef GROUND_H
#define GROUND_H

#include <QList>
#include <QPointF>

#include <QGraphicsPixmapItem>
#include <QObject>
class Ground: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Ground(QList<QPointF>pointsTofollow ,QGraphicsItem * parent=0);

    int maxGround;
public slots:
    void move();

private:
    QList<QPointF>points;
    QPointF dest;
    int point_index;


};

#endif // GROUND_H
