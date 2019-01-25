#include "thingboard.h"

#include <QGraphicsScene>
#include <QDebug>

#include "crate.h"
#include "floor.h"
#include "gunpowder.h"
#include "wall.h"

#include "game.h"
extern Game *game;

ThingBoard::ThingBoard()
{
}

QList<QList<Thing *> > ThingBoard::getBoard() const
{
    return board;
}

void ThingBoard::createBoard(int width, int height)
{
    for (int i = 0; i < height; i++) {
        QList<Thing *> column;
        for (int j = 0; j < width; j++)
        {
            column.append(nullptr);
            //row.append(new QGraphicsPixmapItem()); // or Thing()
        }
        board.append(column);
    }
}

void ThingBoard::placeThing(int x, int y, Thing *thing)
{
    board[x][y] = thing;
    board[x][y]->setLoc(x, y);
    //game->scene->addItem(board[x][y]);
}

Thing *ThingBoard::getThing(int x, int y)
{
    // defensief programmeren
    if (x<0 || x>=game->getWidth() || y<0 || y>=game->getHeight()) {
        return nullptr;
    }
    return board[x][y];
}

void ThingBoard::load(int levelNr)
{
    for (int muurX = 0; muurX < game->getWidth(); muurX++) {
        placeThing(muurX, 0, new Wall());
        placeThing(muurX, game->getHeight()-1, new Wall());
    }
    for (int muurY = 1; muurY < game->getHeight()-1; muurY++) {
        placeThing(0, muurY, new Wall());
        placeThing(game->getWidth()-1, muurY, new Wall());
    }
    for (int muurX = 2; muurX < game->getWidth()-2; muurX = muurX+2){
        for (int muurY = 2; muurY < game->getHeight()-2; muurY = muurY+2){
            placeThing(muurX, muurY, new Wall());
        }
    }

    switch (levelNr)
    {
    case 1:
    default:
        level1();
        break;
    case 2:
        level2();
        break;
    case 3:
        level3();
        break;
    case 4:
        level4();
        break;
    }
}

void ThingBoard::level1()
{
    for (int kratX = 1; kratX < game->getWidth()-1; kratX++){
        for (int kratY = 1; kratY < game->getHeight()-1; kratY++){
            if((kratX % 2) == 1){
                placeThing(kratX, kratY, new Crate());
            }
            if((kratY % 2) == 1){
                placeThing(kratX, kratY, new Crate());
            }
        }
    }

    placeThing(2, 1, new Floor());
    placeThing(1, 2, new Floor());
    placeThing(game->getWidth()-3, game->getHeight()-2,   new Floor());
    placeThing(game->getWidth()-2,   game->getHeight()-3, new Floor());
    /*
    placeThing(game->getPlayers()[0]->getXCo(),   game->getPlayers()[0]->getYCo(),   game->getPlayers()[0]);
    placeThing(game->getPlayers()[0]->getXCo()+1, game->getPlayers()[0]->getYCo(),   new Floor());
    placeThing(game->getPlayers()[0]->getXCo(),   game->getPlayers()[0]->getYCo()+1, new Floor());
    placeThing(game->getPlayers()[1]->getXCo(),   game->getPlayers()[1]->getYCo(),   game->getPlayers()[1]);
    placeThing(game->getPlayers()[1]->getXCo()-1, game->getPlayers()[1]->getYCo(),   new Floor());
    placeThing(game->getPlayers()[1]->getXCo(),   game->getPlayers()[1]->getYCo()-1, new Floor());
    // */
    //speler3
    placeThing(1, game->getHeight()-2, new Floor());
    placeThing(2, game->getHeight()-2, new Floor());
    placeThing(1, game->getHeight()-3, new Floor());
    //speler4
    placeThing(game->getWidth()-2, 1, new Floor());
    placeThing(game->getWidth()-3, 1, new Floor());
    placeThing(game->getWidth()-2, 2, new Floor());
}

void ThingBoard::level2()
{
    for (int grondX = 1; grondX < game->getWidth()-1; grondX++){
        for (int grondY = 1; grondY < game->getHeight()-1; grondY++){
            if((grondX % 2) == 1){
                placeThing(grondX, grondY, new Floor());
            }
            if((grondY % 2) == 1){
                placeThing(grondX, grondY, new Floor());
            }
        }
    }

    /*
    placeThing(game->getPlayers()[0]->getXCo(), game->getPlayers()[0]->getYCo(), game->getPlayers()[0]);
    placeThing(game->getPlayers()[0]->getXCo(), game->getPlayers()[0]->getYCo()+1, new Crate());
    placeThing(game->getPlayers()[1]->getXCo(), game->getPlayers()[1]->getYCo(), game->getPlayers()[1]);
    placeThing(game->getPlayers()[1]->getXCo(), game->getPlayers()[1]->getYCo()-1, new Crate());
    // */

    placeThing(9,  4, new Crate());
    placeThing(9,  5, new Crate());
    placeThing(10, 5, new Crate());
    placeThing(11, 5, new Crate());
    placeThing(11, 4, new Crate());

    placeThing(game->getWidth()-12, game->getHeight()-5, new Crate());
    placeThing(game->getWidth()-12, game->getHeight()-6, new Crate());
    placeThing(game->getWidth()-11, game->getHeight()-6, new Crate());
    placeThing(game->getWidth()-10, game->getHeight()-6, new Crate());
    placeThing(game->getWidth()-10, game->getHeight()-5, new Crate());

    placeThing(1, 3, new Crate());
    placeThing(1, 2, new Crate());
    placeThing(1, 1, new Crate());
    placeThing(2, 1, new Crate());
    placeThing(3, 1, new Crate());

    placeThing(game->getWidth()-2, game->getHeight()-4, new Crate());
    placeThing(game->getWidth()-2, game->getHeight()-3, new Crate());
    placeThing(game->getWidth()-2, game->getHeight()-2, new Crate());
    placeThing(game->getWidth()-3, game->getHeight()-2, new Crate());
    placeThing(game->getWidth()-4, game->getHeight()-2, new Crate());

    placeThing(1, game->getHeight()-4, new Crate());
    placeThing(1, game->getHeight()-3, new Crate());
    placeThing(1, game->getHeight()-2, new Crate());
    placeThing(2, game->getHeight()-2, new Crate());
    placeThing(3, game->getHeight()-2, new Crate());

    placeThing(game->getWidth()-2, 3, new Crate());
    placeThing(game->getWidth()-2, 2, new Crate());
    placeThing(game->getWidth()-2, 1, new Crate());
    placeThing(game->getWidth()-3, 1, new Crate());
    placeThing(game->getWidth()-4, 1, new Crate());

    for (int kruitX = 5; kruitX < game->getWidth()-5; kruitX++) {
        placeThing(kruitX, 3, new Gunpowder());
        placeThing(kruitX, game->getHeight()-4, new Gunpowder());
    }
    for (int kruitY = 4; kruitY < game->getHeight()-4; kruitY++) {
        placeThing(5, kruitY, new Gunpowder());
        placeThing(game->getWidth()-6, kruitY, new Gunpowder());
    }
}

