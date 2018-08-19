#include "Paddle.h"

Paddle::Paddle(SDL_Surface *&surface, SDL_Rect *&rectangle) : GameItem(surface, rectangle, "paddle")
{

}

Paddle::~Paddle()
{
    //dtor
}
