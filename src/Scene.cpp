#include "Scene.h"

Scene::Scene(SDL_Window *window)
{
    printf("Scene constructor called\n");
    pRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (pRenderer == NULL) {
        printf("Unable to create renderer...\n");
        return;
    }
    SDL_SetRenderDrawColor(pRenderer, 0x00, 0x00, 0x00, 0xFF);
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

SDL_Texture *Scene::SurfaceToTexture(SDL_Surface *surface, SDL_Renderer *renderer) {
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

void Scene::AddItem(GameItem *item) {
    SDL_Texture *texture;
    SceneObject *sceneObject;
    texture = SDL_CreateTextureFromSurface( pRenderer, item->GetSurface() );

    sceneObject = new SceneObject(item, texture);
    pItemsVector.push_back(sceneObject);
}

int Scene::GetCountOfItems( void ) {
    return pItemsVector.size();
}

GameItem *Scene::GetItemAt(int index) {
    SceneObject *sceneObject;
    GameItem *gameItem;
    sceneObject = pItemsVector.at(index);
    gameItem = sceneObject->GetGameItem();
    return gameItem;
}

Scene::~Scene()
{
    SceneObject *sObject;
    for (std::vector<SceneObject *>::iterator it = pItemsVector.begin(); it != pItemsVector.end(); ++it) {
        sObject = (*it);
        delete sObject;
    }
    SDL_DestroyRenderer( pRenderer );
    printf("Scene destructor called\n");
}
