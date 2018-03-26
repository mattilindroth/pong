#ifndef SCENE_H
#define SCENE_H

#include <stdio.h>
#include <stdlib.h>
#include "GameItem.h"
#include "SceneObject.h"
#include <vector>

class Scene
{
    public:
        Scene(SDL_Window *window);
        void AddItem(GameItem *item);
        void RenderItems();
        int GetCountOfItems( void );
        GameItem *GetItemAt(int index);
        ~Scene();

    protected:

    private:
    //Private functions

    SDL_Texture *SurfaceToTexture(SDL_Surface *surface, SDL_Renderer *renderer);

    //Private members
    std::vector<SceneObject *> pItemsVector;
    SDL_Renderer *pRenderer;
};

#endif // SCENE_H
