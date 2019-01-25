#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QMouseEvent>
#include <QGraphicsScene>

#include "thingboard.h"
#include "player.h"
#include "playerinfo.h"
#include "portal.h"

#include <iostream>
using namespace std;

class Game: public QGraphicsView
{
    Q_OBJECT

public:
    // constructors
    Game(QWidget *parent = nullptr);
    //~Game();

    // methods
    void gameOver();
    void addThingsToScene();

    // events
    /**
     * Dit zorgt ervoor dat we alle ingedrukte toetsen kunnen uitlezen,
     * hierbij worden bepaalde acties uitgevoerd.
     *
     * @param e Welke toetsenbordtoets er juist wordt ingedrukt.
     */
    void keyPressEvent(QKeyEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent* event);

    // attributes
    QGraphicsScene *scene;
    ThingBoard *thingBoard;
    PlayerInfo *playerInfo;

    /**
     * Hiermee leg je een bom op de plaats van de speler.
     * Afhankelijk van de vuurkracht van de speler ontploffen er meer blokskes.
     * Een explosie stopt aan een muur en kan maar 1 krat tegelijk laten ontploffen.
     *
     * @param speler Het nummer van de speler.
     */
    void legBom(int speler);

    /**
     * Hiermee leg je een bom op de plaats van de speler.
     * Afhankelijk van de vuurkracht van de speler ontploffen er meer blokskes.
     * Een explosie stopt aan een muur en kan maar 1 krat tegelijk laten ontploffen.
     *
     * @param speler Het nummer van de speler.
     */
    void bomHelper(Player *speler);



    /**
     * Hier gaan we in elke richting zover mogelijk voorwerpen nakijken
     * om in brand te steken. De breakflag beperkt de explosie.
     *
     * @param speler Het nummer van de speler.
     * @param bomX De x-coördinaat van de bom.
     * @param bomY De Y-coördinaat van de bom.
     * @param startTime Het tijdstip waarop de bom is neergelegd in milliseconden.
     */
    void vuurHelper(Player *speler, int bomX, int bomY, long startTime);

    /**
     * Acties die het vuur kan uitvoeren.
     *
     * @param x De x-coördinaat van de plaats die momenteel wordt nagekeken.
     * @param y De Y-coördinaat van de plaats die momenteel wordt nagekeken.
     * @param startTime Het tijdstip waarop de bom is neergelegd in milliseconden.
     *
     * @return True or false, dit bepaald of de explosie nog verder kan of niet.
     */
    bool vuurActies(int x, int y, long startTime);

    /**
     * Kruit aansteken.
     */
    void vuurKruit();

    /**
     * Beweeg 1 vakje naar links.
     *
     * @param speler Het nummer van de speler.
     */
    void beweegLinks(int speler);

    /**
     * Beweeg 1 vakje naar rechts.
     *
     * @param speler Het nummer van de speler.
     */
    void beweegRechts(int speler);

    /**
     * Beweeg 1 vakje naar boven.
     *
     * @param speler Het nummer van de speler.
     */
    void beweegBoven(int speler);

    /**
     * Beweeg 1 vakje naar onder.
     *
     * @param speler Het nummer van de speler.
     */
    void beweegOnder(int speler);

    static int getWidth();

    static int getHeight();

    QList<Player *> getPlayers() const;

    // mss nog private maken
    Portal *portaal1A = new Portal(1, 1);
    Portal *portaal1B = new Portal(1, 2);
    Portal *portaal2A = new Portal(2, 1);
    Portal *portaal2B = new Portal(2, 2);

public slots:
    void reset(int levelNrValue);
    void start(int levelNr);

    /**
     * Hiermee maak je vuur rondom een bom.
     * Afhankelijk van de vuurkracht van de speler ontploffen er meer blokskes.
     * De bomLinks, -recht, etc. zorgen ervoor dat het vuur niet voorbij de muur kan.
     *
     * @param speler Het nummer van de speler.
     * @param bomX De x-coördinaat van de bom.
     * @param bomY De Y-coördinaat van de bom.
     * @param startTime Het tijdstip waarop de bom is neergelegd in milliseconden.
     */
    void bomVuur(int speler, int bomX, int bomY, long startTime);

protected:
    /**
     * Hier geven we, afhankelijk van wie de beweging doet (het spelersnummer), de juiste variabelen mee aan de beweeghelper,
     * dit doen we om dubbele code met als enigste verschil andere variabelen te vermijden.
     *
     * @param dx Delta-x: verandering in de x-richting.
     * @param dy Delta-y: verandering in de y-richting.
     * @param speler Het nummer van de speler.
     */
    void beweeg(int dx, int dy, int speler);

    /**
     * Beweeg in een dx-dy richting.
     *
     * @param dx Delta-x: verandering in de x-richting.
     * @param dy Delta-y: verandering in de y-richting.
     * @param speler De speler die de beweging uitvoert.
     * @param spelerZ De andere speler.
     */
    void beweegHelper(int dx, int dy, Player *speler);

    /**
     * 1,2,3,4=bewegen
     * 5=bom leggen
     */
    void willekeurigeActie();

    /**
     * 0=beweeglinks
     * 1=beweegrecht
     * 2=beweegonder
     * 3=beweegboven
     */
    void willekeurigBewegen(int rndspeler);

private:
    static int width; //de breedte van het raster
    static int height; //de hoogte van het raster

    int doelX, doelY;
    Thing *doel;
    int volgX, volgY;
    Thing *volg;

    int numberOfPlayers = 2;

    int levelNr = 1;
    int numberOfPups;
    bool isSomeoneDead = false;

    QList<Player *> players;
};

#endif // GAME_H
