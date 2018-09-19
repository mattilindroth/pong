#include "GameItem.h"

GameItem::GameItem(SDL_Surface *&surface, SDL_Rect *&rectangle, SDL_Renderer *renderer) : SceneObject(rectangle, SDL_CreateTextureFromSurface(renderer, surface))
{
    pSurface = surface;
    pRectangle = rectangle;
}

void GameItem::Move( int x, int y ) {
    pRectangle->x += x;
    pRectangle->y += y;
}

void GameItem::SetSpeed(int x, int y) {
    pSpeedX = x;
    pSpeedY = y;
}

int GameItem::GetSpeedX( void ) {
    return pSpeedX;
}

int GameItem::GetSpeedY( void ) {
    return pSpeedY;
}

SDL_Surface *GameItem::GetSurface ( void ) {

    return pSurface;
}

SDL_Rect *GameItem::GetRectangle( void ) {
    return pRectangle;
}

GameItem::~GameItem()
{
    SDL_FreeSurface( pSurface );
    delete pRectangle;
    pRectangle = NULL;
}
