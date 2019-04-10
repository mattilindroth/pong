#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL2\SDL_image.h>

#include "Scene.h"
#include "Paddle.h"
#include "ValueRange.h"
#include "Menu.h"
#include "MenuItem.h"
#include "Text.h"
#include "InputManager.h"
#include <SDL2/SDL_ttf.h>

class Game
{
    public:
        Game();
        void Run();
        ~Game();

        static const int SCREEN_WIDTH = 800;
        static const int SCREEN_HEIGHT = 600;
    protected:
        void HandlePaddleMove(bool up, Paddle *paddle);
        bool AreColliding(GameItem *ball, Paddle *paddle);
    private:
    //Private variables
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
    Scene *pGameScene;
    Scene *pMenuScene;
    Text *pFpsText;
    InputManager *pInputManager;

};

#endif // GAME_H
