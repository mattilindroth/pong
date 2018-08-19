#include "GameItem.h"

GameItem::GameItem(SDL_Surface *&surface, SDL_Rect *&rectangle, const char *name)
{
    printf("GameItem constructor called for object %s\n", name);
    pSurface = surface;
    pRectangle = rectangle;
    pName = name;
}

void GameItem::Move( int x, int y ) {
    pRectangle->x += x;
    pRectangle->y += y;
}

SDL_Surface *GameItem::GetSurface ( void ) {

    return pSurface;
}

SDL_Rect *GameItem::GetRectangle( void ) {
    return pRectangle;
}

GameItem::~GameItem()
{
    printf("GamneItem destructor called for %s\n", pName);
    //SDL_DestroyTexture( pTexture );
    SDL_FreeSurface( pSurface );
    delete pRectangle;
    pRectangle = NULL;
}
