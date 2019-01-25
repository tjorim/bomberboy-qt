#ifndef THINGBOARD_H
#define THINGBOARD_H

#include <QList>
#include <QGraphicsItem>

#include "thing.h"
#include "powerup.h"

/**
 * class ThingBoard
 *
 * @author Jorim Tielemans
 * @version 09/01/2017
 */
class ThingBoard
{
public:
    // constructors
    ThingBoard();

    QList<QList<Thing *> > getBoard() const;
    void createBoard(int width, int height);
    void placeThing(int x, int y, Thing *thing);
    Thing *getThing(int x, int y);

    /**
     * Constructor voor objects van class Level
     *
     * @param m het Model.
     */
    void load(int levelNr);

    /**
     * Dit is level 1: Old Boring Level. Hier zitten 181 dozen in,
     * nog een bepaald percentage moet gevuld worden met PowerUps.
     *
     * Voorbeeld:
    x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x
    x   b       d   d   d   d   d   d   d   d   d   d   d   d   d   d   d           x
    x       x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x       x
    x   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   x
    x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x
    x   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   x
    x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x
    x   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   x
    x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x
    x   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   x
    x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x
    x   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   x
    x       x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x       x
    x           d   d   d   d   d   d   d   d   d   d   d   d   d   d   d       r   x
    x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x
     */
    void level1();

    /**
     * Dit is level 2: FIRE EVERYWHERE!!! Xoxo. Hier zijn geen PowerUps aanwezig.
     * In het midden bevind zich een cirkel van kruit (eigenlijk een rechthoek),
     * dit ontploft mee als vuur van een explosie het raakt.
     *
     * Voorbeeld:
    x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x
    x   d   d   d                                                       d   d   d   x
    x   d   x       x       x       x       x       x       x       x       x   d   x
    x   d               k   k   k   k   k   k   k   k   k   k   k               d   x
    x       x       x   k   x       x   d   x   d   x       x   k   x       x       x
    x                   k               d   d   d               k                   x
    x       x       x   k   x       x       x       x       x   k   x       x   d   x
    x   b               k                                       k               r   x
    x   d   x       x   k   x       x       x       x       x   k   x       x       x
    x                   k               d   d   d               k                   x
    x       x       x   k   x       x   d   x   d   x       x   k   x       x       x
    x   d               k   k   k   k   k   k   k   k   k   k   k               d   x
    x   d   x       x       x       x       x       x       x       x       x   d   x
    x   d   d   d                                                       d   d   d   x
    x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x
     */
    void level2();

    /**
     * Dit is level 3: Let's teleport! Hier zitten 149 dozen in,
     * nog een bepaald percentage moet gevuld worden met PowerUps.
     * In de hoeken (niet echt helemaal uiterst in de hoeken) bevinden zich portalen,
     * hier kan men doorgaan en men komt bij de andere poort (de overkant van het veld) uit.
     *
     * Voorbeeld:
    x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x
    x   b                   d   d   d   d   d   d   d   d   d                       x
    x       x       x   d   x   d   x   d   x   d   x   d   x   d   x       x       x
    x           p   d   d   d   d   d   d   d   d   d   d   d   d   d   p           x
    x       x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x       x
    x   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   x
    x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x
    x   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   x
    x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x
    x   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   d   x
    x       x   d   x   d   x   d   x   d   x   d   x   d   x   d   x   d   x       x
    x           p   d   d   d   d   d   d   d   d   d   d   d   d   d   p           x
    x       x       x   d   x   d   x   d   x   d   x   d   x   d   x       x       x
    x                       d   d   d   d   d   d   d   d   d                   r   x
    x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x
     */
    void level3();

    /**
     * Dit is level 4: Just go kill yourself >:(. Hier zijn geen PowerUps aanwezig,
     * maar ook geen kratten of kruit. Just plain simple Grond everywhere.
     * Men kan zich nergens verbergen, dus ze moeten elkaar gewoon afmaken, of toch proberen.
     *
     * ToDo: De spelers krijgen direct het maximale aantal bommen,
     * de maximale vuurkracht en ze lopen op hun snelst. Levens krijgen ze maar 3.
     *
     * Voorbeeld:
    x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x
    x   b                                                                           x
    x       x       x       x       x       x       x       x       x       x       x
    x                                                                               x
    x       x       x       x       x       x       x       x       x       x       x
    x                                                                               x
    x       x       x       x       x       x       x       x       x       x       x
    x                                                                               x
    x       x       x       x       x       x       x       x       x       x       x
    x                                                                               x
    x       x       x       x       x       x       x       x       x       x       x
    x                                                                               x
    x       x       x       x       x       x       x       x       x       x       x
    x                                                                           r   x
    x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x   x
     */
    void level4();

    /**
     * Selecteert een willekeurige powerup uit een enum.
     * Source: http://stackoverflow.com/questions/18145766/generating-a-random-enum-value-continuously-without-getting-the-same-value-twice
     *
     * @return Een willekeurige powerup.
     */
    PowerUp::Power getRandomPower();

    /**
     * Nu staat er dus wel een javadocding bij.
     * Deze functie gaat, afhankelijk van hoeveel powerups er moeten worden verstopt, op bepaalde plaatsen een krat vervangen door een powerup.
     */
    void verdeelPowerUp(int aantalPowerUps);

private:
    QList<QList<Thing *> > board;
};

#endif // THINGBOARD_H
