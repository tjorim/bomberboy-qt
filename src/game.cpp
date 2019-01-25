#include "game.h"

#include <QTimer>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QGraphicsItem>
#include <QUrl>
#include <QPixmap>
#include <QBrush>
#include <QImage>
#include <QDateTime>

#include "bomb.h"
#include "crate.h"
#include "floor.h"
#include "gunpowder.h"
#include "powerup.h"
#include "wall.h"

int Game::width = 21;
int Game::height = 15;

Game::Game(QWidget *parent)
{
    // set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024, 768);

    // Initialize generator seed with current time
    qsrand((uint)QDateTime::currentMSecsSinceEpoch());

    start(levelNr);

    // play background music
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/Cataclysmic_Molten_Core.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->setVolume(50);
    music->play();
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if (!isSomeoneDead) {
        switch (event->key()) {
        case Qt::Key_Space:
            if (!players[0]->isOnFire())
            {
                legBom(0);
            }
            break;
        case Qt::Key_Q:
            if (!players[0]->isOnFire())
            {
                beweegLinks(0);
            }
            break;
        case Qt::Key_D:
            if (!players[0]->isOnFire())
            {
                beweegRechts(0);
            }
            break;
        case Qt::Key_Z:
            if (!players[0]->isOnFire())
            {
                beweegBoven(0);
            }
            break;
        case Qt::Key_S:
            if (!players[0]->isOnFire())
            {
                beweegOnder(0);
            }
            break;

        case Qt::Key_0: // NUMPAD0 is bom leggen voor speler 2
            if (!players[1]->isOnFire())
            {
                legBom(1);
            }
            break;
        case Qt::Key_Left: // is naar links voor speler 2
            if (!players[1]->isOnFire())
            {
                beweegLinks(1);
            }
            break;
        case Qt::Key_Right: // is naar rechts voor speler 2
            if (!players[1]->isOnFire())
            {
                beweegRechts(1);
            }
            break;
        case Qt::Key_Up: // is naar boven voor speler 2
            if (!players[1]->isOnFire())
            {
                beweegBoven(1);
            }
            break;
        case Qt::Key_Down: // is naar beneden voor speler 2
            if (!players[1]->isOnFire())
            {
                beweegOnder(1);
            }
            break;

        case Qt::Key_5: // doe iets willekeurigs
            willekeurigeActie();
            break;

        default:
            break;
        }
    }
}

/**
 * Beweeg 1 vakje naar links.
 *
 * @param speler Het nummer van de speler.
 */
void Game::beweegLinks(int speler)
{
    if (players[speler]->getXCo() > 0) {
        players[speler]->setDirection(Player::Direction::LINKS);
        beweeg(-1,0,speler);
    }
}

/**
 * Beweeg 1 vakje naar rechts.
 *
 * @param speler Het nummer van de speler.
 */
void Game::beweegRechts(int speler)
{
    if (players[speler]->getXCo() < width-1) {
        players[speler]->setDirection(Player::Direction::RECHTS);
        beweeg(1,0,speler);
    }
}

/**
 * Beweeg 1 vakje naar boven.
 *
 * @param speler Het nummer van de speler.
 */
void Game::beweegBoven(int speler)
{
    if (players[speler]->getYCo() > 0) {
        players[speler]->setDirection(Player::Direction::BOVEN);
        beweeg(0,-1,speler);
    }
}

/**
 * Beweeg 1 vakje naar onder.
 *
 * @param speler Het nummer van de speler.
 */
void Game::beweegOnder(int speler)
{
    if (players[speler]->getYCo() < height-1) {
        players[speler]->setDirection(Player::Direction::ONDER);
        beweeg(0,1,speler);
    }
}

void Game::gameOver()
{

}

void Game::addThingsToScene() //int width, int height
{
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++)
        {
            scene->addItem(thingBoard->getThing(i, j));
        }
    }
}

void Game::mouseMoveEvent(QMouseEvent *event)
{

}

void Game::mousePressEvent(QMouseEvent *event)
{

}

void Game::legBom(int speler)
{
    bomHelper(players[speler]);
    /*
    switch (speler) {
        case 1:
        bomHelper(speler, speler1);
        break;
        case 2:
        bomHelper(speler, speler2);
        break;
    }
    // */
}

