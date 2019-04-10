#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>

class SceneObject
{
    public:
        SceneObject(SDL_Rect * rect, SDL_Texture *texture);
        SDL_Rect *GetRectangle( void );
        SDL_Texture *GetTexture( void );
        virtual ~SceneObject();

    protected:
        SDL_Texture *pTexture;
        SDL_Rect* pRect;
    private:

};

#endif // SCENEOBJECT_H
