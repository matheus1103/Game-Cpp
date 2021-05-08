#include "gameover.h"
#include "game.h"

GameOver::GameOver(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    setPlainText(QString("GAME OVER"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("System",80));
}
