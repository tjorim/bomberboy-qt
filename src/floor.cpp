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
    setPixmap(QPixmap(value ? ":/images/explosie.gif" : ":/images/grond.gif"));
    onFire = value;
}
