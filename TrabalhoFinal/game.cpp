#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QFont>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <vector>
#include "game.h"
#include "ground.h"
#include "abutre.h"
#include "health.h"
#include "score.h"
Game::Game(QWidget *parent)
{

    //criando o mapa
    //criando a scene
        scene = new QGraphicsScene();
        scene->setSceneRect(0,0,1280,720);
        scene->setBackgroundBrush(QBrush(QImage(":/images/BG.png")));
        number_death = 0;
        setScene(scene);


//desabilitando scrool
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//tamanho HD
        setFixedSize(1280,720);
//criando player
        player = new Player();
        player->setRect(0,0,50,50);
        player->setPos(20,570);
        player->setScale(1.7);
        player->setFlag(QGraphicsItem::ItemIsFocusable);
        player->setFocus();
        scene->addItem(player);
//spawn de inimigos
        QTimer * timer = new QTimer();
        QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
        timer->start(3000);

//colocando HP na tela
        health = new Health();
        health->setPos(health->x(), health->y()+80);
        scene->addItem(health);
        //TIMER

        score = new Score();
        score->setPos(score->x(),score->y()+50);
        scene->addItem(score);
//game over
         gameover = new GameOver();
         gameover->setPos(gameover->x()+350,gameover->y());

         tempinho = 0;

//criando ground

        spawntimer = new QTimer(this);
        groundSpawned = 0;
        maxGround = 0;
        pointsTofollow<<QPointF(1280,600);
        for (int i =0;i<20;i++) {
            spawnGround(i);
        }
//musica
        QMediaPlayer * music = new QMediaPlayer(this);
        music->setMedia(QUrl("qrc:/song/gilvasunner-reupload-athletic-theme-super-mario-world.mp3"));
        music->play();
        show();
}

//ground
void Game::createGround(int numberOfGround)
{
    //groundSpawned = 0;
    maxGround = numberOfGround;
    connect(spawntimer,SIGNAL(timeout()),this,SLOT(spanwGround()));
    spawntimer->start(1000);
}

void Game::spawnGround(int algo)
{
        Ground * ground = new Ground(pointsTofollow);
        ground->setPos(algo*90,600);
        scene->addItem(ground);
        groundSpawned += 1;
}
