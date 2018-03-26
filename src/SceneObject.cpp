#include "SceneObject.h"

SceneObject::SceneObject(GameItem *gameItem, SDL_Texture *texture)
{
    pTexture = texture;
    pItem = gameItem;
}

SDL_Rect *SceneObject::GetRectangle( void ) {
    return pItem->GetRectangle();
}

GameItem *SceneObject::GetGameItem() {
    return pItem;
}

SDL_Texture *SceneObject::GetTexture( void ) {
    return pTexture;
}

SceneObject::~SceneObject()
{
    printf("Destructor called for SceneObject\n");
    delete pItem;
}
