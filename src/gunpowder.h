#ifndef GUNPOWDER_H
#define GUNPOWDER_H

#include "thing.h"

/**
 * class Kruit
 *
 * @author Jorim Tielemans
 * @version 05/01/2017
 */
class Gunpowder: public Thing
{
public:
    /**
     * Constructor voor objects van class Kruit
     */
    Gunpowder(QGraphicsItem *parent = nullptr);

    thingType getType() {return thingType::GUNPOWDER;}

    // Thing interface getters
    bool isEnterable();
    bool isFirePermeable();
    bool isOnFire() const;

    void setOnFire(bool value);

private:
    bool onFire = false;
};

#endif // GUNPOWDER_H
