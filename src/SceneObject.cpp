#include "SceneObject.h"

//SceneObject::SceneObject(GameItem *gameItem, SDL_Texture *texture)
//{
//    pTexture = texture;
//    pRect = gameItem->GetRectangle();
//}

SceneObject::SceneObject(SDL_Rect * rect, SDL_Texture *texture) {
    pTexture = texture;
//    pSurface = surface;
    pRect = rect;
}



SDL_Rect *SceneObject::GetRectangle( void ) {
    return pRect; //pItem->GetRectangle();
}

//GameItem *SceneObject::GetGameItem() {
//    return pItem;
//}

SDL_Texture *SceneObject::GetTexture( void ) {
    return pTexture;
}

SceneObject::~SceneObject()
{
    free(pRect);
    pRect = NULL;
//    SDL_FreeSurface(pSurface);
    SDL_DestroyTexture(pTexture);

}
