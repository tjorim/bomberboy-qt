#ifndef THING_H
#define THING_H

#include <QGraphicsItem>
#include <QDebug>
#include <QPixmap>

/**
 * Abstract class Thing
 *
 * @author Jorim Tielemans
 * @version 05/01/2017
 */
class Thing: public QGraphicsPixmapItem
{
public:
    Thing(QGraphicsItem *parent = nullptr):QGraphicsPixmapItem(parent){}

    /**
     * Enumeration class POWER - geef hier een beschrijving van de enum class
     * we only have seven powers, so no need for ints!
     */
    enum class thingType: char {BOMB = 1, CRATE = 2, FLOOR = 3, GUNPOWDER = 4, PLAYER = 5, PORTAL = 6, POWERUP = 7, WALL = 8};

    /**
     * Is het voorwerp betreedbaar?
     *
     * @return true indien betreedbaar.
     */
    virtual bool isEnterable() = 0;

    /**
     * Laat dit voorwerp vuur door van een bom?
     *
     * @return true indien het vuur doorlaat.
     */
    virtual bool isFirePermeable() = 0;

    /**
     * Staat het voorwerp in vuur en vlam, ten gevolgen van een explosie?
     *
     * @return true indien in brand.
     */
    virtual bool isOnFire() const = 0;

    /**
     * @brief What type is this thing?
     * @return thingType
     */
    virtual thingType getType() = 0;

    /**
     * Is het voorwerp breekbaar, ten gevolgen van een explosie?
     *
     * @return true indien breekbaar.
     */
    virtual bool isBreakable() {return false;}

    /**
     * Kan je dit voorwerp oprapen?
     *
     * @return true indien je het kan oprapen.
     */
    virtual bool isCollectable() {return false;}

    /**
     * Wat is de x-positie van this Thing?
     *
     * @return De x-positie van this Thing.
     */
    int getXCo() const {return xCo;}
    /**
     * Stel de x-positie van de speler in.
     *
     * @param xCo De x-positie van de speler.
     */
    void setXCo(int value)
    {
        setX(30*value);
        xCo = value;
    }

    /**
     * Wat is de y-positie van this Thing?
     *
     * @return De y-positie van this Thing.
     */
    int getYCo() const {return yCo;}
    /**
     * Stel de y-positie van de speler in.
     *
     * @param yCo De y-positie van de speler.
     */
    void setYCo(int value)
    {
        setY(30*value);
        yCo = value;
    }

    QPointF getLoc() const { return QPointF(xCo, yCo); }
    void setLoc(int xValue, int yValue)
    {
        setXCo(xValue);
        setYCo(yValue);
    }

private:
    // De x-positie van the Thing
    int xCo;
    // De y-positie van the Thing
    int yCo;
};

#endif // THING_H
