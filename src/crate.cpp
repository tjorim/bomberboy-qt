#include "crate.h"

Crate::Crate(QGraphicsItem *parent)
    :Thing(parent)
{
    setPixmap(QPixmap(":/images/krat.gif"));
}


bool Crate::isEnterable()
{
    return false;
}

bool Crate::isFirePermeable()
{
    return false;
}

bool Crate::isOnFire() const
{
    return onFire;
}

void Crate::setOnFire(bool value)
{
    onFire = value;
}

bool Crate::isBreakable()
{
    return true;
}
