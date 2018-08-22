#ifndef PADDLE_H
#define PADDLE_H

#include "GameItem.h"

// How inheritance works in C++?
class Paddle : public GameItem /*(surface, rectangle, "Paddle") */
{
    public:
        Paddle(SDL_Surface *&surface, SDL_Rect *&rectangle);
        void Move( int x, int y );
        virtual ~Paddle();

    protected:

    private:
};

#endif // PADDLE_H
