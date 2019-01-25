#include "gunpowder.h"

Gunpowder::Gunpowder(QGraphicsItem *parent)
    :Thing(parent)
{
    setPixmap(QPixmap(":/images/kruit.gif"));
}

bool Gunpowder::isEnterable()
{
    return true;
}

bool Gunpowder::isFirePermeable()
{
    return true;
}

bool Gunpowder::isOnFire() const
{
    return onFire;
}

void Gunpowder::setOnFire(bool value)
{
    onFire = value;
}
