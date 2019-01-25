#include "playerinfo.h"

#include <QFont>

PlayerInfo::PlayerInfo(QGraphicsItem *parent)
    :QGraphicsTextItem(parent)
{
    // initialize the health to 3
    health = 3;
    // initialize the bombs to 1
    bombs = 1;

    // draw the health: 3
    setPlainText("Health: " + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));

    // draw the bombs: 1
    setPlainText("Score: " + QString::number(bombs));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

void PlayerInfo::increaseHealth()
{
    health++;
    // update the health: 4
    setPlainText("Health: " + QString::number(health));
}

void PlayerInfo::decreaseHealth()
{
    health--;
    // update the health: 3
    setPlainText("Health: " + QString::number(health));
}

int PlayerInfo::getHealth() const
{
    return health;
}

void PlayerInfo::increaseBombs()
{
    bombs++;
    // update the bombs: 2
    setPlainText("Bombs: " + QString::number(bombs));
}

void PlayerInfo::decreaseBombs()
{
    bombs--;
    // update the bombs: 1
    setPlainText("Bombs: " + QString::number(bombs));
}

int PlayerInfo::getBombs() const
{
    return bombs;
}
