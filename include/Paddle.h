#ifndef PADDLE_H
#define PADDLE_H

#include "GameItem.h"

// How inheritance works in C++?
class Paddle : public GameItem /*(surface, rectangle, "Paddle") */
{
    public:
        Paddle(SDL_Surface *&surface, SDL_Rect *&rectangle);
        virtual ~Paddle();

    protected:

    private:
};

#endif // PADDLE_H
