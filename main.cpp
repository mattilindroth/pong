#include <stdlib.h>
#include "Game.h"
#include <map>
#include <vector>

using namespace std;

int main(int argc, char**argv)
{
    Game *game = NULL;

    game = new Game();

    game->Run();

    delete game;
    return 0;
}


