#ifndef BALL_H
#define BALL_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL2\SDL_image.h>
#include "SceneObject.h"

class GameItem : public SceneObject {
    public:
        GameItem(SDL_Surface *&surface, SDL_Rect *&rectangle, SDL_Renderer *renderer);
        SDL_Surface *GetSurface( void );
        void Move( int x, int y );
        void SetSpeed(int x, int y);
        int GetSpeedX( void );
        int GetSpeedY( void );
        SDL_Rect *GetRectangle( void );
        ~GameItem();

    protected:
        int pSpeedX, pSpeedY;
        SDL_Rect *pRectangle;
    private:
        SDL_Surface *pSurface;

        //const char* pName;

};

#endif // BALL_H