void Game::bomHelper(Player *speler)
{
    //speler->dropBomb();
    if(speler->getAantalBommen() > 0)
    {
        if(speler->getThingUnderPlayer()->getType() == Thing::thingType::FLOOR)
        {
            // create a bomb with floor under it
            Bomb *bomb = new Bomb(speler->getPlayerNumber(), new Floor());
            qDebug() << "Bomb created";
            bomb->setPos(speler->getXCo(), speler->getYCo());
            scene->addItem(bomb);
            //speler->setThingUnderPlayer(new Bomb(speler->getPlayerNumber(), new Floor()));
        }
        else if(speler->getThingUnderPlayer()->getType() == Thing::thingType::GUNPOWDER)
        {
            // create a bomb with gunpowder under it
            /*Bomb *bomb = new Bomb(speler->getPlayerNumber(), new Gunpowder());
            qDebug() << "Bomb created";
            bomb->setPos(speler->getXCo(), speler->getYCo());
            scene->addItem(bomb);
            */speler->setThingUnderPlayer(new Bomb(speler->getPlayerNumber(), new Gunpowder()));
        }
        speler->eenBomMinder();
        //speelGeluidje(BombDrop);
    }
}

void Game::bomVuur(int speler, int bomX, int bomY, long startTime)
{
    vuurHelper(players[speler], bomX, bomY, startTime);
}

void Game::vuurHelper(Player *speler, int bomX, int bomY, long startTime)
{
    //speelGeluidje(BombeExplode);
    // Naar boven
    bool breakFlag = false;
    for (int j = bomY-1; j > bomY-speler->getHoeveelVuur()-1 && !breakFlag; j--)
    {
        breakFlag = vuurActies(bomX, j, startTime);
    }
    // Naar rechts
    breakFlag = false;
    for (int i = bomX+1; i < bomX+speler->getHoeveelVuur()+1 && !breakFlag; i++)
    {
        breakFlag = vuurActies(i, bomY, startTime);
    }
    // Naar onder
    breakFlag = false;
    for (int j = bomY+1; j < bomY+speler->getHoeveelVuur()+1 && !breakFlag; j++)
    {
        breakFlag = vuurActies(bomX, j, startTime);
    }
    // Naar links
    breakFlag = false;
    for (int i = bomX-1; i > bomX-speler->getHoeveelVuur()-1 && !breakFlag; i--)
    {
        breakFlag = vuurActies(i, bomY, startTime);
    }
}

bool Game::vuurActies(int x, int y, long startTime)
{
    Thing *th = thingBoard->getThing(x, y);
    if(th->getType() == Thing::thingType::WALL || th->getType() == Thing::thingType::PORTAL)
    {
        return true;
    }
    else if(th->getType() == Thing::thingType::BOMB)
    {
        Bomb* bo= dynamic_cast<Bomb*>(th);
        //bo.setStartTime(startTime);
    }
    else if (th->getType() == Thing::thingType::CRATE) {
        Crate* cr= dynamic_cast<Crate*>(th);
        cr->setOnFire(true);
        return true;
    }
    else if (th->getType() == Thing::thingType::POWERUP) {
        PowerUp* po= dynamic_cast<PowerUp*>(th);
        po->setOnFire(true);
        return true;
    }
    else if (th->getType() == Thing::thingType::FLOOR) {
        Floor* fl= dynamic_cast<Floor*>(th);
        fl->setOnFire(true);
    }
    else if (th->getType() == Thing::thingType::PLAYER) {
        Player* pl= dynamic_cast<Player*>(th);
        pl->setOnFire(true);
    }
    else if (th->getType() == Thing::thingType::GUNPOWDER) {
        vuurKruit();
    }
    return false;
}

void Game::vuurKruit()
{
    for (int i=0; i < getWidth(); i++)
    {
        for (int j=0; j < getHeight(); j++)
        {
            Thing *th = thingBoard->getThing(i, j);
            if (th->getType() == Thing::thingType::GUNPOWDER)
            {
                Gunpowder* gu= dynamic_cast<Gunpowder*>(th);
                gu->setOnFire(true);
            }
            else if (th->getType() == Thing::thingType::PLAYER)
            {
                Player* pl= dynamic_cast<Player*>(th);
                if (pl->getThingUnderPlayer()->getType() == Thing::thingType::GUNPOWDER)
                {
                    pl->setOnFire(true);
                }
            }
        }
    }
}

void Game::beweeg(int dx, int dy, int speler)
{
    beweegHelper(dx, dy, players[speler]);
}

