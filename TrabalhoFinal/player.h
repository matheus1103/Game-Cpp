#ifndef PLAYER_H
#define PLAYER_H

#include <QTimer>
#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>
#include <QGraphicsRectItem>
class Player: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Player(QObject * parent=0);
    void keyPressEvent(QKeyEvent * event) override;
    void setIsJumping(bool);
       // Getters
    QTimer *pulo;

    bool getIsJumping();
   // void keyReleaseEvent(QKeyEvent *event) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;

public slots:
    void spawn();
    void jump();
private slots:
    void nextFrame();
private:
    bool isJumping;
    QTimer *timer;
    QPixmap *spriteimage;
    int currentframe;

};

#endif // PLAYER_H
