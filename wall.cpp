#include "wall.h"

Wall::Wall(QGraphicsItem *parent)
    :Thing(parent)
{
    setPixmap(QPixmap(":/images/muur.gif"));
}

bool Wall::isEnterable()
{
    return false;
}

bool Wall::isFirePermeable()
{
    return false;
}

bool Wall::isOnFire() const
{
    return false;
}
