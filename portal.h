#ifndef PORTAL_H
#define PORTAL_H

#include "thing.h"

/**
 * class Portaal
 *
 * @author Jorim Tielemans
 * @version 06/01/2017
 */
class Portal: public Thing
{
public:
    /**
     * Constructor voor objects van class Portaal
     *
     * @param portaalNr Het nummer van het portaal.
     * @param poortNr Het nummer van de poort.
     */
    Portal(int portaalNr, int poortNr, QGraphicsItem *parent = nullptr);

    thingType getType() {return thingType::PORTAL;}

    // Thing interface getters
    bool isEnterable();
    bool isFirePermeable();
    bool isOnFire() const;

    // getters
    /**
     * Hiermee vraag je het nummer van het portaal op.
     *
     * @return portaalNr Het nummer van het portaal.
     */
    int getPortaalNr() const;
    /**
     * Hiermee vraag je het nummer van de poort op.
     *
     * @return poortNr Het nummer van de poort.
     */
    int getPoortNr() const;
    /**
     * Hiermee vraag je of de er niemand in het portaal zit .
     *
     * @return vrij True indien het portaal vrij is.
     */
    bool isVrij() const;

    // setters
    /**
     * Hiermee stel je het nummer van het portaal in.
     *
     * @param portaalNr Het nummer van het portaal.
     */
    void setPortaalNr(int value);
    /**
     * Hiermee stel je het nummer van de poort in.
     *
     * @param poortNr Het nummer van de poort.
     */
    void setPoortNr(int value);
    /**
     * Hiermee kan je zeggen of het portaal leeg is, dus vrij.
     *
     * @param vrij True indien het portaal vrij is.
     */
    void maakVrij(bool value);

    void setOnFire(bool value);

private:
    bool onFire = false;
    int portaalNr;
    int poortNr;
    bool free = true;
};

#endif // PORTAL_H
