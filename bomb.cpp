#include "bomb.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QDateTime>

#include "game.h"
extern Game *game;

Bomb::Bomb(int playerNumber, Thing *thingUnderBomb, QGraphicsItem *parent)
    :playerNumber(playerNumber), thingUnderBomb(thingUnderBomb), Thing(parent)
{
    setPixmap(QPixmap(":/images/bom.gif"));

    setStartTime(QDateTime::currentMSecsSinceEpoch());

    // play background music
    bombSounds = new QMediaPlayer();
    bombSounds->setMedia(QUrl("qrc:/sounds/BombDrop.wav"));
    bombSounds->play();

    // create the timer
    QTimer * timer = new QTimer(this);
    // connect the timer
    connect(timer, &QTimer::timeout, this, &Bomb::explode);
    // start the timer
    timer->start(5000);
}

void Bomb::explode()
{
    // play background music
    bombSounds->setMedia(QUrl("qrc:/sounds/BombExplosion.wav"));
    bombSounds->play();

    setOnFire(true);
    game->bomVuur(playerNumber, getXCo(), getYCo(), 0);

    // delete the bomb
    //scene()->removeItem(this);
    delete this;
    qDebug() << "Bomb deleted";
}

bool Bomb::isEnterable()
{
    return false;
}

bool Bomb::isFirePermeable()
{
    return true;
}

bool Bomb::isOnFire() const
{
    return onFire;
}

void Bomb::setOnFire(bool value)
{
    setPixmap(QPixmap(":/images/explosie.gif"));
    onFire = value;
}

Thing *Bomb::getThingUnderBomb() const
{
    return thingUnderBomb;
}

int Bomb::getSpelerNr() const
{
    return playerNumber;
}

qint64 Bomb::getStartTime() const
{
    return startTime;
}

bool Bomb::getVuurToDo() const
{
    return vuurToDo;
}

int Bomb::getTimerVuur() const
{
    return timerVuur;
}

bool Bomb::getDoofToDo() const
{
    return doofToDo;
}

int Bomb::getTimerDoof() const
{
    return timerDoof;
}

void Bomb::setThingUnderBomb(Thing *value)
{
    thingUnderBomb = value;
}

void Bomb::setSpelerNr(int value)
{
    playerNumber = value;
}

void Bomb::setStartTime(qint64 value)
{
    startTime = value;
}

void Bomb::setVuurToDo(const bool &value)
{
    vuurToDo = value;
}

void Bomb::setTimerVuur(int value)
{
    timerVuur = value;
}

void Bomb::setDoofToDo(const bool &value)
{
    doofToDo = value;
}

void Bomb::setTimerDoof(int value)
{
    timerDoof = value;
}
