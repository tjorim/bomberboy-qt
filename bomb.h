#ifndef BOMB_H
#define BOMB_H

#include "thing.h"

#include <QObject>
#include <QMediaPlayer>

/**
 * class Bomb
 *
 * @author Jorim Tielemans
 * @version 09/01/2017
 */
class Bomb: public QObject, public Thing
{
    Q_OBJECT

public:
    /**
     * Constructor voor objects van class Bom
     *
     * @param spelerNr Het nummer van de speler die de bom heeft gelegd.
     * @param vwOnderBom Het Thing onder de bom.
     */
    Bomb(int playerNumber, Thing *thingUnderBomb, QGraphicsItem *parent = nullptr);

    thingType getType() {return thingType::BOMB;}

    // Thing interface getters
    bool isEnterable();
    bool isFirePermeable();
    bool isOnFire() const;

    // getters
    /**
     * Wat ligt er onder de bom in het veld?
     *
     * @return het voorwerp onder de bom.
     */
    Thing *getThingUnderBomb() const;
    /**
     * Hiermee vraag je het nummer van de speler op.
     *
     * @return het nummer van de speler.
     */
    int getSpelerNr() const;
    /**
     * Geeft de starttijd van de bom terug.
     *
     * @return startTime Het tijdstip waarop de bom is neergelegd in milliseconden.
     */
    qint64 getStartTime() const;
    /**
     * Geeft terug of de bom nog moet ontploffen.
     *
     * @return vuurToDo True als de bom nog moet ontploffen.
     */
    bool getVuurToDo() const;
    /**
     * Geeft terug na hoeveel tijd de bom moet ontploffen.
     *
     * @return timerVuur De tijdsduur waarop de bom moet ontploffen in milliseconden.
     */
    int getTimerVuur() const;
    /**
     * Geeft terug of de bom nog moet worden gedoofd.
     *
     * @return doofToDo True als de bom nog moet worden gedoofd.
     */
    bool getDoofToDo() const;
    /**
     * Geeft terug na hoeveel tijd de bom moet worden gedoofd.
     *
     * @return timerDoof De tijdsduur waarop de bom moet worden gedoofd in milliseconden.
     */
    int getTimerDoof() const;

    // setters
    /**
     * Verander het voorwerp onder de bom.
     *
     * @param vwOnderBom Het nieuwe voorwerp dat je onder de bom wilt leggen.
     */
    void setThingUnderBomb(Thing *value);
    /**
     * Hiermee stel je het nummer van de speler in.
     *
     * @param spelerNr Het nummer van de speler.
     */
    void setSpelerNr(int value);
    /**
     * Stel de starttijd van de bom in.
     *
     * @param startTime De starttijd van de bom.
     */
    void setStartTime(qint64 value);
    /**
     * Stel in of de bom nog moet ontploffen.
     *
     * @param vuurToDo True als de bom nog moet ontploffen.
     */
    void setVuurToDo(const bool &value);
    /**
     * Stel in na hoeveel tijd de bom moet ontploffen.
     *
     * @param timerVuur De tijdsduur waarop de bom moet ontploffen in milliseconden.
     */
    void setTimerVuur(int value);
    /**
     * Stel in of de bom nog moet worden gedoofd.
     *
     * @param doofToDo True als de bom nog moet worden gedoofd.
     */
    void setDoofToDo(const bool &value);
    /**
     * Stel in na hoeveel tijd de bom moet worden gedoofd.
     *
     * @param timerDoof De tijdsduur waarop de bom moet worden gedoofd in milliseconden.
     */
    void setTimerDoof(int value);
    /**
     * Laat de bom ontploffen.
     *
     * @param vuur True indien de bom aan het ontploffen is.
     */
    void setOnFire(bool value);

public slots:
    void explode();

private:
    QMediaPlayer *bombSounds;
    bool onFire = false;
    Thing *thingUnderBomb;
    int playerNumber;

    qint64 startTime;
    bool vuurToDo = true;
    int timerVuur = 2000;
    bool doofToDo = true;
    int timerDoof = 3000;
};

#endif // BOMB_H
