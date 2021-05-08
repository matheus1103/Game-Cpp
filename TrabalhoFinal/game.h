#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <QGraphicsView>
#include <QWidget>
#include <QTimer>
#include <QMediaPlayer>
#include <QGraphicsScene>
#include "health.h"
#include "gameover.h"
#include "score.h"
class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget * parent=0);
    void createGround(int numberOfGround);
    QGraphicsScene * scene;
    Player * player;
    Health * health;
    GameOver * gameover;
    Score * score;
    QTimer * spawntimer;
    QTimer * timer;
    int groundSpawned;
    int maxGround;
    int tempinho;
    QList<QPointF>pointsTofollow;

    int number_death;
public slots:
   // void start();
    void spawnGround(int algo);


};

#endif // GAME_H
