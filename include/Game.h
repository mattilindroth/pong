#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL2\SDL_image.h>

#include "Scene.h"
#include "white.h"

class Game
{
    public:
        Game();
        void Run();
        ~Game();

    protected:

    private:

    //Private variables
    SDL_Window *pWindow;
    //SDL_Renderer *pRenderer;
    Scene *pScene;

};

#endif // GAME_H
