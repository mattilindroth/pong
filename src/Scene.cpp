#include "Scene.h"

Scene::Scene(const int ScreenSizeX, const int ScreenSizeY) //SDL_Window *window)
{
    pScreenSizeX = ScreenSizeX;
    pScreenSizeY = ScreenSizeY;
    printf("Scene constructor called\n");
//    pRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//    if (pRenderer == NULL) {
//        return;
//    }
//    SDL_SetRenderDrawColor(pRenderer, 0x00, 0x00, 0x00, 0xFF);
}

SDL_Renderer *Scene::GetRenderer( void ){
    return pRenderer;
}

void Scene::SetRenderer( SDL_Renderer *renderer ) {
    pRenderer = renderer;
}

void Scene::Clear() {
    pItemsVector.clear();
}

void Scene::RemoveAt(int index) {
    pItemsVector.erase(pItemsVector.begin() + index);
}

void Scene::RemoveItem(SceneObject *object) {
    SceneObject *item;

    for (std::vector<SceneObject*>::iterator it = pItemsVector.begin(); it != pItemsVector.end(); ++it) {
        item = (*it);
        if(item == object) {
            pItemsVector.erase(it);
            break;
        }
    }
}

void Scene::RenderItems() {
    SceneObject *item;

    SDL_RenderClear( pRenderer );

    for (std::vector<SceneObject*>::iterator it = pItemsVector.begin(); it != pItemsVector.end(); ++it) {
        item = (*it);

        SDL_RenderCopyEx( pRenderer, item->GetTexture(), NULL, item->GetRectangle(),0, NULL, SDL_FLIP_NONE );
    }
    SDL_RenderPresent( pRenderer );
}

int Scene::GetScreenSizeX( void ) {
    return this->pScreenSizeX;
}

int Scene::GetScreenSizeY( void ) {
    return this->pScreenSizeY;
}

void Scene::AddItem(SceneObject *item) {
    pItemsVector.push_back(item);
}

int Scene::GetCountOfItems( void ) {
    return pItemsVector.size();
}

SceneObject *Scene::GetObjectAt(int index) {
    SceneObject *sceneObject;
    sceneObject = pItemsVector.at(index);
    return sceneObject;
}

Scene::~Scene()
{
    SceneObject *sObject;
    for (std::vector<SceneObject *>::iterator it = pItemsVector.begin(); it != pItemsVector.end(); ++it) {
        sObject = (*it);
        delete sObject;
    }
    printf("Scene destructor called\n");
}
