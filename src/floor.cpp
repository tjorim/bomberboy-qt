#include "floor.h"

Floor::Floor(QGraphicsItem *parent)
    :Thing(parent)
{
    setPixmap(QPixmap(":/images/grond.gif"));
}

bool Floor::isEnterable()
{
    return true;
}

bool Floor::isFirePermeable()
{
    return true;
}

bool Floor::isOnFire() const
{
    return onFire;
}

void Floor::setOnFire(bool value)
{
    setPixmap(QPixmap(":/images/explosie.gif"));
    onFire = value;
}
