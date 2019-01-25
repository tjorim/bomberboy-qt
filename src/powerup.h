#ifndef POWERUP_H
#define POWERUP_H

#include "thing.h"

/**
 * class PowerUp
 *
 * @author Jorim Tielemans
 * @version 09/01/2017
 */
class PowerUp: public Thing
{
public:
    /**
     * Enumeration class POWER - geef hier een beschrijving van de enum class
     * we only have seven powers, so no need for ints!
     */
    enum class Power: char {EXTRA_BOM = 1, MEER_VLAM = 2, GOLDENFLAME = 3, KICKER = 4, EXTRA_LEVEN = 5, SHIFTER = 6, SNELLER_LOPEN = 7};

    /**
     * Constructor voor objects van class PowerUp
     *
     * @param power EXTRA_BOM, MEER_VLAM, GOLDENFLAME, KICKER, EXTRA_LEVEN, SHIFTER, SNELLER_LOPEN
     */
    PowerUp(Power power, QGraphicsItem *parent = nullptr);

    thingType getType() {return thingType::POWERUP;}

    // getters
    /**
     * Wat zit er in de krat?
     *
     * @return De inhoud.
     */
    PowerUp::Power getPower() const;
    /**
     * Is de krat al open?
     *
     * @return True als de krat open is.
     */
    bool isOpen() const;

    // Thing interface getters
    bool isEnterable();
    bool isFirePermeable();
    bool isOnFire() const;

    bool isCollectable();

    // setters
    /**
     * Maak de krat open.
     *
     * @param open True als het krat open is
     */
    void setOpen(bool value);

    void setOnFire(bool value);

private:
    bool onFire = false;
    PowerUp::Power power;
    bool open = false;
};

#endif // POWERUP_H
