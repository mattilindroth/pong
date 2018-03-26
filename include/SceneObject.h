#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <SDL.h>
#include "GameItem.h"

class SceneObject
{
    public:
        SceneObject(GameItem *gameItem, SDL_Texture *texture);
        GameItem *GetGameItem( void );
        SDL_Rect *GetRectangle( void );
        SDL_Texture *GetTexture( void );
        virtual ~SceneObject();

    protected:

    private:
        SDL_Texture *pTexture;
        GameItem *pItem;
};

#endif // SCENEOBJECT_H
