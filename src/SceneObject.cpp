#include "SceneObject.h"

SceneObject::SceneObject(SDL_Rect * rect, SDL_Texture *texture) {
    //fprintf(stderr, "In the SceneObject constructor.\n");
    pTexture = texture;
    pRect = rect;
}

SDL_Rect *SceneObject::GetRectangle( void ) {
    return pRect;
}

SDL_Texture *SceneObject::GetTexture( void ) {
    return pTexture;
}

SceneObject::~SceneObject()
{
    free(pRect);
    pRect = NULL;
    SDL_DestroyTexture(pTexture);

}
