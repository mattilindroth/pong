#include "Paddle.h"

Paddle::Paddle(SDL_Surface *&surface, SDL_Rect *&rectangle) : GameItem(surface, rectangle, "paddle")
{

}

void Paddle::Move( int x, int y ) {
    this->pSpeedX = x;
    this->pSpeedY = y;
    pRectangle->x += x;
    pRectangle->y += y;

}

Paddle::~Paddle()
{
    //dtor
}
