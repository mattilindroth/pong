#include "SDLUtil.h"

SDLUtil::SDLUtil()
{
    //ctor
}

public static SDL_Texture SDLUtil::Surface2Texture(SDL_Surface *surface, SDL_Renderer *renderer) {
    SDL_Texture *texture = NULL;

    if (surface == NULL) {
        printf("Unable to load surface from file..\n");
        return NULL;
    }

    texture = SDL_CreateTextureFromSurface( renderer, surface );
    if (texture == NULL) {
        printf("Unable to create texture from surface..\n");
        return NULL;
    }

    return texture;
}

SDLUtil::~SDLUtil()
{
    //dtor
}
