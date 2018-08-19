#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL2\SDL_image.h>

#include "Scene.h"
#include "white.h"
#include "Paddle.h"

class Game
{
    public:
        Game();
        void Run();
        ~Game();

        const int SCREEN_WIDTH = 800;
        const int SCREEN_HEIGHT = 600;
    protected:
        void HandlePaddleMove(bool up, Paddle *paddle);
    private:
    //Private variables
    SDL_Window *pWindow;
    //SDL_Renderer *pRenderer;
    Scene *pScene;

};

#endif // GAME_H
