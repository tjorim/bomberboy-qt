#ifndef CRATE_H
#define CRATE_H

#include "thing.h"

/**
 * class Crate
 *
 * @author Jorim Tielemans
 * @version 05/01/2017
 */
class Crate: public Thing
{
public:
    /**
     * Constructor voor objects van class Crate
     */
    Crate(QGraphicsItem *parent = nullptr);

    thingType getType() {return thingType::CRATE;}

    // Thing interface getters
    bool isEnterable();
    bool isFirePermeable();
    bool isOnFire() const;

    bool isBreakable();

    void setOnFire(bool value);

private:
    bool onFire = false;
};

#endif // CRATE_H
