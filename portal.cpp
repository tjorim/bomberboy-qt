#include "portal.h"

Portal::Portal(int portaalNr, int poortNr, QGraphicsItem *parent)
    :portaalNr(portaalNr), poortNr(poortNr), Thing(parent)
{
    setPixmap(QPixmap(":/images/portaal_2.gif"));
}


bool Portal::isEnterable()
{
    if (free) {
        return true;
    } else {
        return false;
    }
}

bool Portal::isFirePermeable()
{
    return false;
}

bool Portal::isOnFire() const
{
    return false;
}

void Portal::setOnFire(bool value)
{
    onFire = value;
}

int Portal::getPortaalNr() const
{
    return portaalNr;
}

int Portal::getPoortNr() const
{
    return poortNr;
}

bool Portal::isVrij() const
{
    return free;
}

void Portal::setPortaalNr(int value)
{
    portaalNr = value;
}

void Portal::setPoortNr(int value)
{
    poortNr = value;
}

void Portal::maakVrij(bool value)
{
    free = value;
}


