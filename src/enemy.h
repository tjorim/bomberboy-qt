#ifndef ENEMY_H
#define ENEMY_H

#include "thing.h"

/**
 * class Enemy
 *
 * Basic enemy thing corresponding to the BasicEnemy image resources.
 *
 * @author Jorim Tielemans
 * @version 11/07/2026
 */
class Enemy: public Thing
{
public:
    /**
     * Constructor voor objects van class Enemy
     */
    Enemy(QGraphicsItem *parent = nullptr);

    thingType getType() {return thingType::ENEMY;}

    // Thing interface getters
    bool isEnterable();
    bool isFirePermeable();
    bool isOnFire() const;

    bool isBreakable();

    void setOnFire(bool value);

private:
    bool onFire = false;
};

#endif // ENEMY_H
