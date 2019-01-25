#include "powerup.h"

PowerUp::PowerUp(Power power, QGraphicsItem *parent)
    :power(power), Thing(parent)
{
    setPixmap(QPixmap(":/images/krat.gif"));
}


bool PowerUp::isEnterable()
{
    if (open) {
        return true;
    } else {
        return false;
    }
}

bool PowerUp::isFirePermeable()
{
    return true;
}

bool PowerUp::isOnFire() const
{
    return onFire;
}

bool PowerUp::isCollectable()
{
    return true;
}

void PowerUp::setOnFire(bool value)
{
    onFire = value;
}

PowerUp::Power PowerUp::getPower() const
{
    return power;
}

bool PowerUp::isOpen() const
{
    return open;
}

void PowerUp::setOpen(bool value)
{
    open = value;
    switch (power) {
    case Power::EXTRA_BOM:
        setPixmap(QPixmap(":/images/item_bomb.gif"));
        break;
    case Power::MEER_VLAM:
        setPixmap(QPixmap(":/images/item_flame.gif"));
        break;
    case Power::GOLDENFLAME:
        setPixmap(QPixmap(":/images/item_goldenflame.gif"));
        break;
    case Power::KICKER:
        setPixmap(QPixmap(":/images/item_kicker.gif"));
        break;
    case Power::EXTRA_LEVEN:
        setPixmap(QPixmap(":/images/item_life.gif"));
        break;
    case Power::SHIFTER:
        setPixmap(QPixmap(":/images/item_shifter.gif"));
        break;
    case Power::SNELLER_LOPEN:
        setPixmap(QPixmap(":/images/item_speedup.gif"));
        break;
    default:
        setPixmap(QPixmap(":/images/item_random.gif"));
        break;
    }
}
