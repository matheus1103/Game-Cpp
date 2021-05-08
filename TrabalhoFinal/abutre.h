#ifndef ABUTRE_H
#define ABUTRE_H
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QPixmap>
#include <QPainter>
#include <QTimer>

class Abutre: public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    Abutre(QObject *parent =0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;

    QPainterPath shape() const override;
public slots:
    void move();
private slots:
    void nextFrame_A();
private:

    QTimer *timer;
    QPixmap *spriteimage;
    int currentframe;

};

#endif // ENEMY_H
