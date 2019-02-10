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
        Scene(const int ScreenSizeX, const int ScreenSizeY); //SDL_Window *window);
        void AddItem(SceneObject *item);
        void RenderItems();
        SDL_Renderer *GetRenderer( void );
        void SetRenderer( SDL_Renderer *renderer );
        void Clear();
        void RemoveAt(int index);
        void RemoveItem(SceneObject *object);
        int GetCountOfItems( void );
        SceneObject *GetObjectAt(int index);
        int GetScreenSizeX( void );
        int GetScreenSizeY( void );
        ~Scene();

    protected:

    private:

    //Private members
    std::vector<SceneObject *> pItemsVector;
    SDL_Renderer *pRenderer;
    int pScreenSizeX;
    int pScreenSizeY;

};

#endif // SCENE_H
