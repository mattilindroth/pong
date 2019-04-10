#ifndef PADDLE_H
#define PADDLE_H

#include "GameItem.h"
#include <SDL.h>

class Paddle : public GameItem
{
    public:
        Paddle(SDL_Surface *&surface, SDL_Rect *&rectangle, SDL_Renderer *renderer);
        void Move( int x, int y );

        virtual ~Paddle();

    protected:

    private:
};

#endif // PADDLE_H