void ThingBoard::level3()
{
    for (int kratX = 1; kratX < game->getWidth()-1; kratX++){
        for (int kratY = 1; kratY < game->getHeight()-1; kratY++){
            if((kratX % 2) == 1){
                placeThing(kratX, kratY, new Crate());
            }
            if((kratY % 2) == 1){
                placeThing(kratX, kratY, new Crate());
            }
        }
    }

    placeThing(2, 1,   new Floor());
    placeThing(3, 1,   new Floor());
    placeThing(4, 1,   new Floor());
    placeThing(5, 1,   new Floor());
    placeThing(1, 2, new Floor());
    placeThing(1, 3, new Floor());
    placeThing(1, 4, new Floor());
    placeThing(3, 2, new Floor());
    placeThing(2, 3, new Floor());

    placeThing(game->getWidth()-3, game->getHeight()-2,   new Floor());
    placeThing(game->getWidth()-4, game->getHeight()-2,   new Floor());
    placeThing(game->getWidth()-5, game->getHeight()-2,   new Floor());
    placeThing(game->getWidth()-6, game->getHeight()-2,   new Floor());
    placeThing(game->getWidth()-2, game->getHeight()-3, new Floor());
    placeThing(game->getWidth()-2, game->getHeight()-4, new Floor());
    placeThing(game->getWidth()-2, game->getHeight()-5, new Floor());
    placeThing(game->getWidth()-4, game->getHeight()-3, new Floor());
    placeThing(game->getWidth()-3, game->getHeight()-4, new Floor());

    //speler3
    placeThing(1, game->getHeight()-2, new Floor());
    placeThing(2, game->getHeight()-2, new Floor());
    placeThing(3, game->getHeight()-2, new Floor());
    placeThing(4, game->getHeight()-2, new Floor());
    placeThing(5, game->getHeight()-2, new Floor());
    placeThing(1, game->getHeight()-3, new Floor());
    placeThing(1, game->getHeight()-4, new Floor());
    placeThing(1, game->getHeight()-5, new Floor());
    placeThing(3, game->getHeight()-3, new Floor());
    placeThing(2, game->getHeight()-4, new Floor());

    //speler4
    placeThing(game->getWidth()-2, 1, new Floor());
    placeThing(game->getWidth()-3, 1, new Floor());
    placeThing(game->getWidth()-4, 1, new Floor());
    placeThing(game->getWidth()-5, 1, new Floor());
    placeThing(game->getWidth()-6, 1, new Floor());
    placeThing(game->getWidth()-2, 2, new Floor());
    placeThing(game->getWidth()-2, 3, new Floor());
    placeThing(game->getWidth()-2, 4, new Floor());
    placeThing(game->getWidth()-4, 2, new Floor());
    placeThing(game->getWidth()-3, 3, new Floor());
}

void ThingBoard::level4()
{
    for (int grondX = 1; grondX < game->getWidth()-1; grondX++){
        for (int grondY = 1; grondY < game->getHeight()-1; grondY++){
            if((grondX % 2) == 1){
                placeThing(grondX, grondY, new Floor());
            }
            if((grondY % 2) == 1){
                placeThing(grondX, grondY, new Floor());
            }
        }
    }
    /*
    placeThing(game->getPlayers()[0]->getXCo(),   game->getPlayers()[0]->getYCo(),   game->getPlayers()[0]);
    placeThing(game->getPlayers()[1]->getXCo(),   game->getPlayers()[1]->getYCo(),   game->getPlayers()[1]);
    // */
}

PowerUp::Power ThingBoard::getRandomPower()
{
    char elem = 1+(qrand()%7);
    return PowerUp::Power(elem);
}

void ThingBoard::verdeelPowerUp(int aantalPowerUps)
{
    for (int i = 0; i < aantalPowerUps; ) {
        int x = 1+(qrand()%(game->getWidth()-2));
        int y = 1+(qrand()%(game->getHeight()-2));

        if (getThing(x, y)->getType() == Thing::thingType::CRATE) {
            placeThing(x, y, new PowerUp(getRandomPower()));
            i++;
        }
    }
}
