#ifndef SCENE_H
#define SCENE_H

#include <stdio.h>
#include <stdlib.h>
// #include "GameItem.h"
#include "SceneObject.h"
#include <vector>

class Scene
{
    public:
        Scene(); //SDL_Window *window);
        void AddItem(SceneObject *item);
        void RenderItems();
        SDL_Renderer *GetRenderer( void );
        void SetRenderer( SDL_Renderer *renderer );
        void Clear();
        void RemoveAt(int index);
        void RemoveItem(SceneObject *object);
        int GetCountOfItems( void );
        SceneObject *GetObjectAt(int index);
        ~Scene();

    protected:

    private:

    //Private members
    std::vector<SceneObject *> pItemsVector;
    SDL_Renderer *pRenderer;
};

#endif // SCENE_H