void Game::beweegHelper(int dx, int dy, Player *speler)
{
    /*
    Thing *nieuw = speler;

    thingBoard->placeThing(speler->getXCo(), speler->getYCo(), doel);

    speler->setXCo(doelX);
    speler->setYCo(doelY);

    thingBoard->placeThing(speler->getXCo(), speler->getYCo(), nieuw);
    // */

    //getVoorwerp(speler.getX(), speler.getY()));

//    setVoorwerp(speler.getX(), speler.getY(), speler.getVwOnderSpeler());
//    speler.setVwOnderSpeler(doel);
//    setVoorwerp(doelX, doelY, speler.getS());
    //*
    speler->setS(thingBoard->getThing( speler->getXCo(), speler->getYCo()));

    doelX = speler->getXCo() + dx;
    doelY = speler->getYCo() + dy;

    doel  = thingBoard->getThing(doelX, doelY);

    volgX = doelX + dx;
    volgY = doelY + dy;

    volg  = thingBoard->getThing(volgX, volgY);

    if (speler->getS()->getType() == Thing::thingType::WALL || speler->getLives() == 0)
    {
        speler->maakDood();
        return;
    }
    /*
    if (doel->getType() == Thing::thingType::BOMB && speler->canShift() && volg->getType() != Thing::thingType::PLAYER)
    {
        Thing *bom = thingBoard->getThing(doelX, doelY);
        try
        {
            if (volg->isEnterable())
            {
                //Bomb bo = (Bom)doel;
                thingBoard->placeThing(volgX, volgY, bom);
                thingBoard->placeThing(doelX, doelY, speler);
                thingBoard->placeThing(speler->getXCo(), speler->getYCo(), new Floor());
                //bo.setX(volgX);
                //bo.setY(volgY);
                //speler->setXCo(doelX);
                //speler->setYCo(doelY);
            }
        }
        catch (int e) {} // ArrayIndexOutOfBoundsException
        return;
    }
    // */
    if(doel->isEnterable() && !doel->isOnFire())
    {
        if (doel->getType() == Thing::thingType::POWERUP) {
            //speelGeluidje(Select);
            Player* playerPower = dynamic_cast<Player*>(speler);
            switch (dynamic_cast<PowerUp*>(doel)->getPower()) {
            case PowerUp::Power::EXTRA_BOM:
                playerPower->eenBomMeer();
                break;
            case PowerUp::Power::MEER_VLAM:
                playerPower->setHoeveelVuur(playerPower->getHoeveelVuur()+1);
                break;
            case PowerUp::Power::GOLDENFLAME:
                playerPower->setHoeveelVuur(playerPower->getMaxVuur());
                break;
            case PowerUp::Power::KICKER:
                playerPower->setKick(true);
                break;
            case PowerUp::Power::EXTRA_LEVEN:
                playerPower->eenLevenMeer();
                break;
            case PowerUp::Power::SHIFTER:
                playerPower->setShift(true);
                break;
                playerPower->setSpeed(playerPower->getSpeed()+1);
            case PowerUp::Power::SNELLER_LOPEN:
                break;
            }
            if (speler->getType() != Thing::thingType::BOMB)
            {
                speler->setThingUnderPlayer(new Floor());
            }
            thingBoard->placeThing(speler->getXCo(), speler->getYCo(), speler->getThingUnderPlayer());
            thingBoard->placeThing(doelX, doelY, speler->getS());
            /*if (speler->getThingUnderPlayer()->getType() == Thing::thingType::BOMB)
            {
                speler->setThingUnderPlayer(new Floor());
            }*/
        }
        /*
        else if (doel->getType() == Thing::thingType::PORTAL)
        {
            Portal* pu = dynamic_cast<Portal*>(doel);
            if (pu->getPortaalNr() == 1)
            {
                if (pu->getPoortNr() == 1)
                {
                    poortHelper(portaal1B, speler, spelerZ);
                }
                else if (pu->getPoortNr() == 2)
                {
                    poortHelper(portaal1A, speler, spelerZ);
                }
            }
            else if (pu->getPortaalNr() == 2)
            {
                if (pu->getPoortNr() == 1)
                {
                    poortHelper(portaal2B, speler, spelerZ);
                }
                else if (pu->getPoortNr() == 2)
                {
                    poortHelper(portaal2A, speler, spelerZ);
                }
            }
            return;
        }
        /*
        else if(spelerZ.getVwOnderSpeler() instanceof Speler)
        {
            setVoorwerp(doelX, doelY, spelerZ.getVwOnderSpeler());
            spelerZ.setVwOnderSpeler(speler.getVwOnderSpeler());
            speler.setVwOnderSpeler(doel);
        }
        // */
        else
        {
            thingBoard->placeThing(speler->getXCo(), speler->getYCo(), speler->getThingUnderPlayer());
            speler->setThingUnderPlayer(doel);
            thingBoard->placeThing(doelX, doelY, speler->getS());
            /*
            if(!(spelerZ.getVwOnderSpeler() instanceof Portaal))
            {
                //switch (laatstgebruikteportaal) {
                //    case 1:
                //        portaal1A.maakVrij(true);
                //        portaal1B.maakVrij(true);
                //        break;
                //else if (pu.getPortaalNr() == 2)
                //{
                //    portaal2A.maakVrij(true);
                //    portaal2B.maakVrij(true);
                //} DEZE SHIT MOET NOG WORDEN OPGELOST
                portaal2A.maakVrij(true);
                    portaal2B.maakVrij(true);
                    portaal1A.maakVrij(true);
                        portaal1B.maakVrij(true);
            }
            // */
        }
        speler->setXCo(doelX);
        speler->setYCo(doelY);
    }
    else
    {
        return;
    }
    // */
}

