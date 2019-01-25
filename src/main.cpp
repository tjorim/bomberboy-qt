#include <QApplication>

#include "game.h"

Game *game;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;

    QApplication a(argc, argv);

    game = new Game();
    game->show();

    return a.exec();
}
