#ifndef WALL_H
#define WALL_H

#include "thing.h"

/**
 * class Muur
 *
 * @author Jorim Tielemans
 * @version 05/01/2017
 */
class Wall : public Thing
{
public:
    /**
     * Constructor voor objects van class Muur
     */
    Wall(QGraphicsItem *parent = nullptr);

    thingType getType() {return thingType::WALL;}

    // Thing interface getters
    bool isEnterable();
    bool isFirePermeable();
    bool isOnFire() const;
};

#endif // WALL_H
