#include "player.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

#include "bomb.h"
#include "floor.h"

int Player::standaardBommen = 1;
int Player::maxBommen = 6;
int Player::standaardVuur = 1;
int Player::standaardLevens = 3;
int Player::maxLevens = 3;
int Player::standaardSnelheid = 1;
int Player::maxSnelheid = 6;

Player::Player(int playerNo, Thing *thingUnderPlayer, QGraphicsItem *parent)
    :playerNumber(playerNo), thingUnderPlayer(thingUnderPlayer), Thing(parent)
{
    setPixmap(QPixmap(":/images/rood_onder.gif"));

    // make the player focusable
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

int Player::getMaxSnelheid()
{
    return maxSnelheid;
}

int Player::getMaxLevens()
{
    return maxLevens;
}

int Player::getMaxBommen()
{
    return maxBommen;
}

bool Player::isEnterable()
{
    return true;
}

bool Player::isFirePermeable()
{
    return true;
}

bool Player::isOnFire() const
{
    return onFire;
}

void Player::setOnFire(bool value)
{
    onFire = value;
}

void Player::dropBomb()
{
    // create a bomb
    Bomb *bomb = new Bomb(playerNumber, new Floor());
    qDebug() << "Bomb created";
    bomb->setPos(x(), y());
    scene()->addItem(bomb);
}

void Player::setDirection(const Direction &value)
{
    switch (value) {
    case Direction::ONDER:
        setPixmap(QPixmap(":/images/rood_onder.gif"));
        break;
    case Direction::BOVEN:
        setPixmap(QPixmap(":/images/rood_boven.gif"));
        break;
    case Direction::LINKS:
        setPixmap(QPixmap(":/images/rood_links.gif"));
        break;
    case Direction::RECHTS:
        setPixmap(QPixmap(":/images/rood_rechts.gif"));
        break;
    default:
        break;
    }
    direction = value;
}

int Player::getAantalBommen() const
{
    return aantalBommen;
}

int Player::getHoeveelVuur() const
{
    return hoeveelVuur;
}

void Player::setHoeveelVuur(int value)
{
    if (getHoeveelVuur() < getMaxVuur()) {
        hoeveelVuur = value;
    } else {
        hoeveelVuur = maxVuur;
    }
}

int Player::getMaxVuur() const
{
    return maxVuur;
}

void Player::setMaxVuur(int value)
{
    maxVuur = value;
}

Thing *Player::getThingUnderPlayer() const
{
    return thingUnderPlayer;
}

void Player::setThingUnderPlayer(Thing *value)
{
    thingUnderPlayer = value;
}

Thing *Player::getS() const
{
    return s;
}

void Player::setS(Thing *value)
{
    s = value;
}

int Player::getLives() const
{
    return lives;
}

int Player::getSpeed() const
{
    return speed;
}

void Player::setSpeed(int value)
{
    if (getSpeed() < getMaxSnelheid()) {
        speed = value;
    } else {
        speed = maxSnelheid;
    }
}

int Player::getPlayerNumber() const
{
    return playerNumber;
}

void Player::setPlayerNumber(int value)
{
    playerNumber = value;
}

bool Player::canShift() const
{
    return shift;
}

void Player::setShift(bool value)
{
    shift = value;
}

bool Player::canKick() const
{
    return kick;
}

void Player::setKick(bool value)
{
    kick = value;
}

Player::Direction Player::getDirection() const
{
    return direction;
}

void Player::maakDood()
{
    lives = 0;
}

void Player::eenLevenMinder()
{
    lives--;
}

void Player::eenLevenMeer()
{
    if (getLives() < getMaxLevens())
    {
        lives++;
    }
    else
    {
        lives = maxLevens;
    }
}

void Player::geefMaxLevens()
{
    lives = maxLevens;
}

void Player::eenBomMinder()
{
    aantalBommen--;
}

void Player::eenBomMeer()
{
    if (getAantalBommen() < getMaxBommen()) {
        aantalBommen++;
    } else {
        aantalBommen = maxBommen;
    }
}

void Player::geefMaxBommen()
{
    aantalBommen = maxBommen;
}
