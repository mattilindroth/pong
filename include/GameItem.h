#ifndef BALL_H
#define BALL_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL2\SDL_image.h>

class GameItem
{
    public:
        GameItem(SDL_Surface *&surface, SDL_Rect *&rectangle, const char *name);
        SDL_Surface *GetSurface( void );
        void Move( int x, int y );
        SDL_Rect *GetRectangle( void );
        ~GameItem();

    protected:

    private:
        SDL_Surface *pSurface;
        SDL_Rect *pRectangle;
        const char* pName;
};

#endif // BALL_H
