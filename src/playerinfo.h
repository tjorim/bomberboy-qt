#ifndef PLAYERINFO_H
#define PLAYERINFO_H

#include <QGraphicsItem>
#include <QObject>

class PlayerInfo: public QGraphicsTextItem
{
public:
    PlayerInfo(QGraphicsItem *parent = nullptr);
    void increaseHealth();
    void decreaseHealth();
    int getHealth() const;
    void increaseBombs();
    void decreaseBombs();
    int getBombs() const;

private:
    int health;
    int bombs;
};

#endif // PLAYERINFO_H
