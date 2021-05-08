#ifndef HYENA_H
#define HYENA_H
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QPixmap>
#include <QPainter>
#include <QTimer>

class Hyena: public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    Hyena(QObject *parent =0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;

    QPainterPath shape() const override;
public slots:
    void move();
private slots:
    void nextFrame_H();
private:

    QTimer *timer;
    QPixmap *spriteimage;
    int currentframe;

};
#endif
