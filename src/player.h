#ifndef PLAYER_H
#define PLAYER_H

#include "thing.h"

/**
 * class Player
 *
 * @author Jorim Tielemans
 * @version 09/01/2017
 */
class Player: public Thing
{
public:
    /**
     * Constructor voor objects van class Player
     *
     * @param spelerNr Het nummer van de speler.
     */
    Player(int playerNumber, Thing *thingUnderPlayer, QGraphicsItem *parent = nullptr);

    thingType getType() {return thingType::PLAYER;}

    // we only have four directions, so no need for ints!
    enum class Direction : char {ONDER = 1, BOVEN = 2, LINKS = 3, RECHTS = 4};

    static int standaardBommen;
    static int maxBommen;
    static int standaardVuur;
    static int standaardLevens;
    static int maxLevens;
    static int standaardSnelheid;
    static int maxSnelheid;

    // Thing interface getters
    bool isEnterable();
    bool isFirePermeable();
    bool isOnFire() const;

    /**
     * Laat de speler ontploffen.
     *
     * @param vuur True indien de speler aan het ontploffen is.
     */
    void setOnFire(bool value);
    void dropBomb();

    // getters
    /**
     * Hiermee vraag je het nummer van de speler op.
     *
     * @return het nummer van de speler.
     */
    int getPlayerNumber() const;
    /**
     * Kan de speler bommen shiften?
     *
     * @return True als de speler bommen kan shiften.
     */
    bool canShift() const;
    /**
     * Kan de speler bommen kicken?
     *
     * @return True als de speler bommen kan kicken.
     */
    bool canKick() const;
    /**
     * Wat is de richting van de speler?
     * ONDER, BOVEN, LINKS, RECHTS
     *
     * @return De richting van de speler.
     */
    Direction getDirection() const;
    /**
     * Hoeveel bommen heeft de speler nog?
     *
     * @return het aantal bommen van de speler.
     */
    int getAantalBommen() const;
    /**
     * Hoeveel bommen kan de speler maximum hebben?
     *
     * @return het maximum aantal bommen van de speler.
     */
    static int getMaxBommen();
    /**
     * Hoe krachtig is de explosie van de speler?
     *
     * @return De 'krachtigheid' van de explosie van de speler.
     */
    int getHoeveelVuur() const;
    /**
     * Hoe krachtig kan de explosie van de speler maximum zijn?
     *
     * @return De maximale 'krachtigheid' van de explosie van de speler.
     */
    int getMaxVuur() const;
    /**
     * Hoeveel levens heeft de speler nog?
     *
     * @return het aantal levens van de speler.
     */
    int getLives() const;
    /**
     * Hoeveel levens kan de speler maximum hebben?
     *
     * @return het maximum aantal levens van de speler.
     */
    static int getMaxLevens();
    /**
     * Welke snelheid heeft de speler?
     *
     * @return snelheid De snelheid van de speler.
     */
    int getSpeed() const;
    /**
     * Welke snelheid kan de speler maximaal hebben?
     *
     * @return maxSnelheid De maximale snelheid van de speler.
     */
    static int getMaxSnelheid();
    /**
     * Wat ligt er onder de speler in het veld?
     *
     * @return vwOnderSpeler Het voorwerp onder de speler.
     */
    Thing *getThingUnderPlayer() const;
    /**
     * Een niet nader omschreven Voorwerp s
     *
     * @return s Nog een voorwerp van de speler.
     */
    Thing *getS() const;

    // setters
    /**
     * Hiermee stel je het nummer van de speler in.
     *
     * @param spelerNr Het nummer van de speler.
     */
    void setPlayerNumber(int value);
    /**
     * Laat de speler bommen shiften.
     *
     * @param shiften True als de speler bommen mag shiften.
     */
    void setShift(bool value);
    /**
     * Laat de speler bommen kicken.
     *
     * @param kicken True als de speler bommen mag kicken.
     */
    void setKick(bool value);
    /**
     * Geef de speler een richting.
     * ONDER, BOVEN, LINKS, RECHTS
     *
     * @param richting De richting die de speler krijgt.
     */
    void setDirection(const Direction &value);
    /**
     * Hiermee pas je de kracht van de explosie van de speler aan.
     *
     * @param hoeveelVuur De 'krachtigheid' van de explosie van de speler.
     */
    void setHoeveelVuur(int value);
    /**
     * Hiermee pas je de snelheid van de speler aan.
     *
     * @param snelheid De snelheid van de speler.
     */
    void setSpeed(int value);
    /**
     * Hoe krachtig kan de explosie van de speler maximum zijn?
     *
     * @param maxVuur De maximale 'krachtigheid' van de explosie van de speler.
     */
    void setMaxVuur(int value);
    /**
     * Verander het voorwerp onder de speler.
     *
     * @param vwOnderSpeler Het nieuwe voorwerp dat je onder de speler wilt leggen.
     */
    void setThingUnderPlayer(Thing *value);
    /**
     * Verander het niet nader omschreven Voorwerp s
     *
     * @param s Het nieuwe voorwerp van de speler.
     */
    void setS(Thing *value);
    /**
     * Hiermee vermoord je de speler, het aantal levens wordt op nul gezet.
     */
    void maakDood();
    /**
     * Hiermee neem je een leven af van de speler.
     */
    void eenLevenMinder();
    /**
     * Hiermee geef je de speler een leven meer.
     */
    void eenLevenMeer();
    /**
     * Geef de speler max levens.
     */
    void geefMaxLevens();
    /**
     * Hiermee neem je een bom af van de speler.
     */
    void eenBomMinder();
    /**
     * Hiermee geef je de speler een bom meer.
     */
    void eenBomMeer();
    /**
     * Geef de speler max bommen.
     */
    void geefMaxBommen();

private:
    bool onFire = false;

    int playerNumber;
    Thing *thingUnderPlayer;
    Thing *s;

    // kan de speler shiften?
    bool shift = false;
    // kan de speler kicken?
    bool kick = false;
    // ONDER, BOVEN, LINKS, RECHTS
    Direction direction = Direction::ONDER;

    int aantalBommen = standaardBommen;
    int hoeveelVuur = standaardVuur;
    int lives = standaardLevens;
    int speed = standaardSnelheid;

    int maxVuur;
};

#endif // PLAYER_H
