#include <stdlib.h>
#include <SDL.h>
#include <SDL2\SDL_image.h>
#include "Game.h"

using namespace std;

int main(int argc, char**argv)
{
    Game *game = NULL;

    game = new Game();
    game->Run();

    delete game;
    return 0;
}
