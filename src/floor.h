#ifndef FLOOR_H
#define FLOOR_H

#include "thing.h"

/**
 * class Grond
 *
 * @author Jorim Tielemans
 * @version 05/01/2017
 */
class Floor: public Thing
{
public:
    /**
     * Constructor voor objects van class Grond
     */
    Floor(QGraphicsItem *parent = nullptr);

    thingType getType() {return thingType::FLOOR;}

    // Thing interface getters
    bool isEnterable();
    bool isFirePermeable();
    bool isOnFire() const;

    void setOnFire(bool value);

private:
    bool onFire = false;
};

#endif // FLOOR_H
