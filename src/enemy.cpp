#include "enemy.h"

Enemy::Enemy(QGraphicsItem *parent)
    :Thing(parent)
{
    setPixmap(QPixmap(":/images/BasicEnemy.png"));
}

bool Enemy::isEnterable()
{
    return false;
}

bool Enemy::isFirePermeable()
{
    return false;
}

bool Enemy::isOnFire() const
{
    return onFire;
}

void Enemy::setOnFire(bool value)
{
    setPixmap(QPixmap(value ? ":/images/BasicEnemyInjured.png" : ":/images/BasicEnemy.png"));
    onFire = value;
}

bool Enemy::isBreakable()
{
    return true;
}