void Game::willekeurigeActie()
{
    if (!isSomeoneDead)
    {
        // Generate a random number from that seed
        int rndspeler = qrand()%2;
        qDebug() << rndspeler;
        int rndactie = qrand()%5;
        qDebug() << rndactie;
        if (rndactie == 4) {
            willekeurigBewegen(rndspeler);
        } else {
            legBom(rndspeler);
        }
    }
}

void Game::willekeurigBewegen(int rndspeler)
{
    if (!isSomeoneDead)
    {
        int rndrichting = qrand()%4;
        qDebug() << rndrichting;
        switch (rndrichting)
        {
            case 0: beweegLinks(rndspeler); break;
            case 1: beweegRechts(rndspeler); break;
            case 2: beweegOnder(rndspeler); break;
            case 3: beweegBoven(rndspeler); break;
        }
    }
}

void Game::reset(int levelNrValue)
{
    levelNr = levelNrValue;
    //setIsHetSpelGereset(true);
    start(levelNr);
}

void Game::start(int levelNr)
{
    // set up the scene
    scene = new QGraphicsScene(0, 0, 1024, 768);
    //scene->setBackgroundBrush(QBrush(QImage("qrc:/images/grond.gif")));
    setScene(scene);

    //speelGeluidje(GameStart);
    //setIsErEenDode(false);
    //setIsHetSpelGereset(false);

    // create the board
    thingBoard = new ThingBoard();

    // create the players
    for (int i = 0; i < numberOfPlayers; ++i) {
        players.append(new Player(i, new Floor()));
        players[i]->setMaxVuur((getHeight()-3)/2);
    }

    // empty the board
    thingBoard->createBoard(height, width);

    // fill the board
    thingBoard->load(levelNr);

    if (levelNr == 1)
    {
        thingBoard->placeThing(1, 1, players[0]);
        thingBoard->placeThing(width-2, height-2, players[1]);

        numberOfPups = 59;
    }
    else if (levelNr == 2)
    {
        thingBoard->placeThing(1, 7, players[0]);
        thingBoard->placeThing(width-2, height-8, players[1]);

        numberOfPups = 0;
    }
    else if (levelNr == 3)
    {
        thingBoard->placeThing(3, 3, portaal1A);
        thingBoard->placeThing(width-4, height-4, portaal1B);
        thingBoard->placeThing(width-4, 3, portaal2A);
        thingBoard->placeThing(3, height-4, portaal2B);

        thingBoard->placeThing(1, 1, players[0]);
        thingBoard->placeThing(width-2, height-2, players[1]);

        numberOfPups = 49;
    }
    else if (levelNr == 4)
    {
        thingBoard->placeThing(1, 1, players[0]);
        thingBoard->placeThing(width-2, height-2, players[1]);

        numberOfPups = 0;

        // set max powers
        for (int i = 0; i < numberOfPlayers; ++i) {
            players[i]->geefMaxBommen();
            players[i]->setHoeveelVuur(players[i]->getMaxVuur());
            players[i]->setSpeed(players[i]->getMaxSnelheid());
            players[i]->setKick(true);
            players[i]->setShift(true);
        }
    }

    thingBoard->verdeelPowerUp(numberOfPups);

    // add everything to the scene
    addThingsToScene();

    // create the info
    playerInfo = new PlayerInfo();
    scene->addItem(playerInfo);
}

QList<Player *> Game::getPlayers() const
{
    return players;
}

int Game::getHeight()
{
    return height;
}

int Game::getWidth()
{
    return width;
}

/*
    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, player, &Player::spawn);
    timer->start(2000);
// */
